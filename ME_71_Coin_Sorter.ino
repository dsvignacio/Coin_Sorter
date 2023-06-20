#include <Servo.h>
Servo servo_ramp;

void setup() {
  servo_ramp.attach(9);
}

void loop() {
  servo_ramp.write(90);
}
