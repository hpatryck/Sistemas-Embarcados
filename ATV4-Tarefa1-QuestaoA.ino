int a = 0b00001010;

int x = a >> 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  printOut1(a);
  delay(2000);
  printOut1(x);
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
