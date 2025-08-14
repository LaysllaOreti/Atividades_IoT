int buzz = 2;

void setup() {
  pinMode(buzz, OUTPUT);
}

void loop() {
  tone(buzz, 1000);  // Toca tom de 1000 Hz
  delay(1000);
  noTone(buzz);
  delay(1000);
}
