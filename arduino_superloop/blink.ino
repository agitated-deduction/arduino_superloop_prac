int blink_led = 13;
int blink_ledState = LOW;
void blink_setup(){
  pinMode(blink_led, OUTPUT);
}

long blink_prevMillis = 0;
long blink_interval = 1000;

void blink_loop(){
  unsigned long curMillis = millis();

  if(curMillis - blink_prevMillis >= blink_interval){
    blink_prevMillis = curMillis;

    if(blink_ledState == LOW)
      blink_ledState = HIGH;
    else
      blink_ledState = LOW;

    digitalWrite(blink_led, blink_ledState);
  }
}
