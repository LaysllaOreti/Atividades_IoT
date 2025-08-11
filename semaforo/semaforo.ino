int ledVermelho = 4;
int ledAmarelo = 3;
int ledVerde = 2;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(ledVerde, HIGH);   // Acende o LED verde
  delay(2000);                   // Espera 5 segundos
  digitalWrite(ledVerde, LOW);    // Apaga o LED verde
  digitalWrite(ledAmarelo, HIGH); // Acende o LED amarelo
  delay(2000);                   // Espera 2 segundos
  digitalWrite(ledAmarelo, LOW);  // Apaga o LED amarelo
  digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
  delay(2000);                   // Espera 5 segundos
  digitalWrite(ledVermelho, LOW);  // Apaga o LED vermelho
}
