#include <IRremote.h>

int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255; // Velocidad de los motores
int estado = 'c';
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void par() { //subrutina para parar el robot
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, 0);    
  analogWrite(izqA, 0);
}

void ade() { //subrutina andar hacia delante
  analogWrite(derB, 0);   
  analogWrite(izqB, 0);
  analogWrite(derA, vel);
  analogWrite(izqA, vel);
}

void der() { //subrunita girar derecha
  analogWrite(derB, 0);     
  analogWrite(izqB, 0);
  analogWrite(izqA, 0);
  analogWrite(derA, vel);
}

void izq(){ //subrutina girar izquierda
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, 0);  
  analogWrite(izqA, vel);
}

void setup()  { 
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
 } 
 
void loop()  { 
  if(Serial.available()>0){ //Busca cambios en el bluetooth, si los hay los guarda en la variable estado.
    estado = Serial.read();
  }
  if (irrecv.decode(&results)) {
  Serial.println(results.value, HEX);
  irrecv.resume(); // Receive the next value
  }
  delay(100);
  
  if (results.value==0xFD00FF){ //Parado
    par();
  }
  
  if(estado=='a'){
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
  }
  if(estado=='b'){          // Boton IZQ 
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);      
  }
  if(estado=='c'){         // Boton Parar
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0); 
  }
  if(estado=='d'){          // Boton DER
    analogWrite(derB, 0);     
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);  
  } 

  if(estado=='e'){          // Boton Atras
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);      
  }
  if(estado=='z'){
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(58000);
    der();
    delay(300);
    ade();
    delay(36000);
    izq();
    delay(300);
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='x'){
    ade();
    delay(58000);
    der();
    delay(300);
    ade();
    delay(36000);
    izq();
    delay(300);
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='c'){
    ade();
    delay(36000);
    izq();
    delay(300);
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='v'){
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='n'){
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='m'){
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='o'){
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='l'){
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if(estado=='p'){
    ade();
    delay(55000);
    par();
  }
  if(estado=='i'){
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(58000);
    der();
    delay(300);
    ade();
    delay(36000);
    izq();
    delay(300);
    ade();
    delay(60000);
    der();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(53000);
    izq();
    delay(300);
    ade();
    delay(39000);
    der();
    delay(300);
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
}
