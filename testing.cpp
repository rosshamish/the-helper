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
	Create some shapes
	*/
	Rectangle one (10, 30, 5, 20, &tft, 0xFF00);
	Rectangle two (30, 30, 5, 20, &tft, 0xFFFF);
	Rectangle three (50, 30, 5, 20, &tft, 0xFFFF);
	Rectangle four (100, 100, 5, 20, &tft, 0xFFFF);
	Rectangle five (70, 100, 5, 20, &tft, 0xFFFF);

	// you can draw a shape individually
	one.drawShape();

	// and hide a shape individually
	one.hideShape();


	/*
	Create some scenes and add some shapes to them
	So shapes can live alone, or in a scene
	*/
	Scene myScene;
	myScene.addToScene(&one);
	myScene.addToScene(&two);
	myScene.addToScene(&three);

	Scene secondScene;
	secondScene.addToScene(&four);
	secondScene.addToScene(&five);

	// draw an entire scene
	myScene.drawScene(true);


	/*
	Attach joystick to a delegate within a scene
	*/
	JoyStick myJoy (&tft);
	myJoy.addHandle(&myScene, &one);

	/*
	Check for collisions within this scene
	Respond to the collision by changing the active scene
	*/
	bool toggleState = true;

	Rectangle* collidedShape = NULL;
	while (1) {
		collidedShape = myJoy.adjustPosition();
		if (collidedShape != NULL) {
			one.setColor(0xFFFF);
			Serial.println("Collision alerted.");
			collidedShape = NULL;

			if (toggleState) {
				// Hide the current scene
				myScene.hideScene();

				// Draw the new scene in original state
				secondScene.drawScene(true);

				// Attach the new delegate and scene
				myJoy.addHandle(&secondScene, &four);
				toggleState = false;
			}
			else {
				secondScene.hideScene();
				myScene.drawScene(true);
				myJoy.addHandle(&myScene, &one);

				toggleState = true;
			}
		}
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







