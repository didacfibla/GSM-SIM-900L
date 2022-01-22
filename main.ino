#include <SoftwareSerial.h>                   //sudo chmod 666 /dev/ttyACM0
#include <Wire.h>                             //sudo chmod 666 /dev/ttyUSB0

SoftwareSerial SIM900(3, 5); 
int AUTO_POWER_ON = 6;
int DETECTOR = A3;
int i;

void setup() {
   
  pinMode(AUTO_POWER_ON, OUTPUT);           // Arranque por software del modulo gsm (simula pulsacion del boton de arranque) 
  pinMode(DETECTOR, INPUT);      
  
  Serial.begin(9600);
  SIM900.begin(9600);
  
  // Arranque por software del modulo SIM900L
  digitalWrite(AUTO_POWER_ON, LOW);
  delay(1000);
  digitalWrite(AUTO_POWER_ON, HIGH);
  delay(2000);
  digitalWrite(AUTO_POWER_ON, LOW);
  delay(1000);


  // Delay de 10 segundos para darle tiempo a encontrar señal 
  for(i=10;i>0;i--){
    Serial.print("Tiempo restante preparativos GSM: ");
    Serial.print(i);
    Serial.println(" segundos.");
    delay(1000);  
  }
  
}

void loop(){ 
  
  if (digitalRead(DETECTOR) == HIGH){
    
    Serial.println("Alarma activada");

    int i;
     
    // Realizamos 5 llamadas a el numero XXX XXX XXX
    for(i=0;i<5;i++){
      Serial.println("Llamando a XXXXXXXXX");
      llamar("ATDXXXXXXXXX;");
      Serial.println("Fin llamada");
    }
  }
}


void llamar(String numeroTel){
  SIM900.println(numeroTel); //SIM900.println("ATD618612924;");
  delay(20000); // Espera 20s mientras realiza la llamada
  SIM900.println("ATH"); //Colgar la llamada
  delay(1000);
}
