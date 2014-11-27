// Include the library
#include "ZZ.h"

// Display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

Sd2Card card;

void setup() {
	/*
	To the basic setup
	*/
	Serial.begin(9600);
	tft.initR(INITR_REDTAB);
	Serial.print("Init..");

	// It worked...
	Serial.println("Done, init, all is ok");

	// If failed...
	if (!SD.begin(SD_CS)) {
		Serial.print("failed to init SD");
		return;
	}
	
	if (!card.init(SPI_HALF_SPEED, SD_CS)) {
    	Serial.println("Raw SD Initialization has failed");
    	while (1) {};
  	}

  	tft.fillScreen(0);
  	/*
  	Test my Class's functionality
  	*/
	// ZZSprite mySprite;
	// mySprite.addImage(cur_image);
	// mySprite.drawSprite(tft);

	/*
	Test the rectangle class
	*/
	Rectangle myRect (10, 10, 5, 10);
	myRect.drawShape(tft);

	for (int i = 0; i < 50; i++) {
		myRect.moveX(tft);
	}

}

void loop() {

}







