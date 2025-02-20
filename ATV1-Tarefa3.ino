#include <Servo.h>

#define SERVO 6 // Porta Digital 6 PWM

Servo s; // Variável Servo
int pos; // Posição Servo


void setup ()
{
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
}

void loop(){
  int val = analogRead(A8);
  val = map(val, 0, 1023, 0, 255);
  s.write(val);

}