#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ScreenO.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// 'default', 16x20px
const unsigned char def [] PROGMEM = {
  0x3f, 0xfc, 0x7f, 0xfe, 0xe0, 0x07, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xe0, 0x07, 0x7f, 0xfe, 0x3f, 0xfc
};
/////////////////////////////////////[ANGRY]
//////////////////[LEFT]
// 'Angry1_R', 16x20px
const unsigned char angry1_l [] PROGMEM = {
  0x00, 0x00, 0x7f, 0x00, 0xff, 0xfe, 0xc0, 0xff, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xff, 0xff, 0x7f, 0xfe, 0x00, 0x00
};
// 'Angry2_R', 16x20px
const unsigned char angry2_l [] PROGMEM = {
  0x00, 0x00, 0x7c, 0x00, 0xff, 0x00, 0xc7, 0xe0, 0xc0, 0xff, 0xc0, 0x1f, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 
  0xff, 0xff, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00
};
// 'Angry3_R', 16x20px
const unsigned char angry3_l [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xfc, 0x00, 0xcc, 0x00, 0xcf, 0x00, 0xc3, 0x00, 0xc3, 0xe0, 
  0xc0, 0xfe, 0xc0, 0x1f, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 0xff, 0xff, 
  0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
//////////////////[RIGHT]
// 'Angry1_L', 16x20px
const unsigned char angry1_r [] PROGMEM = {
  0x00, 0x00, 0x00, 0xfe, 0x7f, 0xff, 0xff, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xff, 0xff, 0x7f, 0xfe, 0x00, 0x00
};
// 'Angry2_L', 16x20px
const unsigned char angry2_r [] PROGMEM = {
  0x00, 0x00, 0x00, 0x3e, 0x00, 0xff, 0x07, 0xe3, 0xff, 0x03, 0xf8, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 
  0xff, 0xff, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00
};
// 'Angry3_L', 16x20px
const unsigned char angry3_r [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x33, 0x00, 0xf3, 0x00, 0xc3, 0x07, 0xc3, 
  0x7f, 0x03, 0xf8, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 0xff, 0xff, 
  0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/////////////////////////////////////[HAPPY]
// 'happy1', 16x20px
const unsigned char happy1 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x7f, 0xfe, 0xe0, 0x07, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xff, 0xff, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00
};
// 'happy2', 16x22px
const unsigned char happy2 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x0f, 0xf0, 0x3c, 0x3c, 
  0xf8, 0x1f, 0xe0, 0x07, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc7, 0xe3, 0xcf, 0xf3, 
  0xfc, 0x3f, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
/////////////////////////////////////[CLOSE]
// 'close1', 16x20px
const unsigned char close1 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00
};
// 'close2', 16x20px
const unsigned char close2 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'close3', 16x20px
const unsigned char close3 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
/////////////////////////////////////[heart]
// 'heart', 16x20px
const unsigned char heart [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x38, 0x7e, 0x7e, 0xe7, 0xe7, 0xc3, 0xc3, 0xc1, 0x83, 
  0xc0, 0x03, 0xe0, 0x07, 0x70, 0x0e, 0x30, 0x0c, 0x38, 0x1c, 0x1c, 0x38, 0x0e, 0x70, 0x07, 0xe0, 
  0x03, 0xc0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00
};
// 'heartf', 16x20px
const unsigned char heartf [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x38, 0x7e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0x3f, 0xfc, 0x3f, 0xfc, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 
  0x03, 0xc0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00
};

