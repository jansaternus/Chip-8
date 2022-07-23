
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
#include <TouchScreen.h>

const int TS_LEFT=907,TS_RT=136,TS_TOP=942,TS_BOT=139;

TouchScreen ts = TouchScreen(6, A1, A2, 7, 300);
TSPoint tp;

#define MINPRESSURE 200
#define MAXPRESSURE 1000

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define RAM_POS_X 456
#define RAM_POS_Y 24
#define RAM_WIDTH 16
#define RAM_HEIGHT 256

void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t id = tft.readID();
  tft.begin(id);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  
  tft.fillRect(100, 100, 1, 1, 0x5F36);
  ramByteWrite(0x200, 0x4356);
  Serial.println(ramByteRead(0x200), HEX);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

unsigned long ramByteRead(int addr){
 int x = RAM_POS_X + addr%RAM_WIDTH;
 int y = RAM_POS_Y + round(addr/RAM_WIDTH);
 short val = tft.readPixel(x,y);
 return val;
}

void ramByteWrite(int addr, short value){
 int x = RAM_POS_X + addr%RAM_WIDTH;
 int y = RAM_POS_Y + round(addr/RAM_WIDTH);
 tft.fillRect(x,y,1,1,value);
}