#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "system.h"
String helpArr[10] = {"help - show help","print - print str","","","","","","","",""};


void help()
{
  for(int i = 0; i < 2; i++)
  {
    cout(helpArr[i]);
    delay(1000);
  }
}
void cmdHandler(String cmd)
{
  if(cmd == "help")
  {
    help();
  }
  if(cmd == "PRINT")
  {
  }
  
}
void setup()
{ 
  initscr();
  // Initializing the lcd.

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
