#include <Keypad.h> // Biblioteca para controle do teclado de matrizes

const byte LINHAS = 4; // Linhas do teclado
const byte COLUNAS = 3; // Colunas do teclado

const int PINO_LED_VERMELHO = 13; 
const int PINO_LED_VERDE = 12; 
const int PINO_LED_AMARELO = 11;

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
  
  Serial.begin(9600); // Inicializa serial monitor
  
  pinMode(PINO_LED_VERMELHO, OUTPUT); 
  pinMode(PINO_LED_VERDE, OUTPUT); 
  pinMode(PINO_LED_AMARELO, OUTPUT);

  digitalWrite(PINO_LED_VERDE, LOW); 
  digitalWrite(PINO_LED_VERMELHO, LOW); 
  digitalWrite(PINO_LED_AMARELO, LOW);
  
}

void loop() {
    
  char leitura_teclas = teclado_personalizado.getKey(); // Atribui a variavel a leitura do teclado
  
  if(leitura_teclas){ // Se alguma tecla foi pressionada

    if(leitura_teclas == '1' || leitura_teclas == '2' || leitura_teclas == '3'){
      Serial.println(leitura_teclas);
      digitalWrite(PINO_LED_VERDE, HIGH);
    }else if(leitura_teclas == '4' || leitura_teclas == '5' || leitura_teclas == '6'){
      Serial.println(leitura_teclas);
      digitalWrite(PINO_LED_AMARELO, HIGH);
    }else if(leitura_teclas == '7' || leitura_teclas == '8' || leitura_teclas == '9'){
      Serial.println(leitura_teclas);
      digitalWrite(PINO_LED_VERMELHO, HIGH);
    }else if(leitura_teclas == '0'){
      Serial.println(leitura_teclas);
      digitalWrite(PINO_LED_VERDE, LOW);
      digitalWrite(PINO_LED_AMARELO, LOW);
      digitalWrite(PINO_LED_VERMELHO, LOW);
    }else if(leitura_teclas == '*'){
      Serial.println(leitura_teclas);
      digitalWrite(PINO_LED_VERDE, HIGH);
      digitalWrite(PINO_LED_AMARELO, HIGH);
      digitalWrite(PINO_LED_VERMELHO, HIGH);
    }else { 
      Serial.println(leitura_teclas); 
    }
  }
}