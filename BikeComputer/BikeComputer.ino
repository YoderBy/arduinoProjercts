//arduino bike speedometer w serial.print()
//by Amanda Ghassaei 2012
//https://www.instructables.com/id/Arduino-Bike-Speedometer/

/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

*/

//calculations
//tire radius ~ 13.5 inches
//circumference = pi*2*r =~85 inches
//max speed of 35kph =~ 616inches/second
//max rps =~7.25dsDS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
#define ledLightRight 7
#define ledLightLeft 8
#define reed 13//pin connected to read switch
//storage variables
int reedVal;
long timer;// time between one full rotation (in ms)
float kph;
float radius = 3;// tire radius (in inches)
float circumference;

int maxReedCounter = 30;//min time (in ms) of one rotation (for debouncing)
int reedCounter;


void setup() {
  mySoftwareSerial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  reedCounter = maxReedCounter;
  circumference = 2 * 3.14 * radius;
  pinMode(reed, INPUT);
pinMode(ledLightRight, OUTPUT);
pinMode(ledLightLeft, OUTPUT);
  // TIMER SETUP- the timer interrupt allows precise timed measurements of the reed switch
  //for more info about configuration of arduino timers see http://ardu6ino.cc/playground/Code/Timer1
  cli();//stop interrupts

  //set timer1 interrupt at 1kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;
  // set timer count for 1khz increments
  OCR1A = 1999;// = (1/1000) / ((1/(16*10^6))*8) - 1
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |= (1 << CS11);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();//allow interrupts
  //END TIMER SETUP
 
  Serial.begin(115200);
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  
  //----Set volume----
  myDFPlayer.volume(20);  //Set volume value (0~30).
  myDFPlayer.volumeUp(); //Volume Up
  myDFPlayer.volumeDown(); //Volume Down
  
  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  Serial.println(myDFPlayer.readState()); //read mp3 state
  Serial.println(myDFPlayer.readVolume()); //read current volume
  Serial.println(myDFPlayer.readEQ()); //read EQ setting
  Serial.println(myDFPlayer.readFileCounts()); //read all file counts in SD card
  Serial.println(myDFPlayer.readCurrentFileNumber()); //read current play file number
  Serial.println(myDFPlayer.readFileCountsInFolder(3)); //read file counts in folder SD:/03
}


ISR(TIMER1_COMPA_vect) {//Interrupt at freq of 1kHz to measure reed switch
  reedVal = digitalRead(reed);//get val of A0
  if (reedVal == 0) { //if reed switch is closed
   
    if (reedCounter == 0) { //min time between pulses has passed
      kph = (float(circumference)) / float(timer) * 36; //calculate miles per hour
      //Serial.println(kph);
      //Serial.println("here!");
      timer = 0;//reset timer
      reedCounter = maxReedCounter;//reset reedCounter
    }
    else {
      if (reedCounter > 0) { //don't let reedCounter go negative
        reedCounter -= 1;//decrement reedCounter
      }
    }
  }
  else { //if reed switch is open
    if (reedCounter > 0) { //don't let reedCounter go negative
      reedCounter = reedCounter - 1;
      //decrement reedCounter
    }
  }
  if (timer > 500) {
    kph = 0;
  }
  else {
    timer += 1;//increment timer
  }
}

void displaykPH() {
  Serial.println(kph);
  lcd.print(kph);
  delay(100);
  lcd.clear();
}

void loop() {
  displaykPH();

 delay(100);
  lcd.print(kph);
  delay(100);
  lcd.clear();
  delay(100);
  if (kph > 3){
  static unsigned long timer = millis();
  myDFPlayer.play(4);  //Loop the first mp3
  delay(500);  }
}