/////////////////////////////////////[heart]
// 'toheart1', 16x20px
const unsigned char toheart1 [] PROGMEM = {
  0x00, 0x00, 0x3e, 0x7c, 0xff, 0xff, 0xc1, 0x83, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 
  0x70, 0x0e, 0x3c, 0x3c, 0x1f, 0xf8, 0x07, 0xe0
};
// 'toheart2', 16x20px
const unsigned char toheart2 [] PROGMEM = {
  0x00, 0x00, 0x3e, 0x7c, 0x7f, 0xfe, 0xf3, 0xcf, 0xe1, 0x87, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
  0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 0x70, 0x0e, 0x38, 0x1c, 0x1c, 0x38, 0x0e, 0x70, 
  0x07, 0xe0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00
};
/////////////////////////////////////[PLAY]
// 'play2', 16x20px
const unsigned char play2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xfe, 0x00, 0xcf, 0x80, 0xc3, 0xe0, 0xc0, 0xf8, 0xc0, 0x3e, 
	0xc0, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x0f, 0xc0, 0x3e, 0xc0, 0xf8, 0xc3, 0xe0, 0xcf, 0x80, 
	0xfe, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'play1', 16x20px
const unsigned char play1 [] PROGMEM = {
	0x00, 0x00, 0x7c, 0x00, 0xff, 0xc0, 0xc3, 0xfe, 0xc0, 0x3f, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 
	0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x3f, 
	0xc3, 0xfe, 0xff, 0xe0, 0x7e, 0x00, 0x00, 0x00
};
/////////////////////////////////////[Recording]
// 'recording1', 10x20px
const unsigned char recording1 [] PROGMEM = {
	0x00, 0x00, 0x3f, 0x00, 0x7f, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 
	0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 
	0x61, 0x80, 0x7f, 0x80, 0x3f, 0x00, 0x00, 0x00
};
// 'recording2', 10x20px
const unsigned char recording2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x3f, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 
	0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 
	0x3f, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'recording3', 10x20px
const unsigned char recording3 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 
	0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'recording4', 10x20px
const unsigned char recording4 [] PROGMEM = {
	0x7f, 0x80, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 
	0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 0x8c, 0x40, 
	0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x7f, 0x80
};


int posX=0;
int posY=0;
int space=8;
int sizeX=16;
int sizeY=20;
int posTargetX=0;
int posTargetY=0;

unsigned long oldTimeMovement;
unsigned long oldTimeAnimation;
unsigned long oldTimeFaceDecide;
unsigned long oldTimeFaceBlink;
unsigned int timeLoopLimit=10000; //AnimationLoopLimit
int mood=1;
int imgNo=0;
bool isOnAnim=true;
bool canRefresh=false;
bool reverse=false;
bool movementLoop=false;

int eyeMoveChance=35;// %35 chance to move different direction
bool autoEyeMove=true;
int autoEyeMoveSeconds=1500;

int faceEmotion=0;
bool useEmotion=false;
bool autoFace=true;
int autoFaceCoolDown=1000;
int autoFaceBlink=1100;
int changeFaceChance=20; // %

int anim_delays[][7]={
  {0,0,0,0,0},
  {10,10,100,-1},
  {10,8000,-1},
  {10,10,5000,-1},
  {10,10,4500,-1},
  {10,3350-1},
  {50,50,50,50,-1},
  {10,3300,-1},
  {100,5000,-1},
  {100,100,100,100,100,-1}
};

String names = "Mira";



/*
 * Mood|ImageNo
 * 1|0:Default
 * 1|1:Blink(Close1)(anim)
 * 1|2:Blink(Close2)(Anim)
 * 1|3:Blink(Close3)(Anim)
 * 
 * 2|0:Default
 * 2|1:happy 1 (Anim)
 * 2|2:happy 2 (Real Happy)
 * 
 * 3|0:Default
 * 3|1:Angry Default(Anim)||(Litle Anger)
 * 3|2:Angry Default(Angry)
 * 3|3:Angry Default(Mad)
 * 
 * 4|0:Default
 * 4|1:Sad
 * 4|2:Sad
 * 4|3:Sad
 * 
 * 5|0:Default
 * 5|1:Suspicous litle
 * 5|2:Suspicous
 * 
 * 6|0:Default
 * 6|1:Heart (Anim)
 * 6|2:Heart (Anim)
 * 6|3:Heart 
 * 6|4:Heart Blink
 * 
 * 7: Name
 * 
 * 8|0:Default
 * 8|1:Play (Anim)
 * 8|2:Play
 *
 * 9|0:Default
 * 9|1:Recording
 * 9|2:Recording
 * 9|3:Recording
 * 9|4:Recording
 *
 */

