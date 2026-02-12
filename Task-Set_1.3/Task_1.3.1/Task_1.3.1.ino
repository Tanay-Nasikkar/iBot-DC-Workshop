#include <LiquidCrystal.h>

LiquidCrystal lcd(2,7,3,4,5,6);

#define ldr 9
#define buzzer 10
#define lazer 8

void setup()
{
  lcd.begin(16,2);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(lazer, OUTPUT);
  digitalWrite(lazer, HIGH);
  Serial.begin(9600);
}
short prev_state=-1;
void loop()
{ 
  int ldr_value = digitalRead(ldr);
  if (ldr_value==HIGH && prev_state!=1) {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Interference");
    lcd.setCursor(4,1);
    lcd.print("Detected");
    tone(buzzer,250);
  } else if (prev_state!=0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Interference");
    noTone(buzzer);
  }
  delay(100);
}