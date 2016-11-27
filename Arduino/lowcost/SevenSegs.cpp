#include "SevenSegs.h"

SevenSegs::SevenSegs() {
  
}

void SevenSegs::init() {
  DigitOn = LOW;
  DigitOff = HIGH;
  SegOn = HIGH;
  SegOff = LOW;

  DigitPins[0] = A4;
  DigitPins[1] = A5;
  DigitPins[2] = 2;
  DigitPins[3] = 3;
  SegmentPins[0] = 4;
  SegmentPins[1] = 5;
  SegmentPins[2] = 6;
  SegmentPins[3] = 7;
  SegmentPins[4] = 8;
  SegmentPins[5] = A7;
  SegmentPins[6] = A0;
  SegmentPins[7] = A6;

  //Set Pin Modes as outputs
  for (byte digit = 0; digit < 4; digit++) {
    pinMode(DigitPins[digit], OUTPUT);
  }
  for (byte seg = 0; seg < 8; seg++) {
    pinMode(SegmentPins[seg], OUTPUT);
  }

  //Turn Everything Off
  //Set all digit pins off.  Low for common anode, high for common cathode
  for (byte digit = 0; digit < 4; digit++) {
    digitalWrite(DigitPins[digit], LOW);
  }
  //Set all segment pins off.  High for common anode, low for common cathode
  for (byte seg = 0; seg < 8; seg++) {
    digitalWrite(SegmentPins[seg], LOW);
  }
}

void SevenSegs::loop() {
  for (byte seg = 0; seg < 8; seg++) {
    //Turn the relevant segment on
    digitalWrite(SegmentPins[seg], SegOn);

    //For each digit, turn relevant digits on
    for (byte digit = 0; digit < 4; digit++) {
      if ((lights[digit] & bit(7-seg)) == bit(7-seg)) {
        digitalWrite(DigitPins[digit], DigitOn);
      }
      //delay(200); //Uncomment this to see it in slow motion
    }
    //Turn all digits off
    for (byte digit = 0; digit < 4; digit++) {
      digitalWrite(DigitPins[digit], DigitOff);
    }

    //Turn the relevant segment off
    digitalWrite(SegmentPins[seg], SegOff);
  }
}

void SevenSegs::write(const char s[4]) {
  for (byte digit = 0; digit < 4; digit++) {
    switch (s[digit]) {
      case '0':
        lights[digit] = 0b11111111;
        break;
      case '1':
        lights[digit] = 0b01100000;
        break;
      case '2':
        lights[digit] = 0b11011010;
        break;
      case '3':
        lights[digit] = 0b11110010;
        break;
      case '4':
        lights[digit] = 0b01100110;
        break;
      case '5':
        lights[digit] = 0b10110110;
        break;
      case '6':
        lights[digit] = 0b10111110;
        break;
      case '7':
        lights[digit] = 0b11100000;
        break;
      case '8':
        lights[digit] = 0b11111110;
        break;
      case '9':
        lights[digit] = 0b11110110;
        break;
      case 'A':
        lights[digit] = 0b11101110;
        break;
      case 'B':
        lights[digit] = 0b11111110;
        break;
      case 'C':
        lights[digit] = 0b10011100;
        break;
      case 'D':
        lights[digit] = 0b11111100;
        break;
      case 'E':
        lights[digit] = 0b10011110;
        break;
      case 'F':
        lights[digit] = 0b10001110;
        break;
      case 'H':
        lights[digit] = 0b01101110;
        break;
      case 'L':
        lights[digit] = 0b00011100;
        break;
      case 'U':
        lights[digit] = 0b01111100;
        break;
      case 'I':
        lights[digit] = 0b00011000;
        break;
      case '/':
      case ' ':
        lights[digit] = 0b00000000;
        break;
      default:
        lights[digit] = 0b00111010;
        break;
    }
  }
}

void SevenSegs::reset() {
  write("    ");
}
