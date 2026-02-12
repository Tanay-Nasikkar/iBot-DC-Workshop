#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define sound_pin A0
#define buzzer 9

void setup() {
  Serial.begin(115200);

  pinMode(sound_pin, INPUT);
  pinMode(buzzer, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  tone(buzzer,250);
}

void loop() {
  int sound_in = analogRead(sound_pin);
  Serial.println(sound_in);
  display.clearDisplay();
  display.drawLine(display.width()/2, display.height()/2-sound_in/32, display.width()/2, display.height()/2+sound_in/32, SSD1306_WHITE);
  display.display();
  delay(10);
}
