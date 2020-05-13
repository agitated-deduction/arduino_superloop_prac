long pho_prevMillis = 0;
long pho_interval = 1000;

int pho_pin = A2;
int pho_ledPin[3] = {12, 7, 8};
int pho_val = 0;

void photosensor_setup(){
  for(int i = 0; i < 3; i++){
    pinMode(pho_ledPin[i], OUTPUT);
  }
}

void photosensor_loop(){
  unsigned long curMillis = millis();
  if(curMillis - pho_prevMillis >= pho_interval){
    pho_prevMillis = curMillis;
    pho_val = analogRead(pho_pin);

    if(pho_val<600){
      for(int i = 0; i < 3; i++)
        digitalWrite(pho_ledPin[i], HIGH);
    }else{
      for(int i = 0; i < 3; i++)
        digitalWrite(pho_ledPin[i], LOW);
    }
  }
}
