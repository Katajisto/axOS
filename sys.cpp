#include <Arduino.h>
void initSerial()
{
  Serial.begin(115200);
}
String cin()
{
  String s = ""; 
  while(!Serial.available())
  {
    //Wait for it to become avaiable.
  }
  while(Serial.available())
  {
    s = Serial.readString();
  }
  return s;
}

