#include <Arduino.h>
char default_num[13] = {'+', '8', '4', '9', '6', '7', '9', '9', '2', '2', '9', '8' };
void send_SMS(String sms);
void GSM_Init();
void setup() {
  Serial.begin(9600);
  delay(3000);
  send_SMS("Chao Anh Le Van Dung");
}
void loop() {
  //updateSerial();
}

void send_SMS(String sms)
{
  Serial.print("AT+CMGS=\"");
  Serial.print(default_num);
  Serial.println("\"");
  delay(200);
  Serial.print(sms); //text content
  Serial.write(26);
}

void GSM_Init(){
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(100);
  Serial.println("AT&W");
  delay(100);
}