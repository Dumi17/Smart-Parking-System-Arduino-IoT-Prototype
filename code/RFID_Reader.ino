#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // SDA (B1 → A1 → RC522)
#define RST_PIN 9  // RST (B5 → A5 → RC522)

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Creăm obiect RFID

void setup() {
  Serial.begin(9600);
  SPI.begin();         // Inițializare magistrală SPI
  mfrc522.PCD_Init();  // Inițializare RC522

  Serial.println("Scanare cartela RFID...");
}

void loop() {
  // Așteaptă o nouă cartelă
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Afișează UID-ul
  Serial.print("UID detectat: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10)
      Serial.print("0");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Oprește comunicarea
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  delay(1500);
}
