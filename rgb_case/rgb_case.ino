#include <Servo.h>

// My 3 turn knobs
Servo R;
Servo G;
Servo B;

const int red_light_pin = D5;
const int green_light_pin = D6;
const int blue_light_pin = D7;

void setup() {
  // Attach the knobs to the pins
  R.attach(D0);
  G.attach(D1);
  B.attach(D2);

  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);

}

void loop() {
  int r = getServoValue(D0);
  int g = getServoValue(D1);
  int b = getServoValue(D2);
  setColor(r,g,b);
}

// reads the value of the knob and maps it to an rgb value
int getServoValue(int pin) {
  int val = analogRead(pin);
  val = map(val, 0, 1023, 0, 255);
  return val;
}

void setColor(red,green,blue) {
  analogWrite(red_light_pin, red);
  analogWrite(green_light_pin, green);
  analogWrite(blue_light_pin, blue);
}
