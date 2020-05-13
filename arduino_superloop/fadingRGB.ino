long fRGB_prevMillis[3] = {0,};
long fRGB_interval[3] = {30, 60, 120};

int fRGB_led[3] = {10, 6, 9};
int fRGB_value[3] = {0, 0, 0};
int fRGB_dir[3] = {1, 1, 1};

void fadingRGB_setup(){}
void fadingRGB_loop(){
  unsigned long curMillis = millis();

  for(int i = 0; i < 3; i++){
    if(curMillis - fRGB_prevMillis[i]>=fRGB_interval[i]){
      fRGB_prevMillis[i] = curMillis;

      if(fRGB_dir[i] == 1){
        if(fRGB_value[i] <=255){
          fRGB_value[i]+=5;
          if(fRGB_value[i]>255){
            fRGB_value[i] = 255;
            fRGB_dir[i] = 0;
          }
        }
      }else{
        if(fRGB_value[i] >=0){
          fRGB_value[i]-=5;
          if(fRGB_value[i]<0){
            fRGB_value[i] = 0;
            fRGB_dir[i] = 1;
          }
      }
    }
  }analogWrite(fRGB_led[i], fRGB_value[i]);
  }
}
