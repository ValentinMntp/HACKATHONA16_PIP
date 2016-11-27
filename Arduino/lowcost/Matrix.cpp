#include <time.h>
#include "Matrix.h"

int dataIn = A3;
int load = A2;
int clockPin = A1;

void putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite(clockPin, LOW);   // tick
    if (data & mask){            // choose bit
      digitalWrite(dataIn, HIGH);// send 1
    }else{
      digitalWrite(dataIn, LOW); // send 0
    }
    digitalWrite(clockPin, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}

void line(byte reg, byte col) {
  digitalWrite(load, LOW);       // begin    
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data  
  digitalWrite(load, LOW);       // and load da stuff
  digitalWrite(load, HIGH);
}

Matrix::Matrix() {
  
}

void Matrix::init() {
  pinMode(dataIn, OUTPUT);
  pinMode(clockPin,  OUTPUT);
  pinMode(load,   OUTPUT);

  //initiation of the max 7219
  line(max7219_reg_scanLimit, 0x07);      
  line(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  line(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  line(max7219_reg_displayTest, 0x00); // no display test
}

unsigned long old = 0;

void Matrix::write(byte m[8]) {
  _m = m;
}

void Matrix::loop() { 
  int i, j;
  byte m2[8];
  for(i = 0; i < 8; i++) {
    m2[i] = 0;
    for(j = 0; j < 8; j++) {
      m2[i] |= (_m[j] & (1 << (7 - i))) >> (7 - i) << j;
    }
  }
  for(i = 0; i < 8; i++) {
    line(i+1, m2[i]);
  }
  line(max7219_reg_intensity, 255);
}

