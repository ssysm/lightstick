void flash()
{
  setColor(255, 165, 0);
  delay(45);
  setColor(0, 0, 0);
  delay(45);
}

void rgbFade(){
  clearOutput();
  analogWrite(bPin, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

void rgbCycle()
{
  setColor(rVal, gVal, bVal);

  rVal = rVal + rDir;
  gVal = gVal + gDir;
  bVal = bVal + bDir;

  if (rVal >= 255 || rVal <= 0)
  {
    rDir = rDir * -1;
  }

  if (gVal >= 255 || gVal <= 0)
  {
    gDir = gDir * -1;
  }

  if (bVal >= 255 || bVal <= 0)
  {
    bDir = bDir * -1;
  }
  delay(13);
}
