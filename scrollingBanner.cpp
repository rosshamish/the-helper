#include "scrollingBanner.h"

/*
	funcuntion def and pre/post cond
	
	TODO: write a custom textWrap so text can wrap to the same line
*/
void scrollStr(char *str, int speed, int x, int y, int rot, int color, int backGrdCol, int size, Adafruit_ST7735 tft){
	tft.setTextWrap(false);
	tft.setRotation(rot);
	tft.setTextSize(size);
	/* write previous text state to backGrdCol */
	tft.setCursor(x-speed,y);
	tft.setTextColor(backGrdCol);
	tft.print(str);

	/* write the new state */
	tft.setCursor(x,y);
	tft.setTextColor(color);	
	tft.print(str);
}

void scrollBanner(char* message, Adafruit_ST7735 tft) {
	for(int i = 0; i< 170; i++){
		scrollStr(message, 2, i, 0, 0, ST7735_WHITE, ST7735_BLACK, 2, tft);
	}
	
	for(int i = 0; i< 170; i++){
		scrollStr(message, 2, i, 0, 1, ST7735_RED, ST7735_BLACK, 2, tft);
	}

	for(int i = 0; i< 170; i++){
		scrollStr(message, 2, i, 0, 2, ST7735_BLUE, ST7735_BLACK, 2, tft);
	}

	for(int i = 0; i< 170; i++){
		scrollStr(message, 2, i, 0, 3, ST7735_GREEN, ST7735_BLACK, 2, tft);
	}
	tft.setRotation(0);
}
