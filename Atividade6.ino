#include <Wire.h>
#include <Servo.h>
#include <Ultrasonic.h>

#define SERVO 6

Servo s;
int pos;
int posServo;

const int echoPin = 5;
const int trigPin = 4;
Ultrasonic ultrasonic(trigPin,echoPin);
int distancia;
String result;

const int MPU_addr=0x68; //Endereço do sensor
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; //Variaveis para pegar os valores medidos

unsigned long time;
int botaoLed = 7;
int botaoInter = 3;
int led1 = 11;
int led2 = 12;
int led3 = 13;
bool estadoLed = LOW;
bool estadoInter = LOW;

bool ultimoStatusBotao = HIGH;
bool ultimoStatusBotaoInter = HIGH;
int statusBotaoLed;
int statusBotaoInter;

unsigned long tempoUltimoDebounce = 0;
unsigned long tempoDebounce = 50;
unsigned long tempoUltimoDebounceInter = 0;
unsigned long tempoDebounceInter = 50;

int contButtonLed = 0;
int statusLed = 0;

int stateInter = 0;
unsigned long int tempoInter = 0;

void setup(){
  Serial.begin(9600);
 
  s.attach(SERVO);
  s.write(0);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
 
  Wire.begin(); //Inicia a comunicação I2C
  Wire.beginTransmission(MPU_addr); //Começa a transmissao de dados para o sensor
  Wire.write(0x6B); // registrador PWR_MGMT_1
  Wire.write(0); // Manda 0 e "acorda" o MPU 6050
  Wire.endTransmission(true);

  pinMode(botaoLed, INPUT);
  pinMode(botaoInter, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  time = millis();
}

void loop(){
  debounceBotoes();
  if((millis() - tempoInter) > 3000){
    stateInter = 0;
  }

  if(stateInter == 0){
    if((millis() - time) > 1000){
      time = millis();
      if(contButtonLed == 0){
        Serial.println("Modo 1");
        Serial.print("Angulo: ");
        Serial.println(posServo);
      }else if(contButtonLed == 1){
        Serial.println("Modo 2");
        Serial.print("Angulo: ");
        Serial.println(posServo);
      }else if(contButtonLed == 2){
        Serial.println("Modo 3");
        Serial.print("Angulo: ");
        Serial.println(posServo);
      }
    }

    if(contButtonLed == 0){
      aceler();
    }else if(contButtonLed == 1){
      sonar();
    }else if(contButtonLed == 2){
      potenciometro();
    }
  }else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}

void debounceBotoes(){
  int leituraLeds = digitalRead(botaoLed);
  estadoLed = digitalRead(botaoLed);
  int leituraInter = digitalRead(botaoInter);
  estadoInter = digitalRead(botaoInter);

  if(leituraLeds != ultimoStatusBotao){
    tempoUltimoDebounce = millis();
  }
  if(leituraInter != ultimoStatusBotaoInter){
    tempoUltimoDebounceInter = millis();
  }
 
  if((millis() - tempoUltimoDebounce) > tempoDebounce){
    if(leituraLeds != statusBotaoLed){
      statusBotaoLed = leituraLeds;
      if(statusBotaoLed == HIGH){
        if(contButtonLed == 0){
          contButtonLed = 1;
        }else if(contButtonLed == 1){
          contButtonLed = 2;
        }else if(contButtonLed == 2){
          contButtonLed = 0;
        }
      }
    }
  }
  ultimoStatusBotao = leituraLeds;

  if((millis() - tempoUltimoDebounceInter) > tempoDebounceInter){
    if(leituraInter != statusBotaoInter){
      statusBotaoInter = leituraInter;
      if(statusBotaoInter == HIGH){
        attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);
      }
    }
  }
  ultimoStatusBotaoInter = leituraInter;
}

void aceler(){
  Wire.beginTransmission(MPU_addr); //Começa a transmissao de dados para o sensor
  Wire.write(0x3B); // registrador dos dados medidos (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); // faz um "pedido" para ler 14 registradores, que serão os registrados com os dados medidos
  AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  delay(33);

  pos = map(AcY, -16000, 16000, 0, 180);
  s.write(pos);
  posServo = pos;
  delay(15);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void sonar(){
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
    delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
    //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
    //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
    //NA VARIAVEL "distancia"
    distancia = (ultrasonic.read(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DIST NCIA MEDIDA
    pos = map(distancia, 0, 50, 0, 180);
    s.write(pos);
    posServo = pos;
    delay(50); //INTERVALO DE 500 MILISSEGUNDOS
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
}

void potenciometro(){
  int val = analogRead(A5);
  val = map(val, 0, 1023, 0, 180);
  s.write(val);
  posServo = val;
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
}

void interrupcao(){
  Serial.println("INTERRUPCAO");
  stateInter = 1;
  tempoInter = millis();
}