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
    void write(byte dataBlock[16]);
    void reset();
    MFRC522::Uid getUid();

    State state;
    
    byte buffer[18];
    byte size = sizeof(buffer);
    
  private:
    byte _sector;
    byte _blockAddr;
    byte* _dataBlock;
};
