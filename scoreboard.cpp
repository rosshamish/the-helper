/**
	Usage:

	A scoreboard with the given number of rows and columns should be on the screen
	with a simple border. To update the data, call clearScoreboard(...) and
	then call this function again with new data. This prevents any data from
	overwriting another heading. The user is responsible for any 'events not
	entering the scoreboard because it is not written to be a 'shape' but should be
	if the libray is ever updated.

  	What this function does not do:
		1. Auto format if a row or column does not fit on the screen
		2. Rotation. Use tft.setRotation before calling if needed

	There are many additions of integers in the creation of the scoreboard
        These where chosen to for readablility of the scoreboard.
*/

#include "scoreboard.h"

/* used for the current state of the scoreboard */
typedef struct{
	int x;
	int y;
} coord;

coord topR, botL; // For clearing the scoreboard

// Border dimentions for the scoreboard.
int borderW = 0;
int borderL = 0;

/* Return the length of a given char pointer. */
int strLen(char *str){
	return sizeof(str)/sizeof(char);
}

/* Return how many characters are in a number. 
   i.e. an input of 100 returns the value 3. */
int charInInt(int x){
	int charInX = 0;

	if(x < 10)
			return 1;
	
	while(x > 0){
		x = x/10;
		charInX++;
	}
	return charInX;
}

/* Finds the max value in an integer array. Runtime O(n^2) */
int findMax(int data[], int len){
	int max = 0;

	for(int i = 0; i < len; i++){
	Serial.println(data[i]);
		if(max < data[i])
			max = data[i];}

	return max;
}

/* Creates a scoreboard based with a border.

   Pre: The ints numRow, numCol, x, y, textSize > 0
        int color should be in 16 bit hex format 0xRRBBGG
        tft is an object for the Adafruit_ST7735 display class
        char **heading and data[] must have the same number of indexes

   Post: A scoreboard with the given number of rows and columns should be on the screen
         with a simple border.

   Runtime O(n^2)
*/
void createScoreboard(char **heading, int data[], int numRow, 
	int numCol, int x, int y, int textSize, int color, Adafruit_ST7735 tft){
	
	topR.x = x;
	topR.y = y;

	int newX = x;
	int newY = y;

	int rowLen[numRow]; // use this to do a border around the scoreboard
	memset(rowLen, 0, sizeof(rowLen));

	int index = 0;

	for(int i = 0; i < numRow; i++){
		newY += i*textSize*charH + 2;
		newX = x+2; // reset for new row


		for(int j = 0; j < numCol; j++){
			char *str = heading[index];

			newX = rowLen[i]+2;
			tft.setCursor(newX, newY);

			// write a string and keep track of length
			tft.print(str);
			rowLen[i] += (strLen(str) + 5)*textSize*charW; // Char width is charW*textSize.
			newX = rowLen[i]+2;

			// Write the data to keep track of.
			tft.setCursor(newX, newY);
			tft.print(data[index]);

			// Update rowLen with the "length" of data[index].
			rowLen[i] += charInInt(data[index])*textSize*charW + 1;
			
			// Add spacing for another column if needed.
			if(j < numCol - 1){
				rowLen[i] += textSize*charW;
			}

			index++;			
		}
	}

	//create border
	borderW = y + numRow*charH*textSize + 5;
	borderL = findMax(rowLen, index);	//get max of array len
Serial.println(borderL);
	/* for scoreboard deletion */
	botL.x = borderL;
	botL.y = borderW;

	tft.drawLine(x,y, borderL, y, color);
	tft.drawLine(x,y,x, borderW, color);
	tft.drawLine(borderL, y, borderL, borderW, color);
	tft.drawLine(x, borderW, borderL, borderW, color);
}

/* Instead of having to check if updated data would overwrite another heading
   remove the score board with a recectangle and create it again.
   
   Ways to improve this: have a linked list that is a string and 
   allows for the addition of characters anywhere the list.
   This would act similar to how Java handles strings. Then the previous string 
   could be removed and then print the new one
*/
void clearScoreboard(int bkColor, Adafruit_ST7735 tft){
	//remove the scoreboard
	tft.fillRect(topR.x, topR.y, botL.x+1, botL.y+1, bkColor);
}
