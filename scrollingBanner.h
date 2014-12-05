#ifndef SCROLLINGBANNER_H
#define SCROLLINGBANNER_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card
#define TFT_CS   6  // Chip select line for TFT display
#define TFT_DC   7  // Data/command line for TFT
#define TFT_RST  8  // Reset line for TFT (or connect to +5V)


void scrollStr(char *str, int speed, int x, int y, int rot, int color, int backGrdCol, int size, Adafruit_ST7735 tft);

void scrollBanner(char* message, Adafruit_ST7735 tft);

#endif
