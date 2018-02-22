
#include <Arduino.h>
#include "commands.h"
#include "screen.h"
#include "interpreter.h"
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
  if(command == "help")
  {
    help();
  }
  if(command == "print")
  {
    //Serial.println("TRIED TO CALL SYS_PRINT");
    sys_print(cmd);
  }
  if(command == "hangman")
  {
    hangman(cmd);
  }
  if(command == "wolf")
  {
    wolf();
  }
  if(command == "wolftest")
  {
    vector<String> testprg;
    testprg.push_back("PRINT HELLO WORLD");
    testprg.push_back("GOTO 1");
    testprg.push_back("DELAY 100");
    system_run(testprg);
  }
}
