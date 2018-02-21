#include "screen.h"
#include <Arduino.h>
#include "commands.h"
void cmdHandler(String cmd)
{
  //Split the commmand into the command, and its argumets.
  String command;
  for(int i = 0; i < cmd.length(); i++)
  {
    if(cmd[i] == ' ') break;
    command += cmd[i];
  }
  Serial.println(command);
  if(command == "help")
  {
    help();
  }
  if(cmd == "PRINT")
  {
  }
  
}