void ScreenO::canUseEmotion(bool use){
	useEmotion=use;
}
void ScreenO::showHeart(int level){
  display.clearDisplay();
   if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, toheart1, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, toheart1, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, toheart2, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, toheart2, sizeX, sizeY, WHITE);
    }else if(level==3){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, heart, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, heart, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
  display.display();
}
void ScreenO::showHeartAnim(){
  for(int i=0;i<10;i++){
    display.clearDisplay();
    display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, heart, sizeX, sizeY, WHITE);
    display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, heart, sizeX, sizeY, WHITE);
    display.display();
    delay(100);
    display.clearDisplay();
    display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, heartf, sizeX, sizeY, WHITE);
    display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2,heartf, sizeX, sizeY, WHITE);
    display.display();
    delay(100);
  }
}
void ScreenO::showSus(int level){
  display.clearDisplay();
   if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry1_r, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry2_r, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
  display.display();
}
void ScreenO::showSad(int level){
   display.clearDisplay();
    if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry1_r, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry1_l, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry2_r, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry2_l, sizeX, sizeY, WHITE);
    }else if(level==3){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry3_r, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2,angry3_l, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
    display.display();
}
void ScreenO::showClose(int level){
  display.clearDisplay();
    if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, close1, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, close1, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, close2, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, close2, sizeX, sizeY, WHITE);
    }else if(level==3){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, close3, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, close3, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
    display.display();
}
void ScreenO::showHappy(int level){
  display.clearDisplay();
    if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, happy1, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, happy1, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2,happy2, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, happy2, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
    display.display();
}
void ScreenO::showAngry(int level/*0-3(include)*/){
   
    display.clearDisplay();
    if(level==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry1_l, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry1_r, sizeX, sizeY, WHITE);
    }else if(level==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry2_l, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry2_r, sizeX, sizeY, WHITE);
    }else if(level==3){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, angry3_l, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, angry3_r, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
    display.display();
}
void ScreenO::showName(int level){
	//Serial.println(String(level)+"/");
	if(level==2){
		//int selectedName=random(0,(sizeof(names) / sizeof (String)));
		display.setTextColor(WHITE);
		display.clearDisplay();
		display.setTextSize(2);
		display.setCursor(SCREEN_WIDTH/2+posX-sizeX/2-space/2,SCREEN_HEIGHT/2+posY-5);             // Start at top-left corner
		display.println(names);
		display.display();
	}
}
void ScreenO::showPlay(int level){
    if(level==1){
	display.clearDisplay();
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, play1, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, play1, sizeX, sizeY, WHITE);
    display.display();
    }else if(level==2){
	display.clearDisplay();
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2,play2, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, play2, sizeX, sizeY, WHITE);
    display.display();
    }else if(level==0) {
	display.clearDisplay();
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    display.display();
    }
}
void ScreenO::showRecording(int level){
    display.clearDisplay();
    if(level%5==1){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, recording1, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, recording1, sizeX, sizeY, WHITE);
    }else if(level%5==2){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, recording2, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, recording2, sizeX, sizeY, WHITE);
    }else if(level%5==3){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, recording3, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, recording3, sizeX, sizeY, WHITE);
    }else if(level%5==4){
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, recording4, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, recording4, sizeX, sizeY, WHITE);
    }else {
      display.drawBitmap(SCREEN_WIDTH/2+posX-space/2-sizeX, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
      display.drawBitmap(SCREEN_WIDTH/2+posX+space/2, SCREEN_HEIGHT/2+posY-sizeY/2, def, sizeX, sizeY, WHITE);
    }
    display.display();
}

