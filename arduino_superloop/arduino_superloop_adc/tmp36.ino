int tmp36sensorPin = A1;
int tmp36ledPin = 13;
int tmp36sensorVal = 0;

long tmp36_prevMillis = 0;
long tmp36_interval = 0;

int tmp36sensor_ledState = 1;

void tmp36sensor_setup(){
  pinMode(tmp36ledPin, OUTPUT);
}
void tmp36sensor_loop(){
  unsigned long curMillis = millis();
  if(curMillis - tmp36_prevMillis >= tmp36_interval){
    tmp36_prevMillis = curMillis;

    if(tmp36sensor_ledState!=0){ //켜져있으면
      tmp36sensorVal = analogRead(tmp36sensorPin);
      tmp36_interval = tmp36sensorVal;
    }
    digitalWrite(tmp36ledPin, tmp36sensor_ledState);
    tmp36sensor_ledState =! tmp36sensor_ledState;
  }
}
