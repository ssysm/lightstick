/**
 * Set color method
 * take R, G, B value and apply to pwm pin
 **/
void setColor(int red, int green, int blue) {
  analogWrite(rPin, red);
  analogWrite(gPin, green);
  analogWrite(bPin, blue);
}
/**
 * Clear output pin color set
 * pull LED pin to DOWN state
 **/
void clearOutput() {
  digitalWrite(rPin, 0);
  digitalWrite(gPin, 0);
  digitalWrite(bPin, 0);
}
/**
 * Init boot check
 **/
void selfCheck() {
  setColor(255, 0, 0);
  delay(500);
  setColor(0, 255, 0);
  delay(500);
  setColor(0, 0, 255);
  delay(500);
  clearOutput();
}
