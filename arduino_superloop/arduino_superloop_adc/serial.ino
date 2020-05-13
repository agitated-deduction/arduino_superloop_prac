
void showMenu(){
  Serial.println("1. potentiometer Led Brightness Enable/Disbale");
  Serial.println("2. temperature sensor  LED Blink Enable/Disbale");
  Serial.println("3. photo sensor RGB Led on/off Enable/Disable");
  Serial.println("4. dist sensor RGB Led Brightness Enable/Disable");
  
}


void serial_setup(){
  //Serial.begin(9600);        //bluetooth
  Serial.begin(115200);             //wifi, serial monitor
  
  showMenu();
  
}

void serial_loop(){
  if(Serial.available()>0){
    int userCmd = Serial.read();

    switch(userCmd){
      case '1': m1_en = !m1_en; break;
      case '2': m2_en = !m2_en; break;
      case '3': m3_en = !m3_en; break;
      case '4': m4_en = !m4_en; break;
      default: break;
    }
  }
  
}
