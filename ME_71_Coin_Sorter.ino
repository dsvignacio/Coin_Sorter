#include <Servo.h>

Servo servo_plate;
Servo servo_ramp;

/* Angles
default: 90 (gitna)
reject: 0 (right)
accept: 180 (left)
*/

void setup() {
  Serial.begin(9600);
  servo_plate.attach(9);
  servo_plate.write(90);
}

void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);

  // servo_plate.write(180);
  // Serial.println("180");
  // delay(1000);

  servo_plate.write(90);
  Serial.println("90");
  delay(1000);

  // servo_plate.write(0);
  // Serial.println("0");
  // delay(1000);

  // servo_plate.write(90);
  // Serial.println("90");
  // delay(1000);


  // for (angle = 0; angle <= 180; angle += 1) { // goes from 0 degrees to 180 degrees
  //   servo_plate.write(angle);              // tell servo to go to angleition in variable 'angle'
  //   delay(15);                       // waits 15 ms for the servo to reach the angleition
  // }
  // for (angle = 180; angle >= 0; angle -= 1) { // goes from 180 degrees to 0 degrees
  //   servo_plate.write(angle);              // tell servo to go to angleition in variable 'angle'
  //   delay(15);                       // waits 15 ms for the servo to reach the angleition
  // }
}

/*
======================================================================================================================
Logic Flow/Pseudocode:
  once an object has been detected on the receiving platform, the sorting mechanism must begin automatically
  sense weight by load cell
  sense magnetic properties by hall effect sensor
  create coin database --> determine if object is coin or not based on standard weights of 0.25, 5, and 20 peso coin
  
  if coin{
    use green LED to indicate
    rotate servo_plate and servo_ramp to proper coin bin
    add coin value to sum
  } else{
    use red LED to indicate
    rotate servo_plate to reject bin
  }

Special stuff:
  Placing a coin/object on the receiving area while sorting/storing is taking place
    i. The machine may either wait for the current sorting; or
    ii. The machine may stop and send out an error signal; or
    iii. Sort the new coin/object at the same time (harder)

  reset button to reset total coin value
======================================================================================================================
*/