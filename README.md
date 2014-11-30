zzlib
=====

CMPUT 274: Sprite and Component Library for the Arduino.

Created by Andrew Hoskins and Nathan Mueller.

What is this?
======

It's a library which can speed up game developement on the [1.8-inch Adafruit TFT LCD display] (http://www.adafruit.com/products/358).  This library allows you to quickly create and use sprites.  It handles **motion, collision detection, and scenes**.  The library also includes two of the most common game accessories - **score clocks and banners**.

Requirements
=======

- [1.8-inch Adafruit TFT LCD display](http://www.adafruit.com/products/358)
- Joystick
- [Arduino.h] (http://arduino.cc/en/Guide/Environment)
- [Adafruit_GFX.h] (https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit_ST7735.h] (https://github.com/adafruit/Adafruit-ST7735-Library)
- [SPI.h] (http://arduino.cc/en/Reference/SPI)

Pins
=====

The following pins are defined in `ZZ.h`. This is for the TFT screen - wire up accordingly.

    #define TFT_CS  6
    #define TFT_DC  7
    #define TFT_RST 8

The following pins are defined in `JoyStick.h`. These are for the joystick.

    const int HORIZ = 0; (analog pin)
    const int VERT = 1; (analog pin)
    const int SEL = 9; (digital pin)

Usage
======

### Initiate The Hardware ###

Initiate the TFT display by doing the following:

`Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);`

Configure the TFT according to your version.  Something like this:

`tft.initR(INITR_REDTAB);`

### Shapes ###

Create some *shapes* (passing in references to your TFT):

`Rectangle::Rectangle(int startingX, int startingY, int shapeHeight, int shapeWidth, Adafruit_ST7735* tft)`

	Rectangle one (10, 10, 5, 10, &tft);
	Rectangle two (1, 10, 5, 10, &tft);
	Rectangle three (100, 10, 5, 10, &tft);

You can draw a shape whenever you'd like:

`one.drawShape();`

### Scenes ###

Now, lets add a *scene*.  A scene is a the container holding a bunch of shapes.  You can use multiple scenes if you'd like.

    Scene myScene;
    myScene.addToScene(&one);
    myScene.addToScene(&two);

We have created a scene, and added two of our shapes to the scene.  

### Motion ###

To add some motion to our scene lets initiate a *joystick*.  If we want some element of our scene to be controlled by the joystick, we can add our scene to the joystick.

    JoyStick myJoy (&tft);
    myJoy.addScene(&myScene);

The joystick has the power to "delegate" one shape at any given time.  This means that joystick will control/steer this shape.

    myJoy.addDelegate(&one);

To actively check this delegate for movement use the `adjustPosition()` method (likely in a loop):

    while (gameIsPlaying) {
        myJoy.adjustPosition();
    }
    
### Collisions ###

One of the main purposes of *scenes* is to define a scope for collisions.  Shapes within a scene are checked for collisions amoungst other shapes in the same scene.
However, if a shape is not in a scene (or in a different scene) it will **not** be checked for collisions with these shapes. 







 
	





  


