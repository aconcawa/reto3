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

void ade() { //subrutina andar hacia delante
  analogWrite(der, vel);
  analogWrite(ziq, vel);
}

void der() {
  analogWrite(der, 0);
  analogWrite(izq, vel);


void setup()
{
  pinMode (izq, OUTPUT);
  pinMode (der, OUTPUT);
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
    par;
  }
  if (results.value==0xFD30CF){ //Desde la primera parada
    digitalWrite(izquierda,HIGH);
    digitalWrite(derecha,HIGH);
  }
}
