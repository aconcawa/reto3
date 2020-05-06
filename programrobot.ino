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
  if (results.value==0xFD08F7){ //Desde 2
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
  if (results.value==0xFD8877){ //Desde 3
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
  if (results.value==0xFD48B7){ //Desde 4
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
  if (results.value==0xFD28D7){ //Desde 5
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
  if (results.value==0xFDA857){ //Desde 6
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
  if (results.value==0xFD6897){ //Desde 7
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
  if (results.value==0xFD18E7){ //Desde 8
    ade();
    delay(77000);
    der();
    delay(300);
    ade();
    delay(55000);
    par();
  }
  if (results.value==0xFD9867){ //Desde 9
    ade();
    delay(55000);
    par();
  }
  if (results.value==0xFD58A7){ //Desde 10
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
