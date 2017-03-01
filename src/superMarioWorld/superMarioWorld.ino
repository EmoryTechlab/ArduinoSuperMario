/*
Written for use in:
Emory University Libraries and Information Technology Services
Student Digital Life
TechLab
*/
//Written by Elishuwon Mitchell

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// If your matrix has the DOUBLE HEADER input, use:
//#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
//#define LAT 9
//#define OE  10
//#define A   A3
//#define B   A2
//#define C   A1
//#define D   A0


//API at: https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.cpp


RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
  uint8_t bright = 255;
  uint16_t red = matrix.Color333(bright, 0, 0);
  uint16_t green = matrix.Color333(0, 51, 0);
  uint16_t blue = matrix.Color333(0, 0, bright);
  uint16_t yellow = matrix.Color888(bright, bright, 0);
  uint16_t orange = matrix.Color888(255, 128, 0);
  uint16_t lightBrown = matrix.Color888(255, 204, 153);
  uint16_t darkBrown = matrix.Color888(153, 76, 0);
  uint16_t black = matrix.Color888(0, 0, 0);
  uint16_t white = matrix.Color333(255, 255, 255);

void setup() {

  matrix.begin();
}

// ------------------------------------------ Display Messages ------------------------------------------
void displayStartMessages(){
  
  int i = 0;
  int times = 5;
  while ( i < times){
    if(i % 2 == 0){
        printTechLab(red, black);
    }
    else{
        printTechLab(blue, black);
    }
    i++;
    delay(500);
  }
    matrix.fillRect(0,0,32,32, black);

  delay(500);
  i = 0;
  while ( i < times){
    if(i % 2 == 0){
        printStartMario(red, black);
    }
    else{
        printStartMario(blue, black);
    }
    i++;
    delay(500);
  }
  matrix.fillRect(0,0,32,32, black);
  delay(100);
  printStart(green, black);
  delay(1000);
  matrix.fillRect(0,0,32,32, black);
  
}

void displayEndMessages(){
  int i = 0;
  while ( i < 5){
    if(i % 2 == 0){
        printAskAboutMe(red, black);
    }
    else{
        printAskAboutMe(blue, black);
    }
    i++;
    delay(500);
  }
  
  matrix.fillRect(0,0,32,32, black);

}


void printHello(uint16_t textColor, uint16_t bgColor){
  matrix.drawChar(0, 0, 'H', textColor, bgColor, 1);
  matrix.drawChar(6, 0, 'E', textColor, bgColor, 1);
  matrix.drawChar(12, 0, 'L', textColor, bgColor, 1);
  matrix.drawChar(18, 0, 'L', textColor, bgColor, 1);
  matrix.drawChar(24, 0, 'O', textColor, bgColor, 1);  
}


void printStartMario(uint16_t textColor, uint16_t bgColor){
  
  matrix.drawChar(1, 0, 'L', textColor, bgColor, 1);
  matrix.drawChar(7, 0, 'e', textColor, bgColor, 1);
  matrix.drawChar(13, 0, 't', textColor, bgColor, 1);
  matrix.drawChar(19, 0, '\'', textColor, bgColor, 1);
  matrix.drawChar(25, 0, 's', textColor, bgColor, 1);

  matrix.drawChar(3, 8, 'P', textColor, bgColor, 1);
  matrix.drawChar(9, 8, 'l', textColor, bgColor, 1);
  matrix.drawChar(15, 8, 'a', textColor, bgColor, 1);
  matrix.drawChar(21, 8, 'y', textColor, bgColor, 1);

  matrix.drawChar(1, 18, 'M', textColor, bgColor, 1);
  matrix.drawChar(7, 18, 'A', textColor, bgColor, 1);
  matrix.drawChar(13, 18, 'R', textColor, bgColor, 1);
  matrix.drawChar(19, 18, 'I', textColor, bgColor, 1);
  matrix.drawChar(25, 18, 'O', textColor, bgColor, 1);
  
  
}

