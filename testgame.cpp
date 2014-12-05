/*
Andrew Hoskins and Nathan Mueller

This is a short demo showing the most useful features of the library.

What is being demonstrated here?
1. Collision detection
2. Draw and track shapes through API interface
3. Create multiple scenes, add shapes and delete shapes from them
4. Draw entire scene, erase entire scene in one-liner
5. One-liner to change shape controlled by the joystick
6. A generic scrolling banner

*/

// Library header
#include "gameHelper.h"

void setup() {
	/*
	Display instance
	*/
	Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	tft.initR(INITR_REDTAB);
	tft.fillScreen(0);

	/*
	****************************************
	Scoreboard
	****************************************
	*/
	char *str[2] = {"player", "player"};
	int data[2] = {1, 2};
	
	createScoreboard(str, data, 2, 1, 0, 0, 1, 0xFFFFFF, tft);
	data[0] = 78;
	delay(5000);
	clearScoreboard(0x000000,tft);
	createScoreboard(str,data,2,1,0,0,1,0xFFFFFF,tft);
	delay(5000);
	clearScoreboard(0x000000,tft);
	createScoreboard(str, data, 1, 2, 0, 0, 1, 0xFFFFFF, tft);

	/*
	****************************************
	Scrolling banner demo
	This is essentially a stand-alone feature, but nonethelesss useful in many games
	****************************************
	*/
	scrollBanner("Arduino.", tft);

	/*
	****************************************
	Initiate our shapes, scene, and joystick
	****************************************
	*/

	/*
	Create some rectangles
	*/
	Rectangle goodGuy(5, 5, 7, 7, &tft, 0xFF00);
	Rectangle bigLine(0, 30, 100, 5, &tft, 0x0033);
	Rectangle obstacle(30, 15, 5, 15, &tft, 0x0033);
	Rectangle obstacleTwo(60, 0, 5, 15, &tft, 0x0033);
	Rectangle ObstacleThree(95, 35, 5, 25, &tft, 0x0033);
	Rectangle blockingTheWay(95, 60, 35, 5, &tft, 0x0033); 
	Rectangle theWayOut(90, 10, 10, 10, &tft, 0xFFFF);

	/*
	Create a first scene
	*/
	Scene firstScene;

	firstScene.addToScene(&goodGuy);
	firstScene.addToScene(&bigLine);
	firstScene.addToScene(&obstacle);
	firstScene.addToScene(&obstacleTwo);
	firstScene.addToScene(&ObstacleThree);
	firstScene.addToScene(&blockingTheWay);

	// Draw entire scene
	//
	// True parameter means to draw in original positions
	// This parameter only has an affect if the shapes have moved since created
	firstScene.drawScene(true);

	/*
	Create a second scene
	*/
	Scene secondScene;

	// Make another shape
	Rectangle finishLine(50, 12, 7, 7, &tft, 0xFEFE);

	// "bigLine" and "goodGuy" was already added to "firstScene", but we can add it here also
	secondScene.addToScene(&bigLine);
	secondScene.addToScene(&goodGuy);
	secondScene.addToScene(&finishLine);

	/*
	Declare a Joystick object
	*/
	JoyStick myJoy (&tft);

	// Add the shape and scene it will control
	// To understand why the scene has to be added, read the README!
	myJoy.addHandle(&firstScene, &goodGuy);

	/*
	****************************************
	Game loop
	****************************************
	*/
	bool finished = false;
	bool portalArrived = false;

	// The essence is to continually check for joystick motion and collision
	// The "adjustPosition()" method returns the collided object (if no collison, null)
	while (1) {
		// Check for motion and collision
		Rectangle* collidedShape = NULL;
		collidedShape = myJoy.adjustPosition();

		// If there is a collision, find which shape collided
		if (collidedShape != NULL) {
			if (collidedShape == &theWayOut) {
				// Erase the first scene and draw the second scene
				firstScene.hideScene(false);
				secondScene.drawScene(true);

				// Change the rectangle and scene controlled by the joystick
				myJoy.addHandle(&secondScene, &goodGuy);
			} 
			else if (collidedShape == &finishLine) {

				// Change the shape controlled by the joystick
				myJoy.addHandle(&secondScene, &finishLine);

				// Erase everything from the scene except this newly controlled rectangle
				secondScene.removeFromScene(&finishLine);
				secondScene.hideScene(false);
			}
			// Collision was not with a special object
			else {
				// Restart the level by drawing it on its original positions (true arguement)
				firstScene.hideScene(false);
				delay(250);
				firstScene.drawScene(true);
			}
		}

		// Use the rectangle shape API to check its position and respond
		if (goodGuy.getY() > bigLine.getY() && !portalArrived) {
			// Add to the scene on the fly and redraw the scene
			firstScene.addToScene(&theWayOut);
			firstScene.drawScene(false);

			portalArrived = true;
		}	
	}
}

void loop() {
}