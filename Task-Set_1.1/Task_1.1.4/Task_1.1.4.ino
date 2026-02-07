const int Trig_Pin = 8;
const int Echo_Pin = 9;

float Distance, Duration;

void setup()
{
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);

  Duration = pulseIn(Echo_Pin, HIGH, 30000);
  Distance = (Duration*0.343)/20;

  if(Duration == 0)
  {
    Serial.println("No Object Detected");
  }
  else
  {
    Serial.print("Distance : ");
    Serial.print(Distance);
    Serial.print(" cm");
    Serial.print(" (Duration : ");
    Serial.print(Duration);
    Serial.println(" µs)");
  }
  
  delay(500);
}