void printAskAboutMe(uint16_t textColor, uint16_t bgColor){
  
  matrix.drawChar(8, 0, 'A', textColor, bgColor, 1);
  matrix.drawChar(14, 0, 's', textColor, bgColor, 1);
  matrix.drawChar(20, 0, 'k', textColor, bgColor, 1);

  matrix.drawChar(1, 10, 'A', textColor, bgColor, 1);
  matrix.drawChar(7, 10, 'b', textColor, bgColor, 1);
  matrix.drawChar(13, 10, 'o', textColor, bgColor, 1);
  matrix.drawChar(19, 10, 'u', textColor, bgColor, 1);
  matrix.drawChar(25, 10, 't', textColor, bgColor, 1);

  matrix.drawChar(10, 20, 'M', textColor, bgColor, 1);
  matrix.drawChar(16, 20, 'E', textColor, bgColor, 1);
  
}

void printTechLab(uint16_t textColor, uint16_t bgColor){
  
  matrix.drawChar(1, 0, 'S', textColor, bgColor, 1);
  matrix.drawChar(7, 0, 'D', textColor, bgColor, 1);
  matrix.drawChar(13, 0, 'L', textColor, bgColor, 1);
  matrix.drawChar(19, 0, '\'', textColor, bgColor, 1);
  matrix.drawChar(25, 0, 'S', textColor, bgColor, 1);

  matrix.drawChar(3, 8, 'T', textColor, bgColor, 1);
  matrix.drawChar(9, 8, 'e', textColor, bgColor, 1);
  matrix.drawChar(15, 8, 'c', textColor, bgColor, 1);
  matrix.drawChar(21, 8, 'h', textColor, bgColor, 1);

  matrix.drawChar(6, 16, 'L', textColor, bgColor, 1);
  matrix.drawChar(12, 16, 'a', textColor, bgColor, 1);
  matrix.drawChar(18, 16, 'b', textColor, bgColor, 1);

  matrix.drawChar(3, 24, '-', textColor, bgColor, 1);
  matrix.drawChar(8, 24, '-', textColor, bgColor, 1);
  matrix.drawChar(13, 24, '-', textColor, bgColor, 1);
  matrix.drawChar(18, 24, '-', textColor, bgColor, 1);
  matrix.drawChar(23, 24, '-', textColor, bgColor, 1);
  matrix.drawChar(24, 24, '>', textColor, bgColor, 1);
  
  
}

void printStart(uint16_t textColor, uint16_t bgColor){
  matrix.drawChar(0, 0, 'S', textColor, bgColor, 1);
  matrix.drawChar(6, 0, 'T', textColor, bgColor, 1);
  matrix.drawChar(12, 0, 'A', textColor, bgColor, 1);
  matrix.drawChar(18, 0, 'R', textColor, bgColor, 1);
  matrix.drawChar(24, 0, 'T', textColor, bgColor, 1);  
}


// ------------------------------------------ Characters and Components ------------------------------------------


//-------Goomba 
void drawFullGoomba(int col, int row){

  //draw feet
  matrix.drawLine(col + 1, row - 0, col + 2, row - 0, green);
  matrix.drawLine(col + 4, row - 0, col + 5, row - 0, green);

  matrix.drawLine(col + 0, row - 1, col + 2, row - 1, green);
  matrix.drawLine(col + 4, row - 1, col + 6, row - 1, green);

  matrix.drawLine(col + 0, row - 2, col + 1, row - 2, green);
  matrix.drawLine(col + 5, row - 2, col + 6, row - 2, green);

  matrix.drawLine(col + 1, row - 3, col + 1, row - 3, green);
  matrix.drawLine(col + 5, row - 3, col + 5, row - 3, green);  


  //draw body
  matrix.drawLine(col + 3, row - 0, col + 3, row - 1, lightBrown);

  matrix.drawLine(col + 2, row - 2, col + 4, row - 2, lightBrown);
  matrix.drawLine(col + 2, row - 3, col + 4, row - 3, lightBrown);
  matrix.drawLine(col + 3, row - 4, col + 3, row - 4, lightBrown);

  //draw head
  matrix.drawLine(col + 1, row - 4, col + 5, row - 4, darkBrown);
  matrix.drawLine(col + 0, row - 5, col + 6, row - 5, darkBrown);

  matrix.drawLine(col + 0, row - 6, col + 1, row - 6, darkBrown);
  matrix.drawLine(col + 2, row - 6, col + 2, row - 6, lightBrown);
  matrix.drawLine(col + 3, row - 6, col + 3, row - 6, darkBrown);
  matrix.drawLine(col + 4, row - 6, col + 4, row - 6, lightBrown);
  matrix.drawLine(col + 5, row - 6, col + 6, row - 6, darkBrown);

  matrix.drawLine(col + 1, row - 7, col + 1, row - 7, darkBrown);
  matrix.drawLine(col + 2, row - 7, col + 2, row - 7, green);
  matrix.drawLine(col + 3, row - 7, col + 3, row - 7, darkBrown);
  matrix.drawLine(col + 4, row - 7, col + 4, row - 7, green);
  matrix.drawLine(col + 5, row - 7, col + 5, row - 7, darkBrown);

  matrix.drawLine(col + 1, row - 8, col + 1, row - 8, darkBrown);
  matrix.drawLine(col + 2, row - 8, col + 2, row - 8, lightBrown);
  matrix.drawLine(col + 3, row - 8, col + 3, row - 8, darkBrown);
  matrix.drawLine(col + 4, row - 8, col + 4, row - 8, lightBrown);
  matrix.drawLine(col + 5, row - 8, col + 5, row - 8, darkBrown);

  matrix.drawLine(col + 2, row - 9, col + 4, row - 9, darkBrown);
}


