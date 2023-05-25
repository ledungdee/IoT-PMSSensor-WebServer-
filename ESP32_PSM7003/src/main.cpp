#include <Arduino.h>
#include "PMS.h"
#include <HardwareSerial.h>
#include <Wire.h>
PMS pms(Serial2);
PMS::DATA data;

void setup()
{
  Serial.begin(9600); 
  Serial2.begin(9600); 
}

void loop()
{

  if (pms.read(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);
    Serial.println(data.PM_SP_UG_1_0);
    Serial.println(data.PM_SP_UG_2_5);
    Serial.println(data.PM_SP_UG_10_0);

    Serial.println();
  }
}