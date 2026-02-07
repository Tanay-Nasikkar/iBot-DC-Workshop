void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int sum, temp, cnt;
int current_reading;
int record[10]={0};
void loop() {
  // put your main code here, to run repeatedly:
  current_reading = analogRead(A0);
  Serial.println(current_reading);

  if (abs(current_reading-sum/(cnt!=0?cnt:1))>3) {
    digitalWrite(13,HIGH);
    Serial.print("sum: ");
    Serial.print(sum);
    Serial.print(" cnt: ");
    Serial.print(cnt); 
    Serial.print(" diff: ");
    Serial.println(abs(current_reading-(sum/(cnt!=0?cnt:1))));
    delay(2000);  
    digitalWrite(13,LOW);
  }
  else
    delay(100);

  cnt = min(cnt+1, 10);
  sum += current_reading-record[0];
  for (int i=0; i<9; i++){
    record[i] = record[i+1];
  }
  record[9] = current_reading;
}
