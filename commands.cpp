#include<Arduino.h>
#include "screen.h"
#include "sys.h"
#include <StandardCplusplus.h>

#include <string>
#include <vector>
#include <iterator>
using namespace std;
String helpArr[10] = {"help - show help","print - print str","hangman - play game","wolf - text editor","","","","","",""};

void help()
{
  for(int i = 0; i < 4; i++)
  {
    cout(helpArr[i]);
    delay(1000);
  }
}
void sys_print(String s)
{
  //Serial.println("sys_print called");
  cout(s);
}
void hangman(String s)
{
  clearScr();
  String toShow;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == ' ') toShow += " ";
    else toShow += "_";
  };
  while(s != toShow)
  {
    clearScr();
    cout(toShow);
    ask:
    String letter = "";
    letter = cin();
    Serial.println(letter);
    if(letter.length() != 1) {
      if(letter == s)
      {
        goto won;
      }
      else { cout("Invalid input"); goto ask; }
    }
    for(int i = 0; i < s.length(); i++)
    {
      if(s[i] == letter[0])
      {
        toShow[i] = letter[0];
      }
    }
  }
  won:
  cout(s);
  cout("You won");
}
void wolf()
{
  vector<String> program;
  String tempLine;
  while(tempLine != "STOP")
  {
    tempLine = cin();
    program.push_back(tempLine);
  }
}

