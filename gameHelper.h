#ifndef GAME_HELPER_H
#define GAME_HELPER_H

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

// Shape, scene, collision, joystick modules
#include "Screen.h"
#include "linkedList.h"
#include "JoyStick.h"
#include "Rectangle.h"
#include "Scene.h"

// Scrolling banner function
#include "scrollingBanner.h"

#include "scoreboard.h"

#endif