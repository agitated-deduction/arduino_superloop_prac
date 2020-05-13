const int pot_analogInPin = A0;
const int pot_analogOutPin = 11;
int pot_sensorVal = 0;
int pot_outputVal = 0;

long pot_prevMillis = 0;
long pot_interval = 2;

void potentiometer_setup(){}
void potentiometer_loop(){
  unsigned long curMillis = millis();

  if(curMillis - pot_prevMillis>=pot_interval){
    pot_prevMillis = curMillis;

    pot_sensorVal = analogRead(pot_analogInPin);
    pot_outputVal = map(pot_sensorVal, 0, 1023, 0, 255);
    analogWrite(pot_analogOutPin, pot_outputVal);
    
  }
}
