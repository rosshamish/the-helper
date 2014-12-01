// Include the library
#include "ZZ.h"

// Display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
	// Make a scene first
	// Create some shape and add to this scene
	// Create a joystick with a screen instance passed in
	// Store references to scenes in the joystick
	// When the joystick moves the delegate, check these scenes

	/*
	The the basic setup
	*/
	Serial.begin(9600);
	tft.initR(INITR_REDTAB);
	Serial.print("Init..");

  	tft.fillScreen(0);

	/*
	Test the rectangle class
	*/
	Rectangle one (10, 15, 5, 10, &tft);
	Rectangle two (30, 15, 5, 10, &tft);
	Rectangle three (100, 15, 5, 10, &tft);

	one.drawShape();
	two.drawShape();
	three.drawShape();

	Scene myScene;
	myScene.addToScene(&one);
	myScene.addToScene(&two);
	myScene.addToScene(&three);
	myScene.traverseScene();

	JoyStick myJoy (&tft);
	myJoy.addDelegate(&one);
	myJoy.addScene(&myScene);

	//Rectangle* collidedShape = NULL;
	while (1) {
		myJoy.adjustPosition();
		//if (collidedShape != NULL) {
		// 	Serial.println("Collision alerted.");
		// 	collidedShape = NULL;
		// }
	}

	// It only makes sense to have JoyStick delegate one object at a time
	// Check collision between delegate and other objects in its scene
	// It probably makes sense to automatically add the delegates scene to the joystick
	// So scenes are packets of shapes. We can add a shape to be delegated, and then
	// all of the shapes in the delegated shapes scene are check for collision.

	// Obviously, a shape should be allowed to be in multiple scenes
	// Add the scene...then add a shape from the scene.  So it's good how it is now.

}

void loop() {

}







