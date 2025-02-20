int button = 13;
int leds[] = {4, 5, 6, 7};
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);

  pinMode(10, OUTPUT);
}

void loop() {
  while(digitalRead(button) == HIGH){
    if(i == 0){
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      tone(10, 300, 3000);
      i++;
    }else if(i == 1){
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      tone(10, 1000, 3000);
      i++;
    }else if(i == 2){
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], LOW);
      tone(10, 2500, 3000);
      i++;
    }else if(i == 3){
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], HIGH);
      tone(10, 5000, 3000);
      i=0;
    }
    delay(400);  
  }

}
