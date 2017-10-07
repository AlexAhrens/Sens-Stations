#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);  // Pins: DIN,CLK,CS, # of Displays connected
int messwert=0; 
unsigned long delayTime=500; 
byte smile[] =
{
   B00111100,  
   B01000010,
   B10011001,
   B10100101,
   B10000001,
   B10100101,
   B01000010,
   B00111100,
};

byte frown[] =
{
   B00111100,  
   B01000010,
   B10100101,
   B10011001,
   B10000001,
   B10100101,
   B01000010,
   B00111100,
};

void setup()
{
  lc.shutdown(0,false);  // Wake up display
  lc.setIntensity(0,5);  // Set intensity level
  lc.clearDisplay(0);  // Clear Displays
  Serial.begin(9600);
}

void good()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,smile[i]);
  }
}

void bad()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,frown[i]);
  }
}

void loop()
{
    messwert=analogRead(A0);
    Serial.print("Feuchtigkeits-Messwert:");
    Serial.println(messwert);
    
if(messwert >= 200)
    {
     lc.clearDisplay(0);
     good();
    }
else
    {
     lc.clearDisplay(0);
     bad();
    }
  delay(2000);
}
