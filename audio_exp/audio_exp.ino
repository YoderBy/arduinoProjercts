#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
int inputPin = 3;
void setup() {
  pinMode(inputPin, INPUT);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(2);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  
  
  // put your setup code here, to run once:

}

void loop() {
  bool state = digitalRead(inputPin);
  while(state == HIGH){
    myDFPlayer.play(1);
    Serial.println("here");
    state = digitalRead(inputPin);
  }
    myDFPlayer.pause();
    Serial.println("here2");
  
  // put your main code here, to run repeatedly:

}
