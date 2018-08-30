#include "include.h"

void setup()
{
    Bluetooth.begin(9600);
    Serial.begin(115200);

    pinMode(rPin, OUTPUT);
    pinMode(gPin, OUTPUT);
    pinMode(bPin, OUTPUT);

    pinMode(btnPin, INPUT_PULLUP);

    selfCheck();
}

void loop()
{
  buttonHandler();
}

void buttonHandler(){
    if (digitalRead(btnPin) == LOW) {

    if (buttonActive == false) {

      buttonActive = true;
      buttonTimer = millis();

    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {

      longPressActive = true;
      handleLongPress();
      Serial.print("Button state:");
      Serial.print(millis());
      Serial.print("Button Timer:");
      Serial.println(buttonTimer);
    }

  } else {

    if (buttonActive == true) {

      if (longPressActive == true) {

        longPressActive = false;
        Serial.println("Deactivate Long");
      } else {
         handleShortPress();
     }

      buttonActive = false;

    }else{
      if(isClear==false){
        modeSelect();
      }
    }

  }
}

void handleShortPress(){
    Serial.println("Short Activated");
    mode++;
    isClear = false;
    modeSelect();
}

void handleLongPress(){
    Serial.println("Long Activated");
    clearOutput();
    isClear = true;
    mode -= 1;
}
