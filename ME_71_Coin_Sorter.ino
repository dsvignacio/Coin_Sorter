#include <Servo.h>
Servo servo_ramp;

void setup() {
  servo_ramp.attach(9);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  servo_ramp.write(90);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

/*
Logic Flow/Pseudocode:
  once an object has been detected on the receiving platform, the sorting mechanism must begin automatically
  sense weight by load cell
  sense magnetic properties by hall effect sensor
  create coin database --> determine if object is coin or not based on standard weights of 0.25, 5, and 20 peso coin
  
  if coin{
    use green LED to indicate
    rotate servo_ramp to proper coin bin
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
*/