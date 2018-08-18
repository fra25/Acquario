// (dht),ventola,riscaldatore,led rgb,lcd,allrme,pulsante.
// LCD RS pin to digital pin 12
// LCD Enable pin to digital pin 11
// LCD D4 pin to digital pin 5
// LCD D5 pin to digital pin 4
// LCD D6 pin to digital pin 3
// LCD D7 pin to digital pin 2
// Fan Relè connect to pin 38
// Fan's led connect to pin 39
// Heater connect to pin 48
// Heater's led connect to pin 49
// RGB led connect to pin 28
// Allarm relè connect to pin 18
// Dht pin connnect to pin 13
// Puls's pin connect to pin 20
#include <DallasTemperature.h>                                                    
#include <OneWire.h>
#include <LiquidCrystal.h>                
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    
int V = 38; // ventola
int LV = 39; // led ventola
int RGB = 28; // led rgb
int LR = 29; //led riscaldatore
int R = 48; // RGB 
int ALL = 18; // allarme
int DHTP = 13; // dht arduino
int PULS = 20; // pulsante 
int PULSS ;
int TEMP;
#define ONE_WIRE_BUS 46 // sonda ds18b20
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire); 
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);  
  sensors.begin(); 
  pinMode(V,OUTPUT);
  pinMode(LV,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(LR,OUTPUT);
  pinMode(RGB,OUTPUT);
  pinMode(ALL,OUTPUT);
  pinMode(PULS,OUTPUT);
  digitalWrite(V,HIGH);
  digitalWrite(R,HIGH);
  digitalWrite(RGB,HIGH);
  digitalWrite(ALL,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(LV,LOW);
}
void loop (){
  lcd.setCursor(0,1);
  lcd.print("Temperatura = ");
  sensors.requestTemperatures();
  delay(2200); 
  TEMP = (sensors.getTempCByIndex(0));
  lcd.setCursor(0,2);
  lcd.print(TEMP);
  Serial.println(TEMP);
  if ((TEMP < 24)&(TEMP != -127))
  {
    digitalWrite(R,LOW);
    digitalWrite(LR,HIGH);
    digitalWrite(ALL,LOW);
  }
  else 
  {
  digitalWrite(R,HIGH);
  digitalWrite(LR,LOW );
  digitalWrite(ALL,HIGH);
  }
  
  if ((TEMP > 26.5)&(TEMP != -127))
  {
    digitalWrite(V,LOW);
    digitalWrite(LV,HIGH);
    digitalWrite(ALL,LOW);
  }
  else
  {
  digitalWrite(V,HIGH);
  digitalWrite(LV,LOW);
  digitalWrite(ALL,HIGH);
  }
  
  PULSS = digitalRead(PULS);
  if (PULSS = HIGH){
    digitalWrite(RGB,HIGH);
  }
  else 
  digitalWrite(RGB,LOW);
}  
