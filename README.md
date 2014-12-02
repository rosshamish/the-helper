Spark
=====

An Arduino graphics library for collision, movement, and scenes.
Made for the Adafruit TFT display.

Created by Andrew Hoskins and Nathan Mueller.

What is this?
======

A library to help speed up game development on the [1.8-inch Adafruit TFT LCD display] (http://www.adafruit.com/products/358). It handles **motion, collision detection, and scenes**.  The library also includes two of the most common game accessories - **score clocks and banners**.

Requirements
=======

- [1.8-inch Adafruit TFT LCD display](http://www.adafruit.com/products/358)
- [Sparkfun Joystick] (https://www.sparkfun.com/products/9032)
- [Arduino.h standard library] (http://arduino.cc/en/Guide/Environment)
- [Adafruit_GFX.h base graphics library] (https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit_ST7735.h display library] (https://github.com/adafruit/Adafruit-ST7735-Library)
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

Now, lets add a *scene*.  A scene is a the container holding a bunch of shapes.

    Scene myScene;
    myScene.addToScene(&one);
    myScene.addToScene(&two);

We have created a scene, and added two of our shapes to the scene.  You can use multiple scenes if you'd like. The same shape can even appear in more than one scene.  Scenes will be discussed in more detail later.    

### Motion ###

To add some motion to our scene lets initiate a *joystick*.  The joystick is in charge of controlling the motion of one shape at time.  But since shapes can be associated with multiple scenes, specify that scene to be controlled as well. 

    JoyStick myJoy (&tft);
    myJoy.addHandle(&myScene, &one);
    
The shape controlled by the joystick can be changed at any time by using this method.

To check the controlled shape for movement, use the `adjustPosition()` method (likely in a loop):

    while (gameIsPlaying) {
        myJoy.adjustPosition();
    }
    
### Collisions ###

One of the main purposes of *scenes* is to define a scope for collisions.  Shapes within a scene are checked for collisions amoungst other shapes in the same scene.  However, if a shape is not in a scene (or in a different scene) it will **not** be checked for collisions with these shapes.

The adjustPosition method on the joystick returns the collided shape if a collision occured in that motion.

    Rectangle* collidedShape = myJoy.adjustPosition();
    
### Other Features ###

Check out the [test game] (https://github.com/ahoskins/Spark/blob/master/testgame.cpp) for more comprehensive examples and available features.  









 
	





  


