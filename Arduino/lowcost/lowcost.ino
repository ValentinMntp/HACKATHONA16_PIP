#include <SimpleTimer.h>
#include <time.h>
#include "RFID.h"
#include "SevenSegs.h"
#include "Matrix.h"

unsigned char* getMatrice(const char s[4]);

RFID rfid;
//SevenSegs seven_segs;
Matrix matrix;

SimpleTimer timer, timer2; 

byte dataBlock[]    = {
    0x02, 0x02, 0x02, 0x02, //  2,  2,   2,  2,
    0x05, 0x06, 0x07, 0x08, //  5,  6,   7,  8,
    0x08, 0x09, 0xff, 0x0b, //  9, 10, 255, 12,
    0x0c, 0x0d, 0x0e, 0x0f  // 13, 14,  15, 16
};

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
void rfidLoop() {
  rfid.loop();
}

void setup() {
    //Serial.begin(9600); // Initialize serial communications with the PC
    //while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    rfid.init(1, 4);
    matrix.init();
    timer.setInterval(500, matrixLoop);
    timer.setInterval(100, rfidLoop);
    matrix.write(sander);
}

unsigned long t = 0;

void loop() {
    // RFID
    //rfid.loop();
    switch(rfid.state) {
        case RFID::WAITING:
            char s[4];
            s[0] = rfid.buffer[0] + '0';
            s[1] = rfid.buffer[1] + '0';
            s[2] = rfid.buffer[2] + '0';
            s[3] = rfid.buffer[3] + '0';
            matrix.write(getMatrice(s));
            rfid.state = RFID::ERROR;
            t = millis();
            //rfid.write(dataBlock);
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
    timer2.run();
}

unsigned char* getMatrice(const char[]);

unsigned char front_left[8] ={
0b00000000,
0b01111000,
0b01100000,
0b01010000,
0b01001000,
0b00000100,
0b00000010,
0b00000000
};

unsigned char front_right[8] ={
0b00000000,
0b00011110,
0b00000110,
0b00001010,
0b00010010,
0b00100000,
0b01000000,
0b00000000
};

unsigned char front[8] ={
0b00000000,
0b00010000,
0b00111000,
0b01111100,
0b00010000,
0b00010000,
0b00010000,
0b00000000
};

unsigned char right[8] ={
0b00000000,
0b00001000,
0b00001100,
0b01111110,
0b00001100,
0b00001000,
0b00000000,
0b00000000
};

unsigned char left[8] ={
0b00000000,
0b00010000,
0b00110000,
0b01111110,
0b00110000,
0b00010000,
0b00000000,
0b00000000
};

unsigned char* getMatrice(const char s[4])
{
    if(strcmp(s, "0201") == 0)
    return right;
    else if(strcmp(s, "0202") == 0)
    return right;
    else if(strcmp(s, "0203") == 0)
    return right;
    else if(strcmp(s, "0204") == 0)
    return right;
    else if(strcmp(s, "0205") == 0)
    return right;
    else if(strcmp(s, "0206") == 0)
    return right;
    else if(strcmp(s, "0207") == 0)
    return right;
    else if(strcmp(s, "0208") == 0)
    return right;
    else if(strcmp(s, "0209") == 0)
    return right;
    else if(strcmp(s, "0210") == 0)
    return right;
    else if(strcmp(s, "0211") == 0)
    return right;
    else if(strcmp(s, "0212") == 0)
    return front_right;
    else if(strcmp(s, "0213") == 0)
    return front_right;
    else if(strcmp(s, "0214") == 0)
    return front_right;
    else if(strcmp(s, "0215") == 0)
    return front_right;
    else if(strcmp(s, "0216") == 0)
    return front_right;
    else if(strcmp(s, "0217") == 0)
    return front_right;
    else if(strcmp(s, "0218") == 0)
    return front_right;
    else if(strcmp(s, "0219") == 0)
    return front;
    else if(strcmp(s, "0220") == 0)
    return front;
    else if(strcmp(s, "0221") == 0)
    return front;
    else if(strcmp(s, "0222") == 0)
    return front_left;
    else if(strcmp(s, "0223") == 0)
    return front_left;
    else if(strcmp(s, "0224") == 0)
    return front_left;
    else if(strcmp(s, "0225") == 0)
    return front_left;
    else if(strcmp(s, "0226") == 0)
    return left;
    else if(strcmp(s, "0227") == 0)
    return left;
    else if(strcmp(s, "0228") == 0)
    return left;
    else
        return front;



}

