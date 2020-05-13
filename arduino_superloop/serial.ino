//#include<SoftwareSerial.h>

//SoftwareSerial bluetooth(18,19);
void showMenu(){
  Serial.println("\033[2J\033[H");
  Serial.println("1. LED Blink Enable/Disable");
  Serial.println("2. LED Fading Enable/Disable");
  Serial.println("3. RGB LED Blink Enable/Disable");
  Serial.println("4. RGB LED Fading Enable/Disable");
  //bluetooth.println("\033[2J\033[H");
  /*bluetooth.println("1. LED Blink Enable/Disable");
  bluetooth.println("2. LED Fading Enable/Disable");
  bluetooth.println("3. RGB LED Blink Enable/Disable");
  bluetooth.println("4. RGB LED Fading Enable/Disable");*/
}
void serial_setup(){
  /*???*/
  //pinMode(14, INPUT);
  //pinMode(50, OUTPUT);

  /**************/
  
  //Serial.begin(9600);
  Serial.begin(115200);
  //bluetooth.begin(9600);
 // bluetooth.println("start..");
  showMenu();
}
int userCmd = 0;
void serial_loop(){
  //char userCmd = '\0';//= bluetooth.read();
  //Serial.write(userCmd);
  if(Serial.available()>0){
    userCmd = Serial.read();
    //Serial.write(bluetooth.read());
    //userCmd = (char)bluetooth.read();
    switch(userCmd){
      case'1': blink_en = !blink_en; break;
      case '2': fading_en = !fading_en; break;
      case '3': bRGB_en = !bRGB_en; break;
      case '4': fRGB_en = !fRGB_en; break;
      default: break;
    }
  }
  
  }