void clearFullGoomba(int col, int row){

  //draw feet
  matrix.drawLine(col + 1, row - 0, col + 2, row - 0, black);
  matrix.drawLine(col + 4, row - 0, col + 5, row - 0, black);

  matrix.drawLine(col + 0, row - 1, col + 2, row - 1, black);
  matrix.drawLine(col + 4, row - 1, col + 6, row - 1, black);

  matrix.drawLine(col + 0, row - 2, col + 1, row - 2, black);
  matrix.drawLine(col + 5, row - 2, col + 6, row - 2, black);

  matrix.drawLine(col + 1, row - 3, col + 1, row - 3, black);
  matrix.drawLine(col + 5, row - 3, col + 5, row - 3, black);  


  //draw body
  matrix.drawLine(col + 3, row - 0, col + 3, row - 1, black);

  matrix.drawLine(col + 2, row - 2, col + 4, row - 2, black);
  matrix.drawLine(col + 2, row - 3, col + 4, row - 3, black);
  matrix.drawLine(col + 3, row - 4, col + 3, row - 4, black);

  //draw head
  matrix.drawLine(col + 1, row - 4, col + 5, row - 4, black);
  matrix.drawLine(col + 0, row - 5, col + 6, row - 5, black);

  matrix.drawLine(col + 0, row - 6, col + 1, row - 6, black);
  matrix.drawLine(col + 2, row - 6, col + 2, row - 6, black);
  matrix.drawLine(col + 3, row - 6, col + 3, row - 6, black);
  matrix.drawLine(col + 4, row - 6, col + 4, row - 6, black);
  matrix.drawLine(col + 5, row - 6, col + 6, row - 6, black);

  matrix.drawLine(col + 1, row - 7, col + 1, row - 7, black);
  matrix.drawLine(col + 2, row - 7, col + 2, row - 7, black);
  matrix.drawLine(col + 3, row - 7, col + 3, row - 7, black);
  matrix.drawLine(col + 4, row - 7, col + 4, row - 7, black);
  matrix.drawLine(col + 5, row - 7, col + 5, row - 7, black);

  matrix.drawLine(col + 1, row - 8, col + 1, row - 8, black);
  matrix.drawLine(col + 2, row - 8, col + 2, row - 8, black);
  matrix.drawLine(col + 3, row - 8, col + 3, row - 8, black);
  matrix.drawLine(col + 4, row - 8, col + 4, row - 8, black);
  matrix.drawLine(col + 5, row - 8, col + 5, row - 8, black);

  matrix.drawLine(col + 2, row - 9, col + 4, row - 9, black);
}


//-------Regular Mario 

