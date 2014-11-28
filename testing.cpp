// Include the library
#include "ZZ.h"

// Display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//Sd2Card card;

void setup() {
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
	Rectangle one (10, 10, 5, 10);
	Rectangle two (1, 10, 5, 10);
	Rectangle three (100, 10, 5, 10);

	one.drawShape(tft);
	two.drawShape(tft);
	three.drawShape(tft);

	Scene myScene;
	myScene.addToScene(one);
	myScene.addToScene(two);
	myScene.addToScene(three);
	myScene.traverseScene();

	JoyStick myJoy;
	myJoy.addDelegate(&one);

	while (1) {
		myJoy.adjustPosition(tft);
	}

}

void loop() {

}







