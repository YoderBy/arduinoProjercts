#include <SPI.h>
#include <Ethernet.h>
#include <EEPROM.h>
// Ethernet MAC address to use.
byte mac[] = {0x90, 0xA2, 0xDA, 0xFD, 0x0D, 0xC1 };  // REPLACE WITH REAL ADDR
// IFTTT Maker parameters:
//     Key -- Obtained when setting up/connecting the Maker channel in IFTTT
//   Event -- Arbitrary name for the event; used in the IFTTT recipe.
char MakerIFTTT_Key[] = "bD2wto7-rZTHKSeJfUTYxW";
char MakerIFTTT_Event[] = "blink";

#define READ_THIS_PIN       3      // the button pin

// helper functions for constructing the POST data
// append a string or int to a buffer, return the resulting end of string

char *append_str(char *here, char *s) {
    while (*here++ = *s++)
  ;
    return here-1;
}

char *append_ul(char *here, unsigned long u) {
    char buf[20];       // we "just know" this is big enough

    return append_str(here, ultoa(u, buf, 10));
}


//
// This is called once per iteration to read the pin
// and send a POST to trigger the IFTTT/Maker event
//

void send_event() {

    EthernetClient client = EthernetClient();

    // connect to the Maker event server
    client.connect("maker.ifttt.com", 80);
    // finally we are ready to send the POST to the server!
    client.print("https://maker.ifttt.com/trigger/blink/with/key/bD2wto7-rZTHKSeJfUTYxWt");
    client.stop();
}

// called once at system reset/startup time
void setup() {
    // this sets up the network connection, including IP addr via DHCP
    Ethernet.begin(mac);
    Serial.begin(9600);
    // the input pin for this example
}
// main body; called over and over if it ever returns
void loop() {

    // DHCP lease check/renewal (library only sends request if expired)
    Ethernet.maintain();
         send_event();
         Serial.print("here");
}
