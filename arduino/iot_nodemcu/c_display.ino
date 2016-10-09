#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void showText(int col, int row, String text, bool clear) {
  if (clear){
    lcd.clear();
  }

  lcd.setCursor(col, row);
  lcd.print(text);
}

void setupLCD() {
  Wire.begin(2, 0);

  lcd.begin(16,2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Initializing ...");
  lcd.setCursor(0, 1);
  lcd.print("----------------");
}

void updateLCDState() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(toString(temp_c) + "C");
  lcd.setCursor(0, 1);
  lcd.print(toString(humidity) + "%");

  lcd.setCursor(6, 0);
  if (r1){
    lcd.print("A1");
  }
  else {
    lcd.print("A0");
  }

  lcd.setCursor(6, 1);
  if (r2){
    lcd.print("B1");
  }
  else {
    lcd.print("B0");
  }

  lcd.setCursor(9, 0);
  lcd.print("WS " + (String)rssi_per + "%");

  lcd.setCursor(10, 1);
  lcd.print("IP " + (String)ip[3]);
}
