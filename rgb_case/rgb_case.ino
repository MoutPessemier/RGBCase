// Written for Arduino Uno
// Just change the pins and the sketch will do the rest
// The input of the 3 turn knobs
const int potpinR = A0;
const int potpinG = A1;
const int potpinB = A2;

// The output for the 3 colors
const int red_light_pin = 11;
const int green_light_pin = 10;
const int blue_light_pin = 9;

// GND of RGB needs to connect with 5V and needs a resistor of 220 Ohm in front of the 3 RGB pins

void setup() {
  // Prepare output pins for RGB
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  // Read the 3 values
  int r = getPotentiaValue(potpinR);
  int g = getPotentiaValue(potpinG);
  int b = getPotentiaValue(potpinB);
  // Set color of LEDs
  setColor(r, g, b);
}

// reads the value of the potentiometer and maps it to an rgb value
int getPotentiaValue(int pin) {
  int val = analogRead(pin);
  val = map(val, 0, 1023, 0, 255);
  return val;
}

// Sets the color for the different RGB LEDs
void setColor(int red, int green, int blue) {
  analogWrite(red_light_pin, red);
  analogWrite(green_light_pin, green);
  analogWrite(blue_light_pin, blue);
}
