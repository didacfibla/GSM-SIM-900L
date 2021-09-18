#include <SoftwareSerial.h>                   //sudo chmod 666 /dev/ttyACM0
#include <Wire.h>                             //sudo chmod 666 /dev/ttyUSB0

SoftwareSerial SIM900(3, 5); 
int AUTO_POWER_ON = 6;
int DETECTOR = A3;
int i;

void setup() {
   
  pinMode(AUTO_POWER_ON, OUTPUT);           // Arranque por software del modulo gsm (simula pulsacion del boton de arranque) 
  pinMode(DETECTOR, INPUT);                 // Entrada para detectar cuando hay 5V y proceder a llamar   

  
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
    // Realizamos 5 llamadas a el numero 1
    for(i=0;i<5;i++){
      Serial.println("Llamando a 618612924");
      llamar("ATD618612924;");
      Serial.println("Fin llamada");
    }

    // Realizamos 5 llamadas a el numero 2
    for(i=0;i<5;i++){
      Serial.println("Llamando a 618612924");
      llamar("ATD618612924;");
      Serial.println("Fin llamada");
    }

    // Esperar 4 minutos en total
    
    Serial.println("Entrando en espera... tiempo de espera 4 minutos");
    delay(10000); // 1 minuto
    Serial.println("Minuto 1/4");
    
    delay(10000); // 2 minutos
    Serial.println("Minuto 2/4");
    
    delay(10000); // 3 minutos
    Serial.println("Minuto 3/4");
    
    delay(10000); // 4 minutos
    Serial.println("Minuto 4/4");

    Serial.println("Espera finalizada, iniciando deteccion nuevamente...");
  }
}


void llamar(String numeroTel){
  SIM900.println(numeroTel); //SIM900.println("ATD618612924;");
  delay(20000); // Espera 20s mientras realiza la llamada
  SIM900.println("ATH"); //Colgar la llamada
  delay(1000);
}
