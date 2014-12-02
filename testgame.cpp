#include "ZZ.h"

void setup() {
	// Display
	Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

	/*
	The the basic setup
	*/
	Serial.begin(9600);
	tft.initR(INITR_REDTAB);
	Serial.print("Init..");
	tft.fillScreen(0);

	// If you hit the red things it goes back to the start of the first scene
	// There are a few "portals" taking you across the screen
	// i.e., the portals delete the old delegate, and spawn a new delegate somewhere else
	// When you reach the end portal a new scene appears

	/*
	First scene
	*/
	Scene firstScene;

	Rectangle goodGuy(5, 5, 7, 7, &tft, 0xFF00);
	Rectangle bigLine(0, 30, 100, 5, &tft, 0x0033); // line blocking the way
	Rectangle obstacle(30, 15, 5, 15, &tft, 0x0033); // obstacle
	Rectangle obstacleTwo(60, 0, 5, 15, &tft, 0x0033); // obstacle
	Rectangle ObstacleThree(95, 35, 5, 25, &tft, 0x0033); // obstacle
	Rectangle wtf(95, 60, 35, 5, &tft, 0x0033); //wtf is this 

	Rectangle theWayOut(90, 10, 10, 10, &tft, 0xFFFF); // portal

	firstScene.addToScene(&goodGuy);
	firstScene.addToScene(&bigLine);
	firstScene.addToScene(&obstacle);
	firstScene.addToScene(&obstacleTwo);
	firstScene.addToScene(&ObstacleThree);
	firstScene.addToScene(&wtf);

	// Draw in original position (doesn't actually matter at this point though)
	firstScene.drawScene(true);

	/*
	Second scene
	*/
	Scene secondScene;

	secondScene.addToScene(&bigLine);
	secondScene.addToScene(&goodGuy);

	Rectangle finishLine(50, 10, 7, 7, &tft, 0xFEFE);

	secondScene.addToScene(&finishLine);

	/*
	Joystick
	*/
	JoyStick myJoy (&tft);
	myJoy.addHandle(&firstScene, &goodGuy);

	/*
	Gameplay
	*/
	bool sceneOneMode = true;
	while (1) {
		// Check for motion and collision
		Rectangle* collidedShape = NULL;
		collidedShape = myJoy.adjustPosition();

		if (goodGuy.getY() > bigLine.getY()) {
			// draw me a portal!
			firstScene.addToScene(&theWayOut);
			firstScene.drawScene(false);
		}

		if (collidedShape != NULL) {
			if (collidedShape == &theWayOut) {
				// Draw the second scene
				firstScene.hideScene();
				secondScene.drawScene(true);
				myJoy.addHandle(&secondScene, &goodGuy);
				sceneOneMode = false;
			} 
			else {
				// Restore state of scene
				firstScene.hideScene();
				delay(250);
				firstScene.drawScene(true);
			}

			if (collidedShape == &finishLine) {
				goodGuy.setColor(0xFFFF);
				goodGuy.drawShape();
			}

		}			
		
	}

}

void loop() {

}