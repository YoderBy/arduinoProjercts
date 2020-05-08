  int inputPin = 3;
void setup() {

pinMode(inputPin,INPUT);// put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  if(digitalRead(inputPin)==HIGH)
  {
    Serial.println("1");
  }
  else{
  Serial.println("0");
  }
  // put your main code here, to run repeatedly:

}
