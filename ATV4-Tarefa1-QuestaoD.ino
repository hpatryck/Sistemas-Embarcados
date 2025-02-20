int x[] = {10, 20, 30, 40};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (byte i = 0; i < 4; i = i + 1) {
    Serial.println(x[i]);
  }
  delay(3000);

}
