int x = 30;
int y = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(x %= y);
  delay(3000);
}
