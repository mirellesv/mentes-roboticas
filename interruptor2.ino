#define botao 10
#define led 9

int estadoBotao;
int estadoBotaoAnterior;
int ledLigado = 0;

void setup()
{
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  estadoBotao = digitalRead(botao);
  
  if(estadoBotao != estadoBotaoAnterior){
    if(estadoBotao){
       ledLigado = !ledLigado;
       digitalWrite(led, ledLigado);
    }
  }
  
  estadoBotaoAnterior = estadoBotao;
  delay(10);
}