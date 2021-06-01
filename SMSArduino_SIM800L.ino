//https://www.arduinoportugal.pt/enviar-sms-arduino-sim800l/
//Enviar SMS com Arduino e SIM800L
#include <SoftwareSerial.h> // Incluimos a livraria SoftwareSerial
SoftwareSerial mySerial(8, 9); // Declaramos os pinos RX(8) y TX(9) que vamos a usar

void setup(){
Serial.begin(9600);       // Iniciamos a comunicação serie
mySerial.begin(9600);     // Iniciamos uma segunda comunicação serie
delay(1000);              // Pausa de 1 segundo
EnviaSMS();               // Chamada a função que envia o SMS
}

void loop(){
if (mySerial.available()){          // Se a comunicação SoftwareSerial tem dados
  Serial.write(mySerial.read());    // Obtemo-los por comunicação serie normal
} 
  
if (Serial.available()){            // Se a comunicação serie normal tem dados
  while(Serial.available()) {       // e enquanto tenha dados para mostrar 
    mySerial.write(Serial.read());  // Obtemos pela comunicação SoftwareSerial
  } 
  mySerial.println();               // Enviamos um fim de linha
}
}

// Função para o envio de um SMS
void EnviaSMS(){              
 mySerial.println("AT+CMGF=1");                 // Activamos a função de envio de SMS
 delay(100);                                    // Pequena pausa
 mySerial.println("AT+CMGS=\"+351XXXXXXXXX\"");  // Definimos o número do destinatário em formato internacional
 delay(100);                                    // Pequena pausa
 mySerial.print("Olá Mundo!");                 // Definimos o corpo da mensagem
 delay(500);                                    // Pequena pausa
 mySerial.print(char(26));                      // Enviamos o equivalente a Control+Z 
 delay(100);                                    // Pequena pausa
 mySerial.println("");                          // Enviamos um fim de linha
 delay(100);                                    // Pequena pausa
}
