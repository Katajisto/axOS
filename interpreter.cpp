#include <StandardCplusplus.h>
#include <string>
#include <vector>
#include <iterator>
#include <arduino.h>
#include <map>
#include "sys.h"
#include "screen.h"
using namespace std;
void system_run(vector<String> programVector)
{
  for(int i = 0; i < programVector.size(); i++)
  {
    String line = programVector[i];
    String start = "";
    for(int i = 0; i < line.length(); i++)
    {
      if(line[i] == ' ') break;
      start += line[i];
    }
    line.remove(0, start.length()+1);
    if(start == "PRINT")
    {
      cout(line);
    }
    else if(start == "GOTO")
    {
      i = (line.toInt() - 2);
    }
    else if(start == "SLEEP")
    {
      delay(line.toInt());
    }
    else if(start == "STOP")
    {
      return;
    }
  }
}

