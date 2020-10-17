#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);//initialize the LCD Library w.r.t. RS,E,D4,D5,D6,D7
int GAS_SENSOR_LOW=3;
int GREEN_LED=5;
int RED_LED=4;
void setup() {
  // put your setup code here, to run once:
pinMode (GAS_SENSOR_LOW, INPUT_PULLUP);//configure pin3 as input and enable the internal pull-up resistor
pinMode (GREEN_LED,OUTPUT);//configure pin4 as output
pinMode (RED_LED,OUTPUT);//configure pin3 as output
lcd.begin(20,4);// set up the LCD's number of columns and rows
lcd.setCursor(0,0);//set cursor to column0 and row1
lcd.print ("SISTEM PENDETEKSI");//Print a message to the LCD.
lcd.setCursor(0,1);// set cursor to column0 and row1
lcd.print("ALKOHOL");// Print a message to the LCD.
lcd.setCursor(0,2);// set cursor to column0 and row2
lcd.print("TELEKOMUNIKASI PNJ");// Print a message to the LCD.
delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  int GAS_SENSOR_LOW_READ=digitalRead(GAS_SENSOR_LOW);//read the pushbutton value into a variable
  if (GAS_SENSOR_LOW_READ==LOW)//read PIN 3 as LOW PIN
{
  lcd.clear();
  lcd.setCursor(0, 3);//set cursor to column0 and row2
  lcd.print("ALKOHOL DETECTED");//print a message to the LCD
  digitalWrite(GREEN_LED,HIGH);//High PIN 5
  digitalWrite(RED_LED,LOW);//Low PIN 4
  delay(20);
}
else//oterwise
{
  lcd.clear();
  lcd.setCursor(0, 3);//set cursor to column0 and row3
  lcd.print("ALKOHOL NOT DETECTED");//print a message to the LCD
   digitalWrite(RED_LED,HIGH);//High PIN 5
   digitalWrite(GREEN_LED,LOW);//Low PIN 4
   delay(20);
}
}
