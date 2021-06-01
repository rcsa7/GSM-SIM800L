//https://lastminuteengineers.com/sim800l-gsm-module-arduino-tutorial/
//GSM SIM800L Arduino Fazendo Chamada
#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
///SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
SoftwareSerial mySerial(11, 10);// TX-D11----RX-D10
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
  updateSerial();
  
///  mySerial.println("ATD+ +ZZxxxxxxxxxx;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  
  updateSerial();
  delay(20000); // wait for 20 seconds...
  mySerial.println("ATH"); //hang up
  updateSerial();
}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
