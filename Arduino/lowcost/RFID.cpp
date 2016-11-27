#include "RFID.h"

#define RST_PIN         9
#define SS_PIN          10

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

RFID::RFID() {
  
}

void RFID::init(byte sector, byte blockAddr) {
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card

    // Prepare the key (used both as key A and as key B)
    // using FFFFFFFFFFFFh which is the default at chip delivery from the factory
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    _sector = sector;
    _blockAddr = blockAddr;
}

void RFID::loop() {
    byte trailerBlock = 7;
    MFRC522::StatusCode status;
            
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Authenticate using key A
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        state = ERROR;
        return;
    }

    // Read data from the block (again, should now be what we have written)
    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(_blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
      state = ERROR;
    }

    state = WAITING;
}

void RFID::write(byte dataBlock[16]) {
    _dataBlock = dataBlock;
    state = WRITING;
}

void RFID::reset() {
    // Halt PICC
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
    
    state = READY;
}

MFRC522::Uid RFID::getUid() {
    return mfrc522.uid;
}
