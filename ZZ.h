#ifndef ZZ_H
#define ZZ_H

// Standard Lib/Screen
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <SD.h>

// U of A library settings for Atmel SPI
#define SD_CS   5
#define TFT_CS  6
#define TFT_DC  7
#define TFT_RST 8


// Linked list
#include "linkedList.h"

#include "JoyStick.h"

// Class header
#include "Rectangle.h"
#include "Scene.h"

#endif