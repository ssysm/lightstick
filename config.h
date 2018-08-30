//RGB Pin
#define rPin 9
#define gPin 11
#define bPin 10
//Bluetooth Module Pin
#define rxPin 6
#define txPin 5
//Pull down button pin
#define btnPin 4
//Mode counter
int mode = 0;
//Button
long buttonTimer = 0;
long longPressTime = 2000;

boolean buttonActive = false;
boolean longPressActive = false;

boolean isClear = false;

//RGB cycle
int rVal = 254;
int gVal = 1;
int bVal = 127;
int rDir = -1;
int gDir = 1;
int bDir = -1;

//RGB fade
int brightness = 0;
int fadeAmount = 5;
