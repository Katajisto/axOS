#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
String screenArr[4];
void clearScr()
{
  for(int i = 0; i < 4; i++)
  {
    lcd.setCursor(0,i);
    lcd.print("                      ");
  }
  lcd.setCursor(0,0);
}
void clearln(int ln)
{
  lcd.setCursor(0,ln);
  lcd.print("                    ");
}

void cout(String s)
{
  //Serial.println("PRINT ASKED FOR: ");
  //Serial.println(s);
  for(int i = 0; i < 4; i++)
  {
    if(screenArr[i] == "")
    {
      clearln(i);
      lcd.setCursor(0,i);
      lcd.print(s);
      screenArr[i] = s;
      return;
    }
  }
  for(int i = 1; i < 4; i++)
  {
    clearln(i-1);
    lcd.setCursor(0,i-1);
    lcd.print(screenArr[i]);
    screenArr[i-1] = screenArr[i]; 
  }
  clearln(3);
  lcd.setCursor(0,3);
  lcd.print(s);
  screenArr[3] = s;
}
void initscr()
{
  for(int i = 0; i < 4; i++)
  {
    screenArr[i] = "";
  }
  lcd.begin();
  lcd.backlight();
  lcd.print("Starting serial read");
  Serial.begin(115200);
  delay(500);
  clearScr();
  cout("axOS v.0.2 GNU GPL 3");
  cout("\"help\" for help.");
}


