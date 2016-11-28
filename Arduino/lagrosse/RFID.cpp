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

    char s[10];
    sprintf(s, "I;%02X%02X%02X%02X", mfrc522.uid.uidByte[0], mfrc522.uid.uidByte[1], mfrc522.uid.uidByte[2], mfrc522.uid.uidByte[3]);
    Serial.println(s);

    byte dataBlock[]    = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };

    int i = 0;
    while(i < 4) {
      if (Serial.available() > 0) {
        dataBlock[i] = (byte) (Serial.read() - '0');
        i++;
      }
    }
  
    // Write data to the block
    status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(_blockAddr, dataBlock, 16);
    if (status != MFRC522::STATUS_OK) {
        state = ERROR;
        return;
    }

    reset();
}

void RFID::reset() {
    state = READY;

    // Halt PICC
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
}

