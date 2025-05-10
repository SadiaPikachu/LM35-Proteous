#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define LM35 A0 // LM35 temperature sensor connected to A0

void setup() {
  pinMode(LM35, INPUT); 
  Serial.begin(9600); 
  lcd.clear();
  lcd.begin(16, 2); 
  lcd.print("Temperature:"); 
  delay(500); 
}

void loop() {
  int sensorValue = analogRead(LM35); 
  float voltage = sensorValue * (5.0 / 1023.0); 
  float temperature = voltage * 100.0; 

  // Categorizing temperature (You can comment out this portion if temperature categorization is not necessary)
  String tempCategory = "";
  if (temperature >= 0 && temperature <= 15.99) {
    tempCategory = "Status : Too Cold";
  } else if (temperature >= 16 && temperature <= 23.99) {
    tempCategory = "Status : Cool";
  } else if (temperature >= 24 && temperature <= 32.99) {
    tempCategory = "Status : Normal";
    } else if (temperature >= 33 && temperature <= 50.99) {
    tempCategory = "Status : Hot";
  } else {
    tempCategory = "Status : Too Hot";
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:"); 
  lcd.print(temperature); 
  lcd.print((char)223); 
  lcd.print("C");
  lcd.setCursor(0, 1); // can comment
  lcd.print(tempCategory); // can comment
  

  // Display on Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C,Status: "); // can comment
  Serial.println(tempCategory); // can comment

  delay(1000); 
}
