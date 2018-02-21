#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "screen.h"
#include "cmdhandler.h"
void setup()
{ 
  initscr();
}

void loop()
{
  while(Serial.available())
  {
    String cmd;
    cmd = Serial.readString();
    cout(cmd);
    cmdHandler(cmd);
  }
}