void drawMario(int col, int row){

  //draw feet: left right respectively
  matrix.drawLine(0 + col, row - 0, 3 + col, row - 0, darkBrown);
  matrix.drawLine(1 + col, row - 1, 3 + col, row - 1, darkBrown);

  matrix.drawLine(8 + col, row - 0, 11 + col, row - 0, darkBrown);
  matrix.drawLine(8 + col, row - 1, 10 + col, row - 1, darkBrown);


  //draw shirt
  matrix.drawLine(2 + col, row - 7, 9 + col,  row - 7, red);
  matrix.drawLine(1 + col, row - 6, 10 + col, row - 6, red);
  matrix.drawLine(0 + col, row - 5, 11 + col, row - 5, red);
  matrix.drawLine(2 + col, row - 4, 9 + col,  row - 4, red);

  //draw hands
  matrix.drawLine(0 + col, row - 4, 1 + col, row - 4, lightBrown);
  matrix.drawLine(10 + col, row - 4, 11 + col, row - 4, lightBrown);
  matrix.drawLine(0 + col, row - 3, 11 + col, row - 3, lightBrown);
  matrix.drawLine(0 + col, row - 2, 4 + col, row - 2, lightBrown);
  matrix.drawLine(7 + col, row - 2, 11 + col, row - 2, lightBrown);

  
  //draw jumper
  matrix.drawLine(2 + col, row - 2, 4 + col, row - 2, blue);
  matrix.drawLine(7 + col, row - 2, 9 + col, row - 2, blue);
  
  matrix.drawLine(3 + col, row - 3, 8 + col, row - 3, blue);

  matrix.drawLine(3 + col, row - 4, 8 + col, row - 4, blue);
  matrix.drawLine(3 + col, row - 5, 8 + col, row - 5, blue);
  matrix.drawLine(4 + col, row - 4, 4 + col, row - 4, yellow);
  matrix.drawLine(7 + col, row - 4, 7 + col, row - 4, yellow);
  
  matrix.drawLine(4 + col, row - 6, 7 + col, row - 6, blue);
  
  matrix.drawLine(4 + col, row - 7, 4 + col, row - 7, blue);
  matrix.drawLine(7 + col, row - 7, 7 + col, row - 7, blue);


  //draw head
  matrix.drawLine(3 + col, row - 8, 11 + col, row - 8, lightBrown);
  matrix.drawLine(1 + col, row - 9, 2 + col, row - 9, darkBrown);
  matrix.drawLine(3 + col, row - 9, 7 + col, row - 9, lightBrown);
  matrix.drawLine(8 + col, row - 9, 11 + col, row - 9, green);

  matrix.drawLine(1 + col, row - 10, 1 + col, row - 10, darkBrown);
  matrix.drawLine(2 + col, row - 10, 2 + col, row - 10, lightBrown);
  matrix.drawLine(3 + col, row - 10, 4 + col, row - 10, darkBrown);
  matrix.drawLine(5 + col, row - 10, 8 + col, row - 10, lightBrown);
  matrix.drawLine(9 + col, row - 10, 9 + col, row - 10, green);
  matrix.drawLine(10 + col, row - 10, 12 + col, row - 10, lightBrown);

  matrix.drawLine(1 + col, row - 11, 1 + col, row - 11, darkBrown);
  matrix.drawLine(2 + col, row - 11, 2 + col, row - 11, lightBrown);
  matrix.drawLine(3 + col, row - 11, 3 + col, row - 11, darkBrown);
  matrix.drawLine(4 + col, row - 11, 7 + col, row - 11, lightBrown);
  matrix.drawLine(8 + col, row - 11, 8 + col, row - 11, green);
  matrix.drawLine(9 + col, row - 11, 11 + col, row - 11, lightBrown);

  matrix.drawLine(2 + col, row - 12, 4 + col, row - 12, darkBrown);
  matrix.drawLine(5 + col, row - 12, 7 + col, row - 12, lightBrown);
  matrix.drawLine(8 + col, row - 12, 8 + col, row - 12, green);
  matrix.drawLine(9 + col, row - 12, 9 + col, row - 12, lightBrown);

  //draw hat
  matrix.drawLine(2 + col, row - 13, 11 + col, row - 13, red);
  matrix.drawLine(3 + col, row - 14, 8 + col, row - 14, red);

}

