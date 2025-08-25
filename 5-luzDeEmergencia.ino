#define LDR A0
#define LED 2

int valor_ldr;

void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valor_ldr = analogRead(LDR);
  Serial.println(valor_ldr);
  
  if(valor_ldr < 500){
     digitalWrite(LED, HIGH); 
  }else{
     digitalWrite(LED, LOW);
  }
}