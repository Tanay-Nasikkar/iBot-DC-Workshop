void setup() {}

int brightness = 0;
bool increase = true;

void loop()
{
  	if (increase){
  		brightness++;
      if (brightness>=256){
  			brightness=254;
  			increase = false;
      }
    } else {
  		brightness--;
      if (brightness<=0){
  			brightness=1;
  			increase = true;
      }
    }
  
  	analogWrite(3,brightness);
  
  	delay(1000/(256*2));
}