//-------Fire Mario 
void drawFireMario(int col, int row){

  //draw feet: left right respectively
  matrix.drawLine(0 + col, row - 0, 3 + col, row - 0, darkBrown);
  matrix.drawLine(1 + col, row - 1, 3 + col, row - 1, darkBrown);

  matrix.drawLine(8 + col, row - 0, 11 + col, row - 0, darkBrown);
  matrix.drawLine(8 + col, row - 1, 10 + col, row - 1, darkBrown);


  //draw shirt
  matrix.drawLine(2 + col, row - 7, 9 + col,  row - 7, red);
  matrix.drawLine(1 + col, row - 6, 10 + col, row - 6, red);
  matrix.drawLine(0 + col, row - 5, 11 + col, row - 5, red);
  matrix.drawLine(2 + col, row - 4, 9 + col,  row - 4, red);

  //draw hands
  matrix.drawLine(0 + col, row - 4, 1 + col, row - 4, lightBrown);
  matrix.drawLine(10 + col, row - 4, 11 + col, row - 4, lightBrown);
  matrix.drawLine(0 + col, row - 3, 11 + col, row - 3, lightBrown);
  matrix.drawLine(0 + col, row - 2, 4 + col, row - 2, lightBrown);
  matrix.drawLine(7 + col, row - 2, 11 + col, row - 2, lightBrown);

  
  //draw jumper
  matrix.drawLine(2 + col, row - 2, 4 + col, row - 2, white);
  matrix.drawLine(7 + col, row - 2, 9 + col, row - 2, white);
  
  matrix.drawLine(3 + col, row - 3, 8 + col, row - 3, white);

  matrix.drawLine(3 + col, row - 4, 8 + col, row - 4, white);
  matrix.drawLine(3 + col, row - 5, 8 + col, row - 5, white);
  matrix.drawLine(4 + col, row - 4, 4 + col, row - 4, yellow);
  matrix.drawLine(7 + col, row - 4, 7 + col, row - 4, yellow);
  
  matrix.drawLine(4 + col, row - 6, 7 + col, row - 6, white);
  
  matrix.drawLine(4 + col, row - 7, 4 + col, row - 7, white);
  matrix.drawLine(7 + col, row - 7, 7 + col, row - 7, white);


  //draw head
  matrix.drawLine(3 + col, row - 8, 11 + col, row - 8, lightBrown);
  matrix.drawLine(1 + col, row - 9, 2 + col, row - 9, darkBrown);
  matrix.drawLine(3 + col, row - 9, 7 + col, row - 9, lightBrown);
  matrix.drawLine(8 + col, row - 9, 11 + col, row - 9, green);

  matrix.drawLine(1 + col, row - 10, 1 + col, row - 10, darkBrown);
  matrix.drawLine(2 + col, row - 10, 2 + col, row - 10, lightBrown);
  matrix.drawLine(3 + col, row - 10, 4 + col, row - 10, darkBrown);
  matrix.drawLine(5 + col, row - 10, 8 + col, row - 10, lightBrown);
  matrix.drawLine(9 + col, row - 10, 9 + col, row - 10, green);
  matrix.drawLine(10 + col, row - 10, 12 + col, row - 10, lightBrown);

  matrix.drawLine(1 + col, row - 11, 1 + col, row - 11, darkBrown);
  matrix.drawLine(2 + col, row - 11, 2 + col, row - 11, lightBrown);
  matrix.drawLine(3 + col, row - 11, 3 + col, row - 11, darkBrown);
  matrix.drawLine(4 + col, row - 11, 7 + col, row - 11, lightBrown);
  matrix.drawLine(8 + col, row - 11, 8 + col, row - 11, green);
  matrix.drawLine(9 + col, row - 11, 11 + col, row - 11, lightBrown);

  matrix.drawLine(2 + col, row - 12, 4 + col, row - 12, darkBrown);
  matrix.drawLine(5 + col, row - 12, 7 + col, row - 12, lightBrown);
  matrix.drawLine(8 + col, row - 12, 8 + col, row - 12, green);
  matrix.drawLine(9 + col, row - 12, 9 + col, row - 12, lightBrown);

  //draw hat
  matrix.drawLine(2 + col, row - 13, 11 + col, row - 13, white);
  matrix.drawLine(3 + col, row - 14, 8 + col, row - 14, white);

}

