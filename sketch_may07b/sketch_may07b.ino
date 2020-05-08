int inputPin = 12;
void setup() {
 pinMode(inputPin, INPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(inputPin));
  // put your main code here, to run repeatedly:

}
