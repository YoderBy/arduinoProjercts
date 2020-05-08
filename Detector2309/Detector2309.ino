int MotionPin = 8;
int beepPin = 11;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MotionPin, INPUT);
  pinMode(beepPin, OUTPUT);
}

void loop() {
Serial.println(DetectMotion());
if(DetectMotion() == true)
{
  Beep(1);
}
delay(500);
}
bool DetectMotion(){
  bool motionState = digitalRead(MotionPin);
  if(motionState==1)
  {
    return true;
  
  }
else{
     return false;
  }
}
void Beep(int beepNum)
{
 for(int i = 0;i < beepNum; i++)
 {
    analogWrite(beepPin, 180);
    delay(500); 
    digitalWrite(beepPin, LOW);
}
}

