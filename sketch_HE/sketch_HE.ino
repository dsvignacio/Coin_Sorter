/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int HS_A = A1;   // select the input pin for the potentiometer
int HS_D = 2; // Hall sensor is connected to the D2 pin
int LED = 13; // onboard LED pin

void setup() {
  Serial.begin(9600);
  pinMode(HS_D, INPUT); // Hall Effect Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
}

void loop() {
  // read the value from the sensor:
  int sensorStatus = digitalRead(HS_D); // Check the sensor status
  int sensorValue = analogRead(HS_A);
  Serial.println(sensorValue);
  delay(100);
  
  if (sensorStatus == 1){
    digitalWrite(LED, HIGH); // LED on
  } else {
    digitalWrite(LED, LOW); // LED off
  }
}
