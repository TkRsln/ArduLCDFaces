#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
class ScreenO {
	public:
		/*
			ASYNC functions are not realy asyncron but their behave depends on time.
			So you can change the face without waiting animations.
			LastEdit: 28.11.2021 01:09
		*/
		//**Important! Put this in a Loop function
		void mainEngine();
		//**Important! Put this in a Setup function, Display will begin
		void mainSetup();
		// ASYNC function / Public set face function
		void setFace(int face);
		// ASYNC function / eye position
		void setPosition(int x,int y);
		//For auto/random values
		void setAutoEyeMove(bool autoMove);
		void setAutoFace(bool _autoFace);
		// For Happy Faces, use this function. Mood value is between -5 and 5
		void increaseEmotion();
		void decreaseEmotion();
		void setEmotion(int emotion);
		void canUseEmotion(bool use);
	private:
		//Main set face 
		void setFace(int face,bool _autoFace);
		//Engines( Loops )
		void    animationEngine();
		void         drawEngine();
		void     movementEngine();
		void autoMovementEngine();
		void     autoFaceEngine();
		//Refresh the display
		void refreshScreen();
		//Face Functions
		void showAngry(int level);
		void showHappy(int level);
		void showClose(int level);
		void showSad(int level);
		void showSus(int level);
		void showHeartAnim();
		void showHeart(int level);
		void showName(int level);
		void showPlay(int level);
		void showRecordCount(int level);
		void showRecording(int level);
		
};
