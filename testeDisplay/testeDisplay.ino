// Piano com LCD - Layslla Eduarda Oreti
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27   

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

const byte pinos[8] = {3, 4, 5, 6, 7, 8, 9, 10};

const int frequencias[8] = {
  523, 587, 659, 698, 784, 880, 988, 1047
};

const char* nomes[8] = {
  "Do", "Re", "Mi", "Fa", "Sol", "La", "Si", "Do agudo"
};

const byte buzz = 2;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nota:");
  lcd.setCursor(0, 1);
  lcd.print("--"); // começa sem nota

  for (byte i = 0; i < 8; i++) {
    pinMode(pinos[i], INPUT_PULLUP); // botões com pull-up
  }

  pinMode(buzz, OUTPUT);
  noTone(buzz); // garante silêncio inicial
}

void loop() {
  bool botaoPressionado = false;

  // Verifica cada botão
  for (byte i = 0; i < 8; i++) {
    if (digitalRead(pinos[i]) == LOW) { // LOW = pressionado
      // Quando pressionado → toca e mostra a nota
      tone(buzz, frequencias[i]);
      lcd.setCursor(0, 1);
      lcd.print("                "); // limpa linha
      lcd.setCursor(0, 1);
      lcd.print(nomes[i]);
      Serial.println(nomes[i]);
      botaoPressionado = true;
      break; // para no primeiro botão encontrado
    }
  }

  // Se nenhum botão está pressionado → silêncio e LCD "--"
  if (!botaoPressionado) {
    noTone(buzz); // silêncio total
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("--");
  }
}
