#define Serial Serial2

int blink_en = 1;
int fading_en = 1;
int bRGB_en = 1;
int fRGB_en = 1;

void setup() {
  blink_setup();
  fading_setup();
  blinkRGB_setup();
  fadingRGB_setup();

  serial_setup();
}

void loop() {
  if(blink_en)
    blink_loop();
  if(fading_en)
    fading_loop();
  if(bRGB_en)
    blinkRGB_loop();
  if(fRGB_en)
    fadingRGB_loop();

  serial_loop();
}
