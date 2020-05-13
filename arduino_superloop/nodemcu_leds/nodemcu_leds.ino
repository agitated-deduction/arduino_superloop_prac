const int ledESP12 = D0;
const int ledNodeMCU = D4;
const int ON = LOW;
const int OFF = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledESP12, OUTPUT);
  pinMode(ledNodeMCU, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledESP12, ON);
  digitalWrite(ledNodeMCU, ON);
  delay(1000);
  digitalWrite(ledESP12, OFF);
  digitalWrite(ledNodeMCU, OFF);
  delay(1000);
}
