long bRGB_prevMillis[3] = {0,};
long bRGB_interval[3] = {1000, 2000, 3000};

int bRGB_led[3] = {12, 7, 8};
int bRGB_ledState[3] = {LOW, LOW, LOW};

void blinkRGB_setup(){
  for(int i = 0; i < 3; i++){
    pinMode(bRGB_led[i], OUTPUT); 
  }
}
void blinkRGB_loop(){
    unsigned long curMillis = millis();

    for(int i = 0; i < 3; i ++){
      if(curMillis - bRGB_prevMillis[i] >=bRGB_interval[i]){
        bRGB_prevMillis[i] = curMillis;

        if(bRGB_ledState[i] == LOW)
      bRGB_ledState[i] = HIGH;
    else
      bRGB_ledState[i] = LOW;

    digitalWrite(bRGB_led[i], bRGB_ledState[i]);
      }
    }
}
