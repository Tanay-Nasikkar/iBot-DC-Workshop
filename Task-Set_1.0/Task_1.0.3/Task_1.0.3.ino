int toggle = LOW;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(7));
  if (digitalRead(7)==LOW) {
    i++;
    toggle = HIGH?toggle==LOW:HIGH;
    Serial.println(i);
    digitalWrite(3, toggle);
    do {
      delay(100);
    } while (digitalRead(7)==LOW);
  }
}
