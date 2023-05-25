#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int aqsensor = 18;  //output of mq135 connected to A0 pin of Arduino
//int threshold = 250;      //Threshold level for Air Quality

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.cursor_off();

  pinMode (aqsensor,INPUT); // MQ135 is connected as INPUT to arduino
  Serial.begin (9600);      //begin serial communication with baud rate of 9600
  delay(1000);
}

void loop() {

  int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A0 and store it in ppm
  Serial.print("CO2: ");  //print message in serail monitor
  Serial.println(ppm);            //print value of ppm in serial monitor
  lcd.setCursor(4,0);             // set cursor of lcd to 1st row and 1st column
  lcd.print("CO2: ");      // print message on lcd
  lcd.print(ppm);                 // print value of MQ135
  lcd.setCursor(13,0);
  lcd.print(" ppm");                 // print value of MQ135
  char state;
  
  if (ppm < 400)           
    {
      lcd.setCursor(2,1);      
      lcd.print("Air Q: ");
      lcd.setCursor(9,1);
      lcd.print("          ");
      lcd.setCursor(9,1);
      lcd.print("GOOD");
      Serial.println("Air Q: GOOD");     
    }
  else if(ppm >= 400 && ppm < 1000)
    {
      //digitalWrite(led,LOW);   //jump here if ppm is not greater than threshold and turn off LED
      //digitalWrite(buz,LOW);   //Turn off Buzzer
      lcd.setCursor(2,1);      
      lcd.print("Air Q: ");
      lcd.setCursor(9,1);
      lcd.print("          ");
      lcd.setCursor(9,1);       
      lcd.print("MEDIUM");
      Serial.println("Air Q: MEDIUM");  
    }
  else if(ppm >= 1000 & ppm < 2000)
    {
      lcd.setCursor(2,1);      
      lcd.print("Air Q: ");
      lcd.setCursor(9,1);
      lcd.print("          ");
      lcd.setCursor(9,1);    
      lcd.print("MODERATE");
      Serial.println("Air Q: MODERATE");
    }
  else 
  {
      lcd.setCursor(2,1);      
      lcd.print("Air Q: ");
      lcd.setCursor(9,1);
      lcd.print("          ");
      lcd.setCursor(9,1);    
    lcd.print("SERIOUS");
    Serial.println("Air Q: SERIOUS");
  }
  delay (1000);
}