#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 7 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 6 //Sensor Trip pin connected to Arduino pin 12

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("TeamBasurero");
  delay(2000);
  lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  lcd.print("Storage:        ");  //Print Message on First Row
}

void loop()
{
  long duration, distance;
  int percentage;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(200 );
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 74;  
  percentage = map(distance, 30, 1 , 0, 100) ;   //14 min value 4 max tas convert to 0 min to 100 max


  lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0,1);   //Set Cursor again to first column of second row
  lcd.print("Percentage: ");
  lcd.print(percentage);
  lcd.print("% "); //Print measured distance  //Print your units.
  lcd.println(" cm");
  delay(800); //pause to let things settle
}
