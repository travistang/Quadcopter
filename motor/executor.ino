#include <Servo.h>

const int POWER_HIGH = 2500;
const int POWER_LOW  = 1000;
const int MOTOR_PINS[4] = {3,5,6,9};
Servo motor[4];

const int analogReadPin = 19;

int data = POWER_HIGH,temp = 0;
int val = 0;
bool calibrated = false;

void setAllSpeed(int val) {
  for(int i = 0; i < 4; i++) {
    motor[i].writeMicroseconds(val);
  }
}
void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 4; i++) {
    motor[i].attach(MOTOR_PINS[i]);
  }
  setAllSpeed(data);
}

void loop() {
  val = analogRead(A0);
  val = map(val,0,1023,POWER_LOW,POWER_HIGH);
  Serial.println(val,DEC);
  setAllSpeed(val);
}