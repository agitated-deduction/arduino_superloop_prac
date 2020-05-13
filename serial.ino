#define Serial Serial2
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void showMenu() {
  Serial.println("\033[2J\033[H");
  Serial.println("1. Led Blink Enable/Disable");
  Serial.println("2. Led Fading Enable/Disable");
  Serial.println("3. RGB Led Blink Enable/Disable");
  Serial.println("4. RGB Led Fading Enable/Disable");
}

void serial_setup() {  
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Hello, world!");
  
  
  Serial.begin(115200);
  
  showMenu();
}

int userCmd = 0;

void serial_loop() {
  if (Serial.available() > 0) {
    userCmd = Serial.read();

    switch(userCmd) {
      case '1': blink_en = !blink_en; 
        lcd.clear(); 
        lcd.home(); 
        lcd.print("1.blink");
        lcd.setCursor(0,1);
        blink_en?lcd.print("Enable"):lcd.print("Disable");          
        break;
      case '2': 
        fading_en = !fading_en; 
        lcd.clear(); 
        lcd.home(); 
        lcd.print("2.fading");        
        lcd.setCursor(0,1);
        fading_en?lcd.print("Enable"):lcd.print("Disable");  
        break; 
      case '3': blinkRGB_en = !blinkRGB_en; lcd.clear(); lcd.home(); lcd.print("3.blinkRGB");   
        lcd.setCursor(0,1);
        blinkRGB_en?lcd.print("Enable"):lcd.print("Disable");  
        break;
      case '4': fadingRGB_en = !fadingRGB_en; lcd.clear(); lcd.home(); lcd.print("4.fadingRGB");
        lcd.setCursor(0,1);
        fadingRGB_en?lcd.print("Enable"):lcd.print("Disable");
        break;
      default: break;
    }
  }
}
