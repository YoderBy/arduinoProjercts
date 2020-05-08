//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int trigPin =5;
int echoPin =6;
long duration;
int distance;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  }
  
void loop()
{
long dist = getDistance();
lcd.clear();
lcd.setCursor(3,0);
lcd.print(dist);
delay(50);
lcd.setCursor(2,1);
lcd.print(dist*2);
delay(300);
lcd.setCursor(3,12);
delay(50);
lcd.print(dist*4);
Serial.println(dist);
}

long getDistance(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
return distance;
}

