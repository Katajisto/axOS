#include<Arduino.h>
#include "screen.h"
String helpArr[10] = {"help - show help","print - print str","","","","","","","",""};

void help()
{
  for(int i = 0; i < 2; i++)
  {
    cout(helpArr[i]);
    delay(1000);
  }
}
