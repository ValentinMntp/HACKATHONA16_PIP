#include <SPI.h>
#include <MFRC522.h>

class RFID
{
  public:
    enum State {
        READY,
        WAITING,
        WRITING,
        ERROR
    };

    RFID();
    
    void init(byte sector, byte blockAddr);
    void loop();
    void reset();

    State state;
    
    byte buffer[18];
    byte size = sizeof(buffer);
    
  private:
    byte _sector;
    byte _blockAddr;
};
