the-helper
=====

An Arduino game library for collisions, movement, and scenes.  The library also includes two commonly used game elements: scoreboards and scrolling banners.

Made for the Adafruit TFT display.

Created by Andrew Hoskins and Nathan Mueller.

What is this?
======

A library to help speed up game development on the [1.8-inch Adafruit TFT LCD display] (http://www.adafruit.com/products/358). It handles **motion, collision detection, and scenes**.  The library also includes two of the most common game accessories - **scoreboards and banners**.

It features a easy to use API, and is ideal for creating simple 2-D games like brickbreaker, connect-four, and maze games.

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

We have created a scene, and added two of our shapes to the scene.  You can use multiple scenes if you'd like and the same shape can appear in more than one scene.

We can draw the entire at once.

    myScene.drawScene(true);
    
There are two ways to draw scenes: in their original state, or most recent state.  The `true` argument means to draw all the shapes in the scene in their original positions (with respect to when they were constructed).  If `false` was supplied, this would draw the shapes based on their last recorded x-y coordinates (i.e., coordinates after moved by the joystick).

We can also hide an entire scene.  This will not remove the shapes from the scene or deconstruct the scene, but simply not display the scene.  Once again, the `true` or `false` argument is needed.   

    myScene.hideScene(true);

### Motion ###

To add some motion to our scene lets initiate a *joystick*.  The joystick is in charge of controlling the motion of one shape at time.  But since shapes can be associated with multiple scenes, specify the scene to be controlled also. 

    JoyStick myJoy (&tft);
    myJoy.addHandle(&myScene, &one);
    
The shape controlled by the joystick can be changed at any time by using this method.

Generally, changing the displayed scene and changing the shape controlled by the joystick go hand-in-hand.

To check the controlled shape for movement, use the `adjustPosition()` method:

    while (gameIsPlaying) {
        myJoy.adjustPosition();
    }
    
### Collisions ###

One of the main purposes of *scenes* is to define a scope for collisions.  Shapes within a scene are checked for collisions among other shapes in the same scene.  However, if a shape is not in that scene it will **not** be checked for collisions with these shapes.

The adjustPosition method on the joystick returns the collided shape if a collision occured in that motion.

    Rectangle* collidedShape = myJoy.adjustPosition();
   
It is worth noting that this library assumes collisions arise due to movement in the shape controlled by the joystick.  Through this method, collisions are **only checked with the shape controlled by the joystick vs all other shapes in its scene** (not every possible permutation of collisions). 

### Scrolling Banner ###

Use the scrolling banner by passing the following method a string, TFT display instance, and the rotation.

    scrollBanner("Arduino!", tft, 2);
    
The rotation is a number between 0 and 3 (inclusive).  This dictates which side of the screen the banner will scroll on.

### Score Board ###

Here is the definition of the function used to draw a scoreboard:

    void createScoreBoard(char** playerNames, int data[], int numRow, int numColumn, int x, int y, int textSize, int color,        Adafruit_ST7735 tft);
    
To clear the scoreboard, call the following function:

    void clearScoreboard(int backgroundColor, Adafruit_ST7735 tft);
    
The workflow to update the score is: erase the current scoreboard, then draw a new scoreboard with the updated score.
    
You are responsible for making sure no other shapes or text is drawn over the scoreboard! You are also responsible for making sure the number of rows and columns you specify for the scoreboard fits on the screen - there is no autoformat.

### Other Features ###

Check out the [test game] (https://github.com/ahoskins/the-helper/blob/master/testgame.cpp) for more comprehensive examples and available features.

<3 









 
	





  


