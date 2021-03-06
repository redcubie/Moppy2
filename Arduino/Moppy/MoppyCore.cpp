#include <Arduino.h>
// Uncomment the appropriate instrument class for your setup
#include "src/MoppyInstruments/FloppyDrives.h"
FloppyDrives instrument = FloppyDrives();

// Uncomment the appropriate networking class for your setup
#include "src/MoppyNetworks/MoppySerial.h"
MoppySerial network = MoppySerial(instrument.systemMessage, instrument.deviceMessage);
// MoppyUDP network = TODO...


//The setup function is called once at startup of the sketch
void setup()
{
    instrument.setup();
    // Start receiving messages
    network.begin();
}

// The loop function is called in an endless loop
void loop()
{
    network.readMessages();
}
