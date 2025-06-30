#define led_vermelho1 13
#define led_vermelho2 12
#define led_vermelho3 11

void setup()
{
  pinMode(led_vermelho1, OUTPUT);
  pinMode(led_vermelho2, OUTPUT);
  pinMode(led_vermelho3, OUTPUT);
}

void loop()
{
  digitalWrite(led_vermelho1, HIGH);
  digitalWrite(led_vermelho2, HIGH);
  digitalWrite(led_vermelho3, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led_vermelho1, LOW);
  digitalWrite(led_vermelho2, LOW);
  digitalWrite(led_vermelho3, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}