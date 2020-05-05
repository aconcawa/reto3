#include <IRremote.h>

int RECV_PIN = 9;
int izqA=5;
int derA=3;
int vel = 125;

IRrecv irrecv(RECV_PIN);

decode_results results;

void par() { //subrutina para parar el robot
  digitalWrite(derA, 0);
  digitalWrite(izqA, 0);
}

void ade() { //subrutina andar hacia delante
  digitalWrite(derA, vel);
  digitalWrite(izqA, vel);
}

void der() { //subrunita girar derecha
  digitalWrite(derA, 0);
  digitalWrite(izqA, vel);
}

void izq(){ //subrutina girar izquierda
  digitalWrite(derA, vel);
  digitalWrite(izqA, 0);
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
