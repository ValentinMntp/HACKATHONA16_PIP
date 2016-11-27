#include <SimpleTimer.h>
#include <time.h>
#include "RFID.h"
//#include "SevenSegs.h"
#include "Matrix.h"
#include "getMatrice.h"

RFID rfid;
//SevenSegs seven_segs;
Matrix matrix;

SimpleTimer timer; 

byte sander[] = {
   0b00111100,
   0b01000010,
   0b10000001,
   0b10100101,
   0b10000001,
   0b10011001,
   0b01000010,
   0b00111100
};

void matrixLoop() {
  matrix.loop();
}

void setup() {
    //Serial.begin(9600); // Initialize serial communications with the PC
    //while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    rfid.init(1, 4);
    matrix.init();
    timer.setInterval(200, matrixLoop);
    matrix.write(sander);
}

unsigned long t = 0;

void loop() {
    // RFID
    rfid.loop();
    switch(rfid.state) {
        case RFID::WAITING:
            char s[4];
            s[0] = rfid.buffer[0] + '0';
            s[1] = rfid.buffer[1] + '0';
            s[2] = rfid.buffer[2] + '0';
            s[3] = rfid.buffer[3] + '0';
            matrix.write(getMatrice(s));
            rfid.reset();
            t = millis();
        break;
        default:
          if(millis() - t > 3000) {
            t = millis();
            matrix.write(sander);
          }
    }

    // Seven segs
    //seven_segs.write("0204");
    //seven_segs.loop();

    // Matrix
    //matrix.write(sander);

    // timer
    timer.run();
}


