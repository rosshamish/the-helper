#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card
#define TFT_CS   6  // Chip select line for TFT display
#define TFT_DC   7  // Data/command line for TFT
#define TFT_RST  8  // Reset line for TFT (or connect to +5V)

// Standard pixel sizes for printed characters with a text size of 1 for the 
// Adafruit_GFX class
#define charW	6 // Width of a character
#define charH	8 // Height of a character

void createScoreboard(char **heading, int data[], int numRow, 
	int numCol, int x, int y, int textSize, int color, Adafruit_ST7735 tft);


void clearScoreboard(int bkColor, Adafruit_ST7735 tft);

#endif
