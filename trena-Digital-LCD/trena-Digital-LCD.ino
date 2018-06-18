#include <LiquidCrystal.h>
LiquidCrystal lcd(3,4,11,10,9,8);

#include <Ultrasonic.h>
Ultrasonic ultrasonic(7,6); //define the name of sensor and set the pins -> trig(8) and echo(7) respectively
int distance=0;
int readValue=0;

void setup() {
  lcd.begin(20,4);
  lcd.setCursor(4,0);
  lcd.print("Trena Digital");
  lcd.setCursor(3,1);
  lcd.print("Liga Embarcados");
  lcd.setCursor(4,3);
  lcd.print("Medida:");

  Serial.begin(9600); //serial comumnication 9600 bauds rates.
}

void loop() {
  readValue = ultrasonic.Ranging(CM);//return the distance in CM
 
  distance = readValue;
  lcd.setCursor(14,3);
  Serial.print(distance);
  Serial.print("\n");
  lcd.print(distance);    
  lcd.setCursor(17,3);
  lcd.print("cm");
  delay(3000);
  

}
