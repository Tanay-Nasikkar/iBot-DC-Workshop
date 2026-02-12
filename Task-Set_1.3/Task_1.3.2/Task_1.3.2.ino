#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
int MAX_COLS = SCREEN_WIDTH/8;
int MAX_ROWS = SCREEN_HEIGHT/8;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
}

int col=0;
int row=0;

void drawGrid() {
  int i;
  for (i=0; i<display.width()/8; i++) {
    display.drawLine(8*i, 0, 8*i, display.height(), SSD1306_WHITE);
  }
  display.drawLine(8*i-1, 0, 8*i-1, display.height(), SSD1306_WHITE);
  for (i=0; i<display.height()/8; i++) {
    display.drawLine(0, 8*i, display.width(), 8*i, SSD1306_WHITE);
  }
  display.drawLine(0, 8*i-1, display.width(), 8*i-1, SSD1306_WHITE);
}

void drawCharacter() {
  display.fillRect(8*col, 8*row, 8, 8, SSD1306_WHITE);
}

void refreshScreen() {
  display.clearDisplay();
  drawGrid();
  drawCharacter();
  display.display();
}

void loop() {
  int any_on, up, down, left, right;
  bool first_run=true;
  do {
    up = !digitalRead(UP);
    down = !digitalRead(DOWN);
    left = !digitalRead(LEFT);
    right = !digitalRead(RIGHT);
    any_on = up || down || left || right;
    if (first_run) {
      if (up) row = (row-1)%MAX_ROWS;
      if (down) row = (row+1)%MAX_ROWS;
      if (left) col = (col-1)%MAX_COLS;
      if (right) col = (col+1)%MAX_COLS;
      if (row<0) row += MAX_ROWS;
      if (col<0) col += MAX_COLS;
      refreshScreen();
      Serial.print(row);
      Serial.println(col);
      first_run=false;
    }
    delay(50);
  } while (any_on);
}