#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereço 0x27 com 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x3F  , 16, 2);

void setup() {
  lcd.init();            // Inicializa o LCD
  lcd.backlight();       // Liga a luz de fundo do LCD

  lcd.setCursor(0, 0);   // Coluna 0, linha 0
  lcd.print("Ola, mundo!");

  lcd.setCursor(0, 1);   // Coluna 0, linha 1
  lcd.print("Display OK :)");
}

void loop() {
  // Nada no loop. Mensagem fica fixa.
}
