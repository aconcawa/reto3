#include <IRremote.h>

int RECV_PIN = 9;
int izq=3;
int der=2;
int vel = 125;

IRrecv irrecv(RECV_PIN);

decode_results results;

void par() { //subrutina para parar el robot
  analogWrite(der, 0);
  analogWrite(izq, 0);
}

#include <IRremote.h>

int RECV_PIN = 9;
int izqA=3;
int derA=2;
int vel = HIGH;

IRrecv irrecv(RECV_PIN);

decode_results results;

void par() { //subrutina para parar el robot
  analogWrite(derA, 0);
  analogWrite(izqA, 0);
}

void ade() { //subrutina andar hacia delante
  analogWrite(derA, vel);
  analogWrite(izqA, vel);
}

void der() { //subrunita girar derecha
  analogWrite(derA, 0);
  analogWrite(izqA, vel);
}

void izq(){ //subrutina girar izquierda
  analogWrite(derA, vel);
  analogWrite(izqA, 0);
}

void setup()
{
  pinMode (izqA, OUTPUT);
  pinMode (derA, OUTPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
 
  if (results.value==0xFD00FF){ //Parado
    par();
  }
  if (results.value==0xFD30CF){ //Desde la primera parada
    ade();
  }
}
