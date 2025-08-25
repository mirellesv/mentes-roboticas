#define LED 9
#define POTENCIOMETRO A5

int valor_potenciometro;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(POTENCIOMETRO, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valor_potenciometro = analogRead(POTENCIOMETRO);
  Serial.println(valor_potenciometro);
  Serial.println(valor_potenciometro/4);
  analogWrite(LED, valor_potenciometro/4);
}