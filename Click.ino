#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int pinA0 = A0;

void setup() {
  lcd.begin(16, 2);  // Initialisation de l'écran
  pinMode(pinA0, INPUT);  // Configurer le capteur comme une entrée
  Serial.begin(9600);  // Initialiser la communication série
}

void loop() {
  float temp = analogRead(pinA0);  // Lire la valeur analogique du capteur
  int randomValue = random(0, 50);
  int randomValue2 = random(0, 50);
  float humi = random(0, 50);
  temp = temp / 65 + randomValue / 50.0;
  humi = temp*1.1 + humi/60 + (randomValue2-25)/80;
  
  // Afficher les informations sur le LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humi:");
  lcd.setCursor(6, 1);
  lcd.print(humi);
  lcd.print(" %");

  // Écrire la température dans la console
  Serial.println("-");
  Serial.println(temp);
  Serial.println(humi);
  delay(5000);
}
