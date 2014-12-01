// Include the library
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
	Create some shapes
	*/
	Rectangle delegateOne (10, 30, 5, 20, &tft, 0xFF00);
	Rectangle portalShape (30, 30, 5, 20, &tft, 0xFFFF);
	Rectangle changeColorShape (50, 30, 5, 20, &tft, 0xFFFF);
	Rectangle spawnNewShape (50, 90, 10, 10, &tft, 0xFFFF);
	Rectangle spawnedShape (70, 90, 10, 10, &tft, 0xFFFF);

	Rectangle delegateTwo (100, 100, 5, 20, &tft, 0xFF00);
	Rectangle portalShapeTwo (70, 100, 5, 20, &tft, 0xFFFF);

	// you can draw a shape individually
	delegateOne.drawShape();

	// and hide a shape individually
	delegateOne.hideShape();

	/*
	Create some scenes and add some shapes to them
	So shapes can live alone, or in a scene
	*/
	Scene firstScene;
	firstScene.addToScene(&delegateOne);
	firstScene.addToScene(&portalShape);
	firstScene.addToScene(&changeColorShape);
	firstScene.addToScene(&spawnNewShape);

	Scene secondScene;
	secondScene.addToScene(&delegateTwo);
	secondScene.addToScene(&portalShapeTwo);

	// draw an entire scene
	firstScene.drawScene(true);

	/*
	Create joystick and attach to a delegate within a scene
	*/
	JoyStick myJoy (&tft);
	myJoy.addHandle(&firstScene, &delegateOne);

	bool toggleState = true;

	/*
	Simulate game play with portalShape different scenes
	*/
	while (1) {
		Rectangle* collidedShape = NULL;
		// Scene delegateOne event logic
		while (toggleState) {
			Rectangle* collidedShape = NULL;
			collidedShape = myJoy.adjustPosition();

			// Collision with portalShape
			if (collidedShape == &portalShape) {
				// Hide the current scene
				firstScene.hideScene();

				// Draw the new scene in original state
				secondScene.drawScene(true);

				// Attach the new delegate and scene
				myJoy.addHandle(&secondScene, &delegateTwo);
				toggleState = false;
			}

			if (collidedShape == &changeColorShape) {
				// change the color of changeColorShape
				changeColorShape.setColor(0x0033);
				changeColorShape.drawShape();
			}

			if (collidedShape == &spawnNewShape) {
				// add the new shape to the scene
				firstScene.addToScene(&spawnedShape);
				firstScene.drawScene(false);
			}


		}

		// Scene portalShape event logic
		while (!toggleState) {
			Rectangle* collidedShape = NULL;
			collidedShape = myJoy.adjustPosition();

			if (collidedShape == &portalShapeTwo) {
				// jump back to the other scene
				secondScene.hideScene();

				firstScene.drawScene(true);

				myJoy.addHandle(&firstScene, &delegateOne);
				toggleState = true;
			}
		}	
	}

	/*
	Check for collisions within this scene
	Respond to the collision by changing the active scene
	*/
	// bool toggleState = true;

	// Rectangle* collidedShape = NULL;
	// while (1) {
	// 	collidedShape = myJoy.adjustPosition();
	// 	if (collidedShape != NULL) {
	// 		delegateOne.setColor(0xFFFF);
	// 		Serial.println("Collision alerted.");
	// 		collidedShape = NULL;

	// 		if (toggleState) {
	// 			// Hide the current scene
	// 			firstScene.hideScene();

	// 			// Draw the new scene in original state
	// 			secondScene.drawScene(true);

	// 			// Attach the new delegate and scene
	// 			myJoy.addHandle(&secondScene, &delegateTwo);
	// 			toggleState = false;
	// 		}
	// 		else {
	// 			secondScene.hideScene();
	// 			firstScene.drawScene(true);
	// 			myJoy.addHandle(&firstScene, &delegateOne);

	// 			toggleState = true;
	// 		}
	// 	}
	// }

}

void loop() {

}







