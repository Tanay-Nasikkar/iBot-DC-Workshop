#include <LiquidCrystal.h>

LiquidCrystal lcd(2,7,3,4,5,6);

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("Hello World!");
  lcd.setCursor(5,1);
  lcd.print("Tanay");
}

void loop()
{ 
  delay(500);
}