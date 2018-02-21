
#include <Arduino.h>
#include "commands.h"
#include "screen.h"
void cmdHandler(String cmd)
{
  //Split the commmand into the command, and its argumets.
  String command;
  int amount = 0;
  for(int i = 0; i < cmd.length(); i++)
  {
    if(cmd[i] == ' ') break;
    command += cmd[i];
  }
  cmd.remove(0,command.length()+1);
  Serial.println(command);
  Serial.println(cmd);
  if(command == "help")
  {
    help();
  }
  if(command == "print")
  {
    //Serial.println("TRIED TO CALL SYS_PRINT");
    sys_print(cmd);
  }
}
