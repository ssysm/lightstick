#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial Bluetooth(rxPin, txPin); // RX, TX

void btlControl()
{
    while (Bluetooth.available() > 0)
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
            Bluetooth.flush();
        }
    }
}