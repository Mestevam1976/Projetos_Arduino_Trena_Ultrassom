#include <Arduino.h>

#define echoPin 11        //Pino Echo
#define trigPin 12        //Pino Desencadear
long duration, distance;  //A duração é usada para calcular a distância

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //Calcular a distância em cm com base na velocidade do som:
  distance = duration / 58.2;
  Serial.println(distance);
  delay(50);
}
