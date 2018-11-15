
#include <Wire.h>
#include <Adafruit_PN532.h>


Adafruit_PN532 nfc(2, 3);

void setup(void) {
   Serial.begin(9600);
  pinMode(6,OUTPUT);//vermelho
   pinMode(10,OUTPUT);//verde
    pinMode(12,OUTPUT);//relé


  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  while (! versiondata) {
      tone(8,300,100);
      delay(5000);

  nfc.begin();
  }

  
  nfc.SAMConfig();
  

  tone(8,2000,500);
  delay(500);

}


void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;  

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) {

    nfc.PrintHex(uid, uidLength);
    
    if (uidLength == 4)
    {
      uint32_t cardid = uid[0];
      cardid <<= 8;
      cardid |= uid[1];
      cardid <<= 8;
      cardid |= uid[2];  
      cardid <<= 8;
      cardid |= uid[3]; 

    }
  Serial.println ("Codigo do cartao= ", ?????;// mostrar o codigo do cartao no monitor de serial
  
            if (uid[3] == 57)     //identificação do cartão nao aceite
  {tone(8,400,200);
  delay(200);
  tone(8,600,200);
  digitalWrite(6,HIGH);//LED vermelho
  delay(2000);
  digitalWrite(6,LOW);//LED vermelho
  }
         if (uid[3] == 213)        //identificação do cartão aceite 
  {tone(8,2000,200);
  digitalWrite(10,HIGH);//LED verde
  digitalWrite(12,HIGH);//abre porta
  delay(2000);
  digitalWrite(10,LOW);//LED verde
  digitalWrite(12,LOW);//fecha porta
  }

  }

}