void clearMario(int col, int row){

  //draw feet: left right respectively
  matrix.drawLine(0 + col, row - 0, 3 + col, row - 0, black);
  matrix.drawLine(1 + col, row - 1, 3 + col, row - 1, black);

  matrix.drawLine(8 + col, row - 0, 11 + col, row - 0, black);
  matrix.drawLine(8 + col, row - 1, 10 + col, row - 1, black);


  //draw shirt
  matrix.drawLine(2 + col, row - 7, 9 + col,  row - 7, black);
  matrix.drawLine(1 + col, row - 6, 10 + col, row - 6, black);
  matrix.drawLine(0 + col, row - 5, 11 + col, row - 5, black);
  matrix.drawLine(2 + col, row - 4, 9 + col,  row - 4, black);

  //draw hands
  matrix.drawLine(0 + col, row - 4, 1 + col, row - 4, black);
  matrix.drawLine(10 + col, row - 4, 11 + col, row - 4, black);
  matrix.drawLine(0 + col, row - 3, 11 + col, row - 3, black);
  matrix.drawLine(0 + col, row - 2, 4 + col, row - 2, black);
  matrix.drawLine(7 + col, row - 2, 11 + col, row - 2, black);

  
  //draw jumper
  matrix.drawLine(2 + col, row - 2, 4 + col, row - 2, black);
  matrix.drawLine(7 + col, row - 2, 9 + col, row - 2, black);
  
  matrix.drawLine(3 + col, row - 3, 8 + col, row - 3, black);

  matrix.drawLine(3 + col, row - 4, 8 + col, row - 4, black);
  matrix.drawLine(3 + col, row - 5, 8 + col, row - 5, black);
  matrix.drawLine(4 + col, row - 4, 4 + col, row - 4, black);
  matrix.drawLine(7 + col, row - 4, 7 + col, row - 4, black);
  
  matrix.drawLine(4 + col, row - 6, 7 + col, row - 6, black);
  
  matrix.drawLine(4 + col, row - 7, 4 + col, row - 7, black);
  matrix.drawLine(7 + col, row - 7, 7 + col, row - 7, black);


  //draw head
  matrix.drawLine(3 + col, row - 8, 11 + col, row - 8, black);
  matrix.drawLine(1 + col, row - 9, 2 + col, row - 9, black);
  matrix.drawLine(3 + col, row - 9, 7 + col, row - 9, black);
  matrix.drawLine(8 + col, row - 9, 11 + col, row - 9, black);

  matrix.drawLine(1 + col, row - 10, 1 + col, row - 10, black);
  matrix.drawLine(2 + col, row - 10, 2 + col, row - 10, black);
  matrix.drawLine(3 + col, row - 10, 4 + col, row - 10, black);
  matrix.drawLine(5 + col, row - 10, 8 + col, row - 10, black);
  matrix.drawLine(9 + col, row - 10, 9 + col, row - 10, black);
  matrix.drawLine(10 + col, row - 10, 12 + col, row - 10, black);

  matrix.drawLine(1 + col, row - 11, 1 + col, row - 11, black);
  matrix.drawLine(2 + col, row - 11, 2 + col, row - 11, black);
  matrix.drawLine(3 + col, row - 11, 3 + col, row - 11, black);
  matrix.drawLine(4 + col, row - 11, 7 + col, row - 11, black);
  matrix.drawLine(8 + col, row - 11, 8 + col, row - 11, black);
  matrix.drawLine(9 + col, row - 11, 11 + col, row - 11, black);

  matrix.drawLine(2 + col, row - 12, 4 + col, row - 12, black);
  matrix.drawLine(5 + col, row - 12, 7 + col, row - 12, black);
  matrix.drawLine(8 + col, row - 12, 8 + col, row - 12, black);
  matrix.drawLine(9 + col, row - 12, 9 + col, row - 12, black);

  //draw hat
  matrix.drawLine(2 + col, row - 13, 11 + col, row - 13, black);
  matrix.drawLine(3 + col, row - 14, 8 + col, row - 14, black);

}

//-------Fire Ball

