//RGB Pin
#define rPin 9
#define gPin 11
#define bPin 10
//Bluetooth Module Pin
#define rxPin 5
#define txPin 6
//Pull down button pin
#define btnPin 4
//Mode counter
int mode = 0;
//Button counter
long buttonTimer = 0;
long longPressTime = 500;
//Button active tracker
boolean buttonActive = false;
boolean longPressActive = false;