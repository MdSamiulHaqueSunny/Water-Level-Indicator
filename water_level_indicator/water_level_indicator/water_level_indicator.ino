#include "NewPing.h"
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

#define MAX_DISTANCE 400

LiquidCrystal lcd(4, 5,6,7,8,9);
#define LCD_CLEAR 0b00000001



void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
   Serial.println("Serial initialized");
    delay(3000);
}


int Distance;

NewPing Sonar(13, 12, MAX_DISTANCE);


void updateDistance()
{
   Serial.println("Updating distances: ");
    Distance = Sonar.ping() / US_ROUNDTRIP_CM;
    
}
void printdistance()
{
 Serial.println("Front: " + String(Distance) + " cm");
delay(500);
  }

void loop()
{
  updateDistance();
  printdistance();
  lcd.setCursor(0, 0);
lcd.print("WATER LEVEL:"+String(Distance)+" " +"CM");
if(Distance<3)
{
 lcd.setCursor(0, 1);
lcd.print("FULL"); 
  }
  else if(Distance>3&&Distance<8)
  {lcd.setCursor(0, 1);
lcd.print("MIDDLE");
    }
  else if(Distance>8)
  {lcd.setCursor(0, 1);
lcd.print("LOW");
    }
}
