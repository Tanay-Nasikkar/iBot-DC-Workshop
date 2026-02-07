#include <Servo.h>

Servo myservo;

int angle = 0;
bool increase = true;

void setup()
{
  myservo.attach(11);
  myservo.write(angle);
  delay(2000);
}

void loop()
{
  if (increase){
    angle++;
    if (angle>=181){
      angle=179;
      increase = false;
    }
  } else {
    angle--;
    if (angle<=0){
      angle=1;
      increase = true;
    }
  }

  myservo.write(angle);

  delay(5000/(180*2));
}
  	