void ScreenO::showRecordCount(int level){
	
}

/*
 * |----------------------------------|
 * |   Secreen Size: 128x64           |
 * |   Eye Can Move: -44 to +44 on X  |
 * |   Eye Can Move: -12 ro +12 on Y  |
 * |   (Since Space is 8              |
 * |----------------------------------|
 */
void ScreenO::refreshScreen(){
  canRefresh=true;
}
/*
int faceEmotion=0;
bool autoFace=true;
int autoFaceCoolDown=1000;
int autoFaceBlink=2500;
int changeFaceChance=45;
 */
void ScreenO::autoFaceEngine(){
  
  if(!autoFace)return;
  if(isOnAnim){
    //Serial.println("FACE: onAnim");
    oldTimeFaceDecide=millis(); 
    return;
  }
  //Serial.println("FACE: "+String(imgNo==0&&reverse&&(millis()-oldTimeFaceBlink>autoFaceBlink)));
  if(imgNo==0&&reverse && millis()-oldTimeFaceBlink>autoFaceBlink){
    oldTimeFaceBlink=millis();
    setFace(1,true);
  }else if(millis()-oldTimeFaceDecide>autoFaceCoolDown){
    oldTimeFaceDecide=millis();
    if(!useEmotion){
      if(random(0,100)<changeFaceChance)
        setFace(random(2,sizeof (anim_delays) / sizeof (anim_delays[0])),true);
    }else
    {
      int addition=random(0,5);
      for(int i=0;i<5;i++){
        switch((i+addition)%5){
          case 0:
            if((faceEmotion>=0)&&random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(2,true);return;} 
          case 1:
            if((faceEmotion<=0)&&random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(3,true);return;} 
          case 2:
            if((faceEmotion<-2)&&random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(4,true);return;} 
          case 3:
            if((abs(faceEmotion)<3)&&random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(5,true);return;} 
          case 4:
           if((faceEmotion>2)&&random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(6,true);return;}
		  //case 5:
           //if(random(0,100)<changeFaceChance+abs(faceEmotion)){setFace(7,true);return;}		   
        }
        //if((faceEmotion>=0)&&random(0,100)<changeFaceChance+abs(faceEmotion))setFace(2,true); // FACE HAPPY
        //else if((faceEmotion<=0)&&random(0,100)<changeFaceChance+abs(faceEmotion)) setFace(3,true); // FACE ANGRY
        //else if((abs(faceEmotion)<3)&&random(0,100)<changeFaceChance+abs(faceEmotion)) setFace(5,true);// FACE SUS
        //else if((faceEmotion<-2)&&random(0,100)<changeFaceChance+abs(faceEmotion)) setFace(4,true); // FACE SAD
        //else if((faceEmotion>2)&&random(0,100)<changeFaceChance+abs(faceEmotion)) setFace(6,true); // FACE Heart
      }
    }
  }
  
}
void ScreenO::autoMovementEngine(){
  if(!autoEyeMove)return;
  if(millis()-oldTimeMovement>autoEyeMoveSeconds){
      oldTimeMovement=millis();
      if(random(0,100)<eyeMoveChance){
         posTargetX=random(-44,44);
         posTargetY=random(-22,22);
      }else{
         posTargetX=0;
         posTargetY=0;
      }
       movementLoop=true;//Starts the engine
   }
}
void ScreenO::movementEngine(){
  if(!movementLoop)return;
  bool xFixxed=false;
  bool yFixxed=false;
  posX+=(posTargetX-posX)/2;
  posY+=(posTargetY-posY)/2;
  if(abs(posTargetX-posX)<=5){
    xFixxed=true;
    posX=posTargetX;
  }
  if(abs(posTargetY-posY)<=5){
    yFixxed=true;
    posY=posTargetY;
  }
  refreshScreen();
  movementLoop=!(yFixxed&&xFixxed);
}
void ScreenO::drawEngine(){
    if(!canRefresh)return;
    else if(mood==1)showClose(imgNo);
    else if(mood==2)showHappy(imgNo);
    else if(mood==3)showAngry(imgNo);
    else if(mood==4)showSad(imgNo);
    else if(mood==5)showSus(imgNo);
    else if(mood==6){
      if(imgNo!=4){
        showHeart(imgNo);
      }else{
        showHeartAnim();
      }
   }else if(mood==7)showName(imgNo);
   else if(mood==8)showPlay(imgNo);
   else if(mood==9)showPlay(imgNo);
   
   canRefresh=false;
}
void ScreenO::animationEngine(){
  if(isOnAnim){
    //int sz = sizeof(anim_delays[mood])/sizeof(int); 
    int delta = millis()-oldTimeAnimation;
    if(delta>anim_delays[mood][imgNo-1]){
      imgNo+=reverse?-1:1;
      refreshScreen();
      if(anim_delays[mood][imgNo-1]==-1){
        reverse=true;
        imgNo-=2;
      }else if(reverse&&imgNo==0){
          isOnAnim=false;
          //mood=1;
      }
      //Serial.println(String(mood)+"/"+String(imgNo)+"/"+String(reverse)+"/"+String(anim_delays[mood][imgNo-1])+"/"+String(isOnAnim)+"/"+String(delta));
    }
    
  }
}
void ScreenO::mainEngine(){
  autoFaceEngine();
  autoMovementEngine();
  movementEngine();
  animationEngine();
  drawEngine();
}
void ScreenO::setFace(int face,bool _autoFace){
  if(face==mood)return;
  if(isOnAnim){
	reverse=true;
	oldTimeAnimation=0;
	return;
  }
  isOnAnim=true;
  oldTimeAnimation=millis();
  mood=face;
  reverse=false; 
  autoFace=_autoFace;
}
void ScreenO::setFace(int face){
   setFace(face,true);
}
void ScreenO::setAutoFace(bool _autoFace){
  setFace(1,_autoFace);
}
void ScreenO::setPosition(int x,int y){
  movementLoop=true;
  posTargetX=x;
  posTargetY=y;
  //autoEyeMove=false; // disables auto mod after setted manualy
}
void ScreenO::setAutoEyeMove(bool autoMove){
  autoEyeMove=autoMove;
  if(autoMove)oldTimeMovement=millis();
}
void ScreenO::increaseEmotion(){
  faceEmotion=faceEmotion>5?5:faceEmotion+1;
}
void ScreenO::decreaseEmotion(){
  faceEmotion=faceEmotion<-5?-5:faceEmotion-1;
}
void ScreenO::setEmotion(int emotion){
  faceEmotion=(emotion<-5)?-5:(emotion>5?5:emotion);
}

void ScreenO::mainSetup(){
  //Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  oldTimeMovement=millis();
  oldTimeAnimation=millis();
}
/*
 * Mood|ImageNo
 * 1|0:Default
 * 1|1:Blink(Close1)(anim)
 * 1|2:Blink(Close2)(Anim)
 * 1|3:Blink(Close3)(Anim)
 * 
 * 2|0:Default
 * 2|1:happy 1 (Anim)
 * 2|2:happy 2 (Real Happy)
 * 
 * 3|0:Default
 * 3|1:Angry Default(Anim)||(Litle Anger)
 * 3|2:Angry Default(Angry)
 * 3|3:Angry Default(Mad)
 * 
 * 4|0:Default
 * 4|1:Sad
 * 4|2:Sad
 * 4|3:Sad
 * 
 * 5|0:Default
 * 5|1:Suspicous litle
 * 5|2:Suspicous
 * 
 * 6|0:Default
 * 6|1:Heart (Anim)
 * 6|2:Heart (Anim)
 * 6|3:Heart 
 * 6|4:Heart Blink
 * 
 */