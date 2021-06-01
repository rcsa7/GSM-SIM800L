//Testando Comandos AT
//https://lastminuteengineers.com/sim800l-gsm-module-arduino-tutorial/
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

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CSQ"); //Verifique a 'intensidade do sinal' - o primeiro # é a intensidade de dB, deve ser superior a cerca de 5.
                              // Quanto maior, melhor. Claro que depende da sua antena e localização! range is 0-31 , 31 is the best
  updateSerial();
  mySerial.println("AT+CCID"); //obter o número do cartão SIM - testa se o cartão SIM está OK e você pode verificar se o número está escrito no cartão.
  updateSerial();
  mySerial.println("AT+CREG?"); //Verifique se você está registrado na rede. O segundo # deve ser 1 ou 5.
                                   // 1 indica que você está registrado na rede doméstica e 5 indica rede em roaming.
                                  // Além desses dois números, indicam que você não está registrado em nenhuma rede.
  updateSerial();
}

void loop()
{
  updateSerial();
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
