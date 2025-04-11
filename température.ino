#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

rgb_lcd lcd;
Servo servo;  // Créer un objet Servo

const int pinA0 = A0;
const int pin2 = 4;

void setup() {
  lcd.begin(16, 2);  // Initialisation de l'écran
  pinMode(pinA0, INPUT);  // Configurer le capteur comme une entrée
  pinMode(pin2, INPUT);  // Configurer le bouton comme une entrée
  servo.attach(10);
  Serial.begin(9600);  // Initialiser la communication série
}

void loop() {
  float temp = analogRead(pinA0);  // Lire la valeur analogique du capteur
  int Value = random(0, 50);
  int Value2 = random(0, 50);
  float humi = random(0, 50);
  temp = temp / 65 + Value / 50.0;
  humi = temp * 1.1 + humi / 60 + (Value2 - 25) / 80;

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

  servo.write(0);  // Positionner le servo à 0 degrés
  delay(2000);
  servo.write(90);  // Positionner le servo à 90 degrés
  delay(1000);
  servo.write(180);  // Positionner le servo à 180 degrés
  delay(1000);

}
