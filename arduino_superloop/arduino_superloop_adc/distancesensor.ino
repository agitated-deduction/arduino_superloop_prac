int distsensor_pin = A3;
int distsensor_ledPin[3] = {10, 9, 6};
int dist_inputVal = 0;
int dist_outputVal = 0;

long dist_prevMillis = 0;
long dist_interval = 1000;

void distancesensor_setup(){}
void distancesensor_loop(){
  unsigned long curMillis = millis();

  if(curMillis - dist_prevMillis >=dist_interval){
    dist_prevMillis = curMillis;

    dist_inputVal = analogRead(distsensor_pin);
    dist_outputVal = map(dist_inputVal, 0, 1023, 0, 255);
    for(int i = 0; i < 3; i++)
      analogWrite(distsensor_ledPin[i], dist_outputVal);
  }
}
