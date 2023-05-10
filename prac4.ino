/*
Práctica 4
*/

//Definición de variables globales

int ledVerde = 2;      //Indicador luminoso verde
int ledAmarillo = 3;    //Indicador luminoso amarillo
int ledAzul = 4;      //Indicador luminoso azul
int ledRojo = 5;      //Indicador luminoso rojo

int lectura1 = 0;     //Variable para lectura del CAD, laboratorio S1
int lectura2 = 0;     //Variable para lectura del CAD, laboratorio TIFB-3

float temperatura1 = 0.0; //Variable para cálculo de temperatura, laboratorio S1
float temperatura2 = 0.0; //Variable para cálculo de temperatura, laboratorio TIFB-3


//Función void setup()
void setup()
{
  //Se declaran los indicadores luminosos como pines de salida
  for (int i = 2; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
  //Inicialización de la comunicación serial
  Serial.begin(9600);
  
  pinMode(9, OUTPUT);         //Instrucción prescindible por tratarse de PWM
  pinMode(10, OUTPUT);        //Instrucción prescindible por tratarse de PWM
}

void loop()
{
  //Lectura analógica del sensor de temperatura S1
  lectura1 = analogRead(A0);
  
  //Lectura analógica del sensor de temperatura TIFB-3
  lectura2 = analogRead(A1);

  //Cálculo de la temperatura en S1
  temperatura1 = ( lectura1 * (500.0 / 1023.0) );
  
  //Cálculo de la temperatura en TIFB-3
  temperatura2 = ( lectura2 * (500.0 / 1023.0) );
  
  //Despliegue de la temperatura en monitor serie 
  
  Serial.println(temperatura1);
  Serial.println(temperatura2);
  
  //Primer condición: temperatura adecuada en ambos laboratorios
  if(temperatura1 < 30 && temperatura2 < 30){
    //Indicador luminoso verde encendido
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRojo, LOW);
    
    //Ambos ventiladores apagados
    analogWrite(9, 0);
    analogWrite(10, 0);
  }else if(temperatura1 <30 && temperatura2 >=30){  //Segunda condición
    //Indicador luminoso amarillo encendido
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRojo, LOW);
    
    //Ventilador 2 encendido
    analogWrite(9, 0);
    analogWrite(10, 255);
  }else if(temperatura1 >= 30 && temperatura2 < 30){  //Tercer condición
    //Indicador luminoso azul encendido
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledRojo, LOW);
    
    //Ventilador 1 encendido
    analogWrite(9, 255);
    analogWrite(10, 0);
  }else if(temperatura1 >= 30 && temperatura2 >= 30){ //Cuarta condición
    //Indicador luminoso rojo encendido
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRojo, HIGH);
    
    //Ventiladores 1 y 2 encendidos
    analogWrite(9, 255);
    analogWrite(10, 255);
  }

  delay(200);

}
