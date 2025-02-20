int b = 0b1111;

int y = b << 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  printOut1(b);
  delay(2000);
  printOut1(y);
  delay(2000);
  
}

void printOut1(int c) {
  for (int bits = 7; bits > -1; bits--) {
    // Compara bits 7-0 no byte
    if (c & (1 << bits)) {
      Serial.print("1");
    }
    else {
      Serial.print("0");
    }
  }
  Serial.println("");
}
