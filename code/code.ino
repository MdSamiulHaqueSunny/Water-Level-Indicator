#include <LiquidCrystal.h>
int ir[] = {A0, A1, A2};
int reading[] = {0, 0, 0};

LiquidCrystal lcd(4, 5,6,7,8,9);
#define LCD_CLEAR 0b00000001

void setup(void){
  Serial.begin(9600);
  lcd.begin(16, 2);
  for (int i = 0; i < 3; i++){
    pinMode(ir[i], INPUT);
  }
}

void read(void){
  for (int i = 0; i < 3; i++){
    reading[i] = analogRead(ir[i])*30;
  }
}

void print(void){
  Serial.println(" ===== BEGIN ======== \n\n");
  read();
  Serial.println("LOW: " + String(reading[0]));
  Serial.println("MID: " + String(reading[1]));
  Serial.println("HIGH: " + String(reading[2]));
  Serial.println();
  Serial.println("======= END ======== \n\n");
  delay(1000);
}
void checkwaterlevel()
{
  
  }

void loop(void){
  print();
  lcd.setCursor(0, 0);
lcd.print("WATER LEVEL:");

}
