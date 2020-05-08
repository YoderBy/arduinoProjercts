int EnB = A1;
int EnA = A0;
int In1=12;
int In2=11;
int In3=10;
int In4=9;
long ran;
int BuzzerPin =A2;
int LedPin = A3;
int Sec = 1000;
int Min = Sec * 60;
int hour = Sec * 60;

void setup() {
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(LedPin, 150);
 for (int i = 0; i < 3600*4.5; i ++){
  delay(Sec);
  Serial.println(i);
  if (i %2 == 0)
  {
    analogWrite(LedPin, 150);
  }
  else
  {
     analogWrite(LedPin, 0);
     }
 }
 analogWrite(LedPin, 0);
  while(true){
 escape_and_scream();
 }
}

void escape_and_scream(){
ran =  random(0, 4);
if(ran == 0){
  analogWrite(BuzzerPin, 255);
  analogWrite(LedPin, 0);
  driveF(200, 200);
  delay(2000);
  }
  
if(ran == 1){
  analogWrite(BuzzerPin, 150);
  analogWrite(LedPin, 155);
  driveB(200, 200);
  delay(2000);
  }
  
if(ran == 2){ 
  analogWrite(BuzzerPin, 250);
  analogWrite(LedPin, 255);
  driveL(200, 200);
  delay(500);
  }
  
if(ran == 3){
  analogWrite(BuzzerPin, 100);
  analogWrite(LedPin, 0);
  driveR(200, 200);
  delay(500);
  }
}

int driveF (int sp1, int sp2){
analogWrite(EnB, sp1);
analogWrite(EnA, sp1);
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
digitalWrite(In3, LOW);
digitalWrite(In4, HIGH);
}
int driveB (int sp1, int sp2){
analogWrite(EnB, sp1);
analogWrite(EnA, sp1);
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
}

int driveL (int sp1, int sp2){
analogWrite(EnB, sp1);
analogWrite(EnA, sp1);
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
digitalWrite(In3, LOW);
digitalWrite(In4, HIGH);
}

int driveR (int sp1, int sp2){
analogWrite(EnB, sp1);
analogWrite(EnA, sp1);
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
}
void escap(){
ran =  random(0, 4);
if(ran == 0){
  driveF(200, 200);
  delay(2000);
  }
  
if(ran == 1){
  driveB(200, 200);
  delay(2000);
  }
  
if(ran == 2){
  driveL(200, 200);
  delay(500);
  }
  
if(ran == 3){
  driveR(200, 200);
  delay(500);
  }

}
 
