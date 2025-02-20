#include <Keypad.h> // Biblioteca para controle do teclado de matrizes
#include <Servo.h>

#define SERVO 7

int botao = 2;
bool stateB = LOW;
int ultimoStatusBotao = 0;
int tempoUltimoDebounce = 0;
int statusBotao = 0;
unsigned long tempoDebounce = 50;

int angulo = 0;

unsigned long int tempoAnteriorTarefa1 = 0;

int brilho1 = 1;
int brilho2 = 1;
int brilho3 = 1;

Servo s; // Variável Servo
int pos; // Posição Servo

const byte LINHAS = 4; // Linhas do teclado
const byte COLUNAS = 3; // Colunas do teclado

const int PINO_LED_VERMELHO = 13; 
const int PINO_LED_VERDE = 12; 
const int PINO_LED_AMARELO = 11;

bool estado_led_vermelho = false;
bool estado_led_verde = false;
bool estado_led_amarelo = false;

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { // Matriz de caracteres (mapeamento do teclado)
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

const byte PINOS_LINHAS[LINHAS] = {3, 4, 5, 6}; // Pinos de conexao com as linhas do teclado
const byte PINOS_COLUNAS[COLUNAS] = {8, 9, 10}; // Pinos de conexao com as colunas do teclado

Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado

void setup() {

  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
  
  Serial.begin(9600); // Inicializa serial monitor
  
  pinMode(PINO_LED_VERMELHO, OUTPUT); 
  pinMode(PINO_LED_VERDE, OUTPUT); 
  pinMode(PINO_LED_AMARELO, OUTPUT);

  digitalWrite(PINO_LED_VERDE, LOW); 
  digitalWrite(PINO_LED_VERMELHO, LOW); 
  digitalWrite(PINO_LED_AMARELO, LOW);
  
}

void loop() {

  int leitura = digitalRead(botao);

  if(leitura != ultimoStatusBotao){
    tempoUltimoDebounce = millis();
  }

  if((millis() - tempoUltimoDebounce) > tempoDebounce){
    if(leitura != statusBotao){
      statusBotao = leitura;
      if(statusBotao == HIGH){
        if(estado_led_vermelho){
          if(brilho1 == 1){
            analogWrite(PINO_LED_VERMELHO, 25);
            brilho1 = 0;
          }else if(brilho1 == 0){
            analogWrite(PINO_LED_VERMELHO, 200);
            brilho1 = 1;
          }
        }if(estado_led_verde){
          if(brilho2 == 1){
            analogWrite(PINO_LED_VERDE, 25);
            brilho2 = 0;
          }else if(brilho2 == 0){
            analogWrite(PINO_LED_VERDE, 200);
            brilho2 = 1;
          }
        }if(estado_led_amarelo){
          if(brilho3 == 1){
            analogWrite(PINO_LED_AMARELO, 25);
            brilho3 = 0;
          }else if(brilho3 == 0){
            analogWrite(PINO_LED_AMARELO, 200);
            brilho3 = 1;
          }
        }
      }
    }
    
    char leitura_teclas = teclado_personalizado.getKey(); // Atribui a variavel a leitura do teclado
  
    if(leitura_teclas){ // Se alguma tecla foi pressionada

      if(leitura_teclas == '1'){
        Serial.println(leitura_teclas);
        if(estado_led_vermelho == false){
          digitalWrite(PINO_LED_VERMELHO, HIGH);
          estado_led_vermelho = !estado_led_vermelho;
        }else{
          digitalWrite(PINO_LED_VERMELHO, LOW);
          estado_led_vermelho = !estado_led_vermelho;
        }
      }else if(leitura_teclas == '2'){  
        Serial.println(leitura_teclas);
        if(estado_led_verde == false){
          digitalWrite(PINO_LED_VERDE, HIGH);
          estado_led_verde = !estado_led_verde;
        }else{
          digitalWrite(PINO_LED_VERDE, LOW);
          estado_led_verde = !estado_led_verde;
        }
      }else if(leitura_teclas == '3'){
        Serial.println(leitura_teclas);
        if(estado_led_amarelo == false){
          digitalWrite(PINO_LED_AMARELO, HIGH);
          estado_led_amarelo = !estado_led_amarelo;
        }else{
          digitalWrite(PINO_LED_AMARELO, LOW);
          estado_led_amarelo = !estado_led_amarelo;
        }
      }else if(leitura_teclas == '4'){
        Serial.println(leitura_teclas);
        s.write(pos = 0);
        angulo = 0;
        delay(15);
      }else if(leitura_teclas == '5'){  
        Serial.println(leitura_teclas);
        s.write(pos = 90);
        angulo = 90;
        delay(15);
      }else if(leitura_teclas == '6'){
        Serial.println(leitura_teclas);
        s.write(pos = 180);
        angulo = 180;
        delay(15);
      }else if(leitura_teclas == '7'){
        Serial.println(leitura_teclas);
        digitalWrite(PINO_LED_VERMELHO, LOW);
        digitalWrite(PINO_LED_VERDE, LOW);
        digitalWrite(PINO_LED_AMARELO, LOW);
        estado_led_vermelho = false;
        estado_led_verde = false;
        estado_led_amarelo = false;
      }else if(leitura_teclas == '8'){ 
        Serial.println(leitura_teclas);
        digitalWrite(PINO_LED_VERMELHO, HIGH);
        digitalWrite(PINO_LED_VERDE, HIGH);
        digitalWrite(PINO_LED_AMARELO, HIGH);
      }else { 
        Serial.println(leitura_teclas); 
      }
    }
  }

  if((millis() - tempoAnteriorTarefa1) > 1000){
    if(estado_led_vermelho == true){
      Serial.println("Led 1 aceso");
      if(brilho1 == 1){
        Serial.println("Brilho Alto");
      }else{
        Serial.println("Brilho Baixo");
      }
    }else{
      Serial.println("Led 1 apagado");
    }
    if(estado_led_verde == true){
      Serial.println("Led 2 aceso");
      if(brilho2 == 1){
        Serial.println("Brilho Alto");
      }else{
        Serial.println("Brilho Baixo");
      }
    }else{
      Serial.println("Led 2 apagado");
    }
    if(estado_led_amarelo == true){
      Serial.println("Led 3 aceso");
      if(brilho3 == 1){
        Serial.println("Brilho Alto");
      }else{
        Serial.println("Brilho Baixo");
      }
    }else{
      Serial.println("Led 3 apagado");
    }
    Serial.print("O angulo atual é: ");
    Serial.println(angulo);
    
   tempoAnteriorTarefa1 = millis();
  }

}