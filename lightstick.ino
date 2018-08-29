#include "header.h"
#include "helper.h"
#include "animation.h"
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(rxPin, txPin); // RX, TX

void setup()
{
    Bluetooth.begin(9600);
    Serial.begin(9600);

    pinMode(rPin, OUTPUT);
    pinMode(gPin, OUTPUT);
    pinMode(bPin, OUTPUT);

    pinMode(btnPin, INPUT_PULLUP);

    selfCheck();
}

void loop()
{
    if (digitalRead(btnPin) == LOW)
    {
        buttonHandler();
    }
    else
    {
        //Run animation thing in loop
        modeSelect();
    }
}


void buttonHandler()
{
    if (digitalRead(btnPin) == LOW)
    {
        if (buttonActive == false)
        {
            buttonActive = true;
            buttonTimer = millis();
        }
        if ((millis() - buttonTimer > longPressTime) && (longPressActive == false))
        {
            longPressActive = true;
            //long Press
            handleLongPress();
        }
    }
    else
    {
        if (buttonActive == true)
        {
            if (longPressActive == true)
            {
                longPressActive = false;
            }
            else
            {
                //Short Press;
                handleShortPress();
            }
            buttonActive = false;
        }
    }
}


void handleShortPress()
{
    mode++;
    modeSelect();
}

void handleLongPress()
{
    clearOutput();
    mode -= 1;
}

void bltControl()
{
    setColor(0, 0, 255);
    delay(25);
    setColor(0, 0, 0);
    setColor(0, 0, 255);
    delay(25);
    setColor(0, 0, 0);
    while ((Bluetooth.available() > 0))
    {
        int redInt = Bluetooth.parseInt();
        int greenInt = Bluetooth.parseInt();
        int blueInt = Bluetooth.parseInt();
        redInt = constrain(redInt, 0, 255);
        greenInt = constrain(greenInt, 0, 255);
        blueInt = constrain(blueInt, 0, 255);
        if (Bluetooth.available() > 0)
        {
            setColor(redInt, greenInt, blueInt);
            Serial.print("Red: ");
            Serial.print(redInt);
            Serial.print(" Green: ");
            Serial.print(greenInt);
            Serial.print(" Blue: ");
            Serial.print(blueInt);
            Serial.println();
            Bluetooth.flush();
        }
        if (digitalRead(btnPin) == LOW)
        {
            break;
        }
    }
}



void modeSelect()
{
    switch (mode)
    {
    case 0:
        setColor(255, 0, 0);
        break;
    case 1:
        setColor(0, 255, 0);
        break;
    case 2:
        setColor(0, 0, 255);
        break;
    case 3:
        flash();
        break;
    case 4:
        rgbCycle();
        break;
    case 5:
        rgbFade();
        break;
    case 6:
        bltControl();
        break;
    default:
        mode = 0;
        modeSelect();
    }
}