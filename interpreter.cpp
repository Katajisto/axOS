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
  std::map<String, int> mem_map;
  vector<long> int_mem;
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
    if(start == "print")
    {
      cout(line);
    }
    else if(start == "goto")
    {
      i = (line.toInt() - 2);
    }
    else if(start == "sleep")
    {
      delay(line.toInt());
    }
    else if(start == "var")
    {
      String varname = ""; 
      for(int i = 0; i < line.length(); i++)
      {
        if(line[i] == " ") break;
        varname += line[i];
      }
      line.remove(0,varname.length()+1);
      int mem_address = int_mem.size();
      int_mem.push_back(line.toInt());
      Serial.print("Varname " + varname);
      mem_map.insert(pair<String, int>(varname,mem_address));
    }
    else if(start == "print_var")
    {
      Serial.print(line);
      int mem_address = mem_map[line];
      Serial.print(mem_address);
      long variable = int_mem[mem_address];
      cout(String(variable));
    }
    else if(start == "STOP")
    {
      return;
    }
  }
}

