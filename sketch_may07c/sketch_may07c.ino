int EnB = A1;
int EnA = A0;
int In1=12;
int In2=11;
int In3=10;
int In4=9;
int BuzzerPin = A2;
int LedPin = A3;
void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  analogWrite(BuzzerPin, 100);
  delay(1000);
  // put your main code here, to run repeatedly:

}
