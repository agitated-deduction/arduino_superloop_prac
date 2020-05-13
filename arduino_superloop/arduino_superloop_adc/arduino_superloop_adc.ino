//#define Serial Serial1
#define Serial Serial2

int m1_en = 1;
int m2_en = 1;
int m3_en = 1;
int m4_en = 1;

void setup() {
  // put your setup code here, to run once:
  serial_setup();
  potentiometer_setup();
  tmp36sensor_setup();
  photosensor_setup();
  distancesensor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  serial_loop();
  if(m1_en)
    potentiometer_loop();
  if(m2_en)
    tmp36sensor_loop();
  if(m3_en)
    photosensor_loop();
  if(m4_en)
    distancesensor_loop();
}
