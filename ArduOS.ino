#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "screen.h"
#include "cmdhandler.h"
#include "sys.h"
void setup()
{ 
  initscr();
}
void loop()
{
  //Get commands from serial, then pass them to a C++ fucntion.
   initSerial();
   String cmd = cin();
   cout(cmd);
   cmdHandler(cmd);
}
