#include <SimpleTimer.h>
#include <time.h>
#include "RFID.h"
#include "KeyBoard.h"

RFID rfid;

void setup() {
    Serial.begin(9600); // Initialize serial communications with the PC
    while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    rfid.init(1, 4);
}

void loop() {
  rfid.loop();
  keypad_loop();
}

