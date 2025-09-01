#include <Adafruit_LiquidCrystal.h>

#define sensor_temperatura A0
#define LED1 3
#define LED2 4
#define LED3 5

Adafruit_LiquidCrystal lcd(0);

float valor_sensor;
float valor_tensao;
float temperatura;

void setup()
{
  pinMode(sensor_temperatura, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Mentes Roboticas");
  lcd.setCursor(1, 1);
  lcd.print("EEJBC - IFMG");
  lcd.setCursor(0, 0);
}

void loop()
{
  valor_sensor = analogRead(sensor_temperatura);
  valor_tensao = (valor_sensor * 5) / 1023;
  temperatura = (valor_tensao - 0.5)/0.01;
  
  Serial.println(valor_sensor);
  Serial.println(temperatura);
  
  lcd.print("Temperatura:  ");
  lcd.setCursor(1, 1);
  lcd.print(temperatura);
  lcd.println(" Celsius  ");
  
  if(temperatura < 15){
     digitalWrite(LED1, HIGH);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, LOW);
  }else if(temperatura < 30){
     digitalWrite(LED1, HIGH);
     digitalWrite(LED2, HIGH);
     digitalWrite(LED3, LOW);
  }else{
     digitalWrite(LED1, HIGH);
     digitalWrite(LED2, HIGH);
     digitalWrite(LED3, HIGH);
  }
}