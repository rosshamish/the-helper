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

	/*
	What is being demonstrated here?
	1. Collision detection
	2. Multiple scenes that can easily be drawn in and out
	3. 
	*/


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

	// Draw in original position ("true" doesn't actually matter at this point though)
	firstScene.drawScene(true);

	/*
	Second scene
	*/
	Scene secondScene;

	secondScene.addToScene(&bigLine);
	secondScene.addToScene(&goodGuy);

	Rectangle finishLine(50, 12, 7, 7, &tft, 0xFEFE);

	secondScene.addToScene(&finishLine);

	/*
	Joystick
	*/
	JoyStick myJoy (&tft);
	myJoy.addHandle(&firstScene, &goodGuy);

	/*
	Gameplay
	*/
	bool finished = false;
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
			} 
			else if (collidedShape == &finishLine) {
				// Magically make the finish like the new delegate!
				myJoy.addHandle(&secondScene, &finishLine);
				secondScene.removeFromScene(&finishLine);
				secondScene.hideScene();
				tft.setCursor(5, 70);
				tft.setTextSize(2);
				tft.print("Spark.");
			}
			else {
				// Restore state of scene
				firstScene.hideScene();
				delay(250);
				firstScene.drawScene(true);
			}
		}
		
	}
}

void loop() {

}