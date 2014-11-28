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
	Rectangle myRect (10, 10, 5, 10);
	myRect.drawShape(tft);

	for (int i = 0; i < 50; i++) {
		myRect.moveX(tft);
	}

	/*
	Testing linked list
	*/

	list myList = {0, NULL, NULL};
	add_to_end(&myList, 1);
	add_to_end(&myList, 2);
	add_to_end(&myList, 3);
	add_to_end(&myList, 4);

	printList(&myList);

}

void loop() {

}







