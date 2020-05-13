long fading_prevMillis = 0;
long fading_interval = 30;

int fading_led = 11;
int fadeValue = 0;
int fadeDir = 1;

void fading_setup(){}
void fading_loop(){
  unsigned long curMillis = millis();

  if(curMillis-fading_prevMillis>=fading_interval){
    fading_prevMillis = curMillis;

    if(fadeDir==1){
      if(fadeValue<=255){
        fadeValue +=5;
        if(fadeValue>255){
          fadeValue = 255;
          fadeDir = 0;
        }
      }
    }else{
      if(fadeValue>=0){
        fadeValue -=5;
        if(fadeValue<0){
          fadeValue= 0;
          fadeDir = 1;
        }
      }
    }
    analogWrite(fading_led, fadeValue);
  }
    
}
 
