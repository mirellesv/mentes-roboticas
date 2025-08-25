/* Projeto - Semafóro
   Mentes Robóticas
*/

#define led_vermelho 13
#define led_amarelo 12
#define led_verde 11

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void loop() {
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
  delay(7000);

  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);
  delay(2000);

  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  delay(7000);
}