void drawFireBall(int col, int row){
  int radius = 2;
  matrix.drawCircle(col+radius,row-radius,radius, red);
  matrix.fillRect(col+radius-1, row-radius-1, 3, 3, red);
}

void clearFireBall(int col, int row){
  int radius = 2;
  matrix.drawCircle(col+radius,row-radius,radius, black);
  matrix.fillRect(col+radius-1, row-radius-1, 3, 3, black);
}



//-------MysteryBox 

void drawMysteryBox(int col, int row){

  matrix.fillRect(col-1, row-1, 7, 9, darkBrown);
  matrix.drawChar(col, row, '?', blue, darkBrown, 1);
}

void drawHitMysteryBox(int col, int row){
  matrix.fillRect(col-1, row-1, 6, 9, darkBrown);
  
}

void clearMysteryBox(int col, int row){
  matrix.fillRect(col-1, row-1, 7, 9, black);
  
}

//-------Fire Flower

void drawFireFlower(int col, int row){

  //draw stem
  matrix.drawLine(col + 3, row - 0, col + 8, row - 0, green);
  matrix.drawLine(col + 5, row - 0, col + 5, row - 2, green);
  matrix.drawLine(col + 6, row - 0, col + 6, row - 2, green);

  //draw leaves
  matrix.drawLine(col + 2, row - 1, col + 3, row - 1, green);
  matrix.drawLine(col + 8, row - 1, col + 9, row - 1, green);

  //draw flower
  matrix.drawLine(col + 4, row - 3, col + 7, row - 3, red);
  
  matrix.drawLine(col + 3, row - 4, col + 4, row - 4, red);
  matrix.drawLine(col + 5, row - 4, col + 6, row - 4, orange);
  matrix.drawLine(col + 7, row - 4, col + 8, row - 4, red);

  matrix.drawLine(col + 3, row - 5, col + 4, row - 5, red);
  matrix.drawLine(col + 5, row - 5, col + 6, row - 5, orange);
  matrix.drawLine(col + 7, row - 5, col + 8, row - 5, red);

  matrix.drawLine(col + 4, row - 6, col + 7, row - 6, red);
  matrix.drawLine(col + 4, row - 6, col + 7, row - 6, red);

}

void clearFireFlower(int col, int row){

  //draw stem
  matrix.drawLine(col + 3, row - 0, col + 8, row - 0, black);
  matrix.drawLine(col + 5, row - 0, col + 5, row - 2, black);
  matrix.drawLine(col + 6, row - 0, col + 6, row - 2, black);

  //draw leaves
  matrix.drawLine(col + 2, row - 1, col + 3, row - 1, black);
  matrix.drawLine(col + 8, row - 1, col + 9, row - 1, black);

  //draw flower
  matrix.drawLine(col + 4, row - 3, col + 7, row - 3, black);
  
  matrix.drawLine(col + 3, row - 4, col + 4, row - 4, black);
  matrix.drawLine(col + 5, row - 4, col + 6, row - 4, black);
  matrix.drawLine(col + 7, row - 4, col + 8, row - 4, black);

  matrix.drawLine(col + 3, row - 5, col + 4, row - 5, black);
  matrix.drawLine(col + 5, row - 5, col + 6, row - 5, black);
  matrix.drawLine(col + 7, row - 5, col + 8, row - 5, black);

  matrix.drawLine(col + 4, row - 6, col + 7, row - 6, black);
  matrix.drawLine(col + 4, row - 6, col + 7, row - 6, black);

}


// ------------------------------------------ Regular Mario Scene ------------------------------------------
void regularMarioScene(int times){
   
  int col = 0;
  int row = 31;
  
  drawMario(0, 31);
  int i = 0;
  
  while (i < times){
    int x = 31;
    int y = 31; 
    bool started = false;
    int count = 0;
    while(x > -9){
        drawFullGoomba(x, y);
        if ( abs (col + 13 - x) < 10 and row -  20){
          clearMario(col, row);
          drawMario(col, row-=1);
        }

        clearFullGoomba(x, y);
        x--;
    }
  
    while (row != 31){
      clearMario(col, row);
      drawMario(col, row+=1);
    }
    i++;
  }
  matrix.fillRect(0,0,32,32, black);
}

