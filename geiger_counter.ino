#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DFRobot_Geiger.h>

#if defined ESP32
#define detect_pin D3
#else
#define detect_pin 3
#endif

LiquidCrystal_I2C lcd(0x27,16, 2);
DFRobot_Geiger  geiger(detect_pin);

void setup(){
  Serial.begin(9600);

  lcd.init();                   
  lcd.backlight();

  geiger.start();
}

void loop(){ 
  lcd.clear();
  float x= geiger.getCPM();
  Serial.println(x);
  
  lcd.setCursor(0,0);
  lcd.print("CPM :");
  lcd.setCursor(0,1);
  lcd.print(x);

  //Serial.println(geiger.getnSvh());
  //Serial.println(geiger.getuSvh());
  delay(3000);
}


