#include <Arduino.h>

class SevenSegs
{
  public:
    SevenSegs();
    
    void init();
    void loop();
    void write(const char s[4]);
    void reset();

    
  private:
    boolean DigitOn, DigitOff, SegOn, SegOff;
    byte DigitPins[4];
    byte SegmentPins[8];
    byte lights[4];
};
