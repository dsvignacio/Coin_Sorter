#include <Servo.h>

#define SERVO_PLATE_PIN 9
#define SERVO_RAMP_PIN 8

#define SERVO_PLATE_ACCEPT_ANGLE 180
#define SERVO_PLATE_REJECT_ANGLE 0
#define SERVO_PLATE_DEFAULT_ANGLE 90

#define SERVO_RAMP_25c_ANGLE 58
#define SERVO_RAMP_5p_ANGLE 95
#define SERVO_RAMP_20p_ANGLE 120

Servo servo_plate;
Servo servo_ramp;

int plate_accept = 0;
int plate_reject = 0;

void setup() {
  Serial.begin(9600);
  servo_plate.attach(SERVO_PLATE_PIN);
  servo_ramp.attach(SERVO_RAMP_PIN);
  servo_plate.write(SERVO_PLATE_DEFAULT_ANGLE);
  servo_ramp.write(SERVO_RAMP_5p_ANGLE);
}

void loop() {
  while (Serial.available() == 0) {
  }

  // Insert coin
  int input = Serial.parseInt();

  // Example: Accept 5 peso
  switch (input) {
    case 25:
      servo_ramp.write(SERVO_RAMP_25c_ANGLE);
      Serial.println("25 cents");
      plate_accept = 1;
      break;

    case 5:
      servo_ramp.write(SERVO_RAMP_5p_ANGLE);
      Serial.println("5 pesos");
      plate_accept = 1;
      break;

    case 20:
      servo_ramp.write(SERVO_RAMP_20p_ANGLE);
      Serial.println("20 pesos");
      plate_accept = 1;
      break;

    default:
      Serial.println("Please choose a valid selection");
      plate_reject = 1;
  }

  if (plate_accept == 1){
    for (int i = SERVO_PLATE_DEFAULT_ANGLE; i <= SERVO_PLATE_ACCEPT_ANGLE; i += 1) {
      servo_plate.write(i);
      delay(25);
    }
    for (int i = SERVO_PLATE_ACCEPT_ANGLE; i >= SERVO_PLATE_DEFAULT_ANGLE; i -= 1) {
      servo_plate.write(i);
      delay(25);
    }
  } else if (plate_reject == 1){
    for (int i = SERVO_PLATE_DEFAULT_ANGLE; i >= SERVO_PLATE_REJECT_ANGLE; i -= 1) {
      servo_plate.write(i);
      delay(25);
    }
    for (int i = SERVO_PLATE_REJECT_ANGLE; i <= SERVO_PLATE_DEFAULT_ANGLE; i += 1) {
      servo_plate.write(i);
      delay(25);
    }
  }

  plate_accept = 0;
  plate_reject = 0;
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