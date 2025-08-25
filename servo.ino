#include <Servo.h>

#define pot A0

Servo servo1;

int valor_pot;
int angulo_servo;

void setup()
{
  servo1.attach(3);
  angulo_servo = 0;
  servo1.write(angulo_servo);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
	valor_pot = analogRead(pot);
    angulo_servo = map(valor_pot, 0, 1023, 0, 180);
    servo1.write(angulo_servo);
    Serial.println(servo1.read());
}