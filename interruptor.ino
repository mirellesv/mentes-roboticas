#define led 8
#define botao 10

int estadoBotao;

void setup(){
   pinMode(led, OUTPUT);
   pinMode(botao, INPUT);
}

void loop(){
   estadoBotao = digitalRead(botao);
   digitalWrite(led, estadoBotao);
}