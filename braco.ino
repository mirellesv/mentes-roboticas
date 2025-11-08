#include <Servo.h> 

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// define as portas dos potenciômetros
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3

// nomeia os servos
Servo serv1, serv2, serv3, serv4;

// variáveis para armazenar somas
long soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0;

// contador de leituras
int contador = 0;

// variáveis dos ângulos
int motor1, motor2, motor3, motor4;

void setup() {
  Serial.begin(9600);
  
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
}

void loop() {
  // leitura atual dos potenciômetros
  int leitura1 = analogRead(pot1);
  int leitura2 = analogRead(pot2);
  int leitura3 = analogRead(pot3);
  int leitura4 = analogRead(pot4);

  // acumula as leituras
  soma1 += leitura1;
  soma2 += leitura2;
  soma3 += leitura3;
  soma4 += leitura4;
  contador++;

  // quando atingir 200 leituras, calcula a média
  if (contador >= 200) {
    int media1 = soma1 / contador;
    int media2 = soma2 / contador;
    int media3 = soma3 / contador;
    int media4 = soma4 / contador;

    // converte as médias em ângulos
    motor1 = map(media1, 0, 1023, 0, 180);
    motor2 = map(media2, 0, 1023, 0, 180);
    motor3 = map(media3, 0, 1023, 85, 180);
    motor4 = map(media4, 0, 1023, 0, 43);

    // posiciona os servos com base na média
    serv1.write(motor1);
    serv2.write(motor2);
    serv3.write(motor3);
    serv4.write(motor4);

    // exibe os resultados no monitor serial
    Serial.println("**********************************************");
    Serial.print("Média Pot1: "); Serial.print(media1); Serial.print(" -> Ângulo: "); Serial.println(motor1);
    Serial.print("Média Pot2: "); Serial.print(media2); Serial.print(" -> Ângulo: "); Serial.println(motor2);
    Serial.print("Média Pot3: "); Serial.print(media3); Serial.print(" -> Ângulo: "); Serial.println(motor3);
    Serial.print("Média Pot4: "); Serial.print(media4); Serial.print(" -> Ângulo: "); Serial.println(motor4);

    // reinicia as variáveis para próxima média
    soma1 = soma2 = soma3 = soma4 = 0;
    contador = 0;
  }

  delay(50); // define o tempo entre as leituras
}
