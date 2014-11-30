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
	Rectangle one (10, 10, 5, 10, &tft);
	Rectangle two (1, 10, 5, 10, &tft);
	Rectangle three (100, 10, 5, 10, &tft);

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

	while (1) {
		myJoy.adjustPosition();
	}

}

void loop() {

}