// ------------------------------------------ Fire Mario Scene ------------------------------------------

void fireMarioScene(int times){
   
  drawMario(0, 31);
  //delay(1000);
  int i = 0;
  int box_col = 20;
  int box_row = 7;
  while (i < 15){
    drawMysteryBox(box_col, box_row);
    delay(50);
    clearMysteryBox(box_col, box_row);
    box_col--;
    i++;
  }
  i = 0;
  int mario_col = 0;
  int mario_row = 31;
  while( i < 2){
    clearMario(mario_col, mario_row);
    drawMario(mario_col, mario_row -=1);
    i++;
  }
  drawHitMysteryBox(box_col, box_row);

  
  int f_col = 1;
  int f_row = 6;
  drawFireFlower(f_col, f_row);

  clearMysteryBox(box_col, box_row);
  drawFireFlower(f_col, f_row);
  i = 0;
  while( i < 2){
    clearMario(mario_col, mario_row);
    drawMario(mario_col, mario_row +=1);
    i++;
  }

  
  while(f_row < 16){
    clearFireFlower(f_col, f_row);
    drawFireFlower(f_col, f_row+=1);
    delay(50);
  }

  clearFireFlower(f_col, f_row);
  clearMario(mario_col, mario_row);
  drawFireMario(mario_col, mario_row);

  mario_col = 0;
  mario_row = 31;
  i = 0;
  drawMario(mario_col, mario_col);

  while (i < times){
    int ball_col = 13;
    int ball_row = 28;
    int goom_col = 31;
    int goom_row = 31; 
    while(goom_col != ball_col){
        drawFullGoomba(goom_col, goom_row);
        drawFireBall(ball_col, ball_row);
        delay(25);
        clearFullGoomba(goom_col, goom_row);
        clearFireBall(ball_col, ball_row);
        ball_col++;
        goom_col--;
    }
    drawFullGoomba(goom_col, goom_row);
    delay(50);
    clearFullGoomba(goom_col, goom_row);
    drawFullGoomba(goom_col, goom_row-=1);
    delay(50);
    clearFullGoomba(goom_col, goom_row);
    drawFullGoomba(goom_col, goom_row+=1);
    delay(50);
    clearFullGoomba(goom_col, goom_row);

    delay(50);
    i++;
  }
   
  matrix.fillRect(0,0,32,32, black);

}

// ------------------------------------------ Goal Pole Scene ------------------------------------------

void drawGoalPole(int col, int row){
    
  //base
  matrix.fillRect(col, row, 3, 3, darkBrown);

  //pole
  matrix.drawLine(col+1, row-1, col+1, 3, green);

  //flag
  matrix.drawLine(col, 3, col, 7, red);
  matrix.drawLine(col-1, 4, col-1, 6, red);
  matrix.drawPixel(col-2, 5, red);
  
}

void clearGoalPole(int col, int row){

  //base
  matrix.fillRect(col, row, 3, 3, black);

  //pole
  matrix.drawLine(col+1, row-1, col+1, 3, black);

  //flag
  matrix.drawLine(col, 3, col, 7, black);
  matrix.drawLine(col-1, 4, col-1, 6, black);
  matrix.drawPixel(col-2, 5, black);
  
}

void goalPoleScene(){
  int m_col = 0;
  int m_row = 31;

  int p_col = 31;
  int p_row = 29;

  drawMario(m_col, m_row);

  while(m_col+12 < p_col - 3){
    drawGoalPole(p_col, p_row);
    delay(50);
    clearGoalPole(p_col, p_row);
    p_col -= 1;
  }

  drawGoalPole(p_col, p_row);
  clearMario(m_col, m_row);
  drawMario(m_col+=2, m_row-=8);
  clearMario(m_col, m_row);
  drawMario(m_col+=2, m_row+=2);
  delay(1000);
  matrix.fillRect(0,0,32,32, black);

}

// ------------------------------------------ Loop ------------------------------------------

void loop() { 
  int times = 5;
  displayStartMessages();
  regularMarioScene(times);
  fireMarioScene(times);
  regularMarioScene(times);
  goalPoleScene();
  displayEndMessages();
  
}
