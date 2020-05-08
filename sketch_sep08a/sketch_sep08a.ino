#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  Serial.begin(9600);
  while(!Serial);
  
  // put your setup code here, to run once:

}

void loop() {
  HttpClient client;
  client.getAsynchronously("https://maker.ifttt.com/trigger/start/with/key/cdCRuRDIvDtbZzS4wKThoM");
  while (client.available()) {
    char c = client.read();
    SerialUSB.print(c);
  }
  SerialUSB.flush();
  delay(1000000);

}
