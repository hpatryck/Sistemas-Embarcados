unsigned long time;
int cont = 0;
int entrada = 7;
bool estado = LOW;
int aux = 1;

int led = 13;

int ultimoStatusBotao = 0;
int tempoUltimoDebounce = 0;
int statusBotao = 0;
int tempoDebounce = 50;


void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(entrada, INPUT);
  time = millis();
}

void loop(){
  int leitura = digitalRead(entrada);

  if(leitura != ultimoStatusBotao){
    tempoUltimoDebounce = millis();
  }

  if((millis() - tempoUltimoDebounce) > tempoDebounce){
    if(leitura != statusBotao){
      statusBotao = leitura;
      if(statusBotao == HIGH){
        cont++;
      }
    }
  }
  if(millis() - time >= 500){
    time = millis();
    Serial.print("variações = ");
    Serial.print(cont);
    Serial.print("\n");
    cont = 0;
  }

  ultimoStatusBotao = leitura;
}