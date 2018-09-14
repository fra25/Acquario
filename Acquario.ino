#include <DallasTemperature.h>                                                    
#include <OneWire.h>
#include <LiquidCrystal.h>                
LiquidCrystal lcd(12,11,5,4,3,2);   
int V = 38; // ventola
int LV = 39; // led ventola
int RGB = 28; // led rgb
int LR = 29; //led riscaldatore
int R = 48; // RGB 
int ALL = 18; // allarme
int DHTP = 13; // dht arduino
int PULS = 52; // pulsante 
float TEMP;
int PULSS;
int stato = LOW;
#define ONE_WIRE_BUS 46 // sonda ds18b20
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);  
  sensors.begin(); 
  pinMode(V,OUTPUT);
  pinMode(LV,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(LR,OUTPUT);
  pinMode(RGB,OUTPUT);
  pinMode(ALL,OUTPUT);
  pinMode(PULS,INPUT );
  digitalWrite(V,LOW);
  digitalWrite(R,LOW);
  digitalWrite(RGB,LOW);
  digitalWrite(ALL,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(LV,LOW);
}
void loop (){
 // lcd.setCursor(0,0);
 //lcd.print("Temp.:");
  lcd.setCursor(6,0);
  lcd.print(TEMP);
 //lcd.setCursor(11,0);
 //lcd.print(" C.");
  if (digitalRead(PULS) == HIGH){
    stato= !stato;
  }
  if (stato == HIGH){
    digitalWrite(RGB,LOW);
  }
  else
  digitalWrite(RGB,HIGH);

  if (Serial.read() == 'c'){
      Serial.print("Temperatura Acquario: ");
      Serial.println(TEMP);   
    }
  sensors.requestTemperatures();
  delay(2200); 
  TEMP = (sensors.getTempCByIndex(0));
  if ((TEMP < 24)&(TEMP != -127))
  {
    digitalWrite(R,LOW);
    digitalWrite(LR,HIGH);
    digitalWrite(ALL,LOW);
  }
  else 
  {
    digitalWrite(R,HIGH);
    digitalWrite(LR,LOW);
    digitalWrite(ALL,HIGH);
  }
  
  if ((TEMP > 26.5)&(TEMP != -127))
  {
    digitalWrite(V,HIGH);
    digitalWrite(LV,HIGH);
    digitalWrite(ALL,LOW);
  }
  else
  {
    digitalWrite(V,LOW);
    digitalWrite(LV,LOW);
    digitalWrite(ALL,HIGH);
  }
}  
