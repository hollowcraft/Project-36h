#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>
#include "DHT.h"

rgb_lcd lcd;
Servo servo;

const int pinA0 = A0;
const int pin2 = 2;
const int pin4 = 4;
const int pin7 = 7;
const int buzzerPin = 8;
const int pinPresence = 4;

bool alarme = true;  // Doit être modifiable, donc pas "const"
DHT dht(pinA0, DHT11);  // Création du DHT11

const int note[] = {900, 750};

float temp = 24;
float humi = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(pinA0, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin4, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinPresence, INPUT);
  servo.attach(10);
  Serial.begin(9600);
}

void playNote(const int notes[], int length) {
  for (int i = 0; i < length; i++) {
    tone(buzzerPin, notes[i]);
    for (int j = 1; j < 4000; j += 8) {
      Serial.println(j);
      tone(buzzerPin, j);
    }
    for (int j = 1; j < 4000; j += 8) {
      Serial.println(j);
      tone(buzzerPin, 4000 - j);
    }
    delay(500);
    noTone(buzzerPin);
    delay(100);
  }
}

void loop() {
  TakeValue();  // Met à jour temp et humi
  Test();

  // Affichage LCD
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

  // Affichage Serial
  Serial.println("-");
  Serial.print("Température : ");
  Serial.println(temp);
  Serial.print("Humidité : ");
  Serial.println(humi);

  // Capteur de présence
  if (digitalRead(pinPresence) && alarme) {
    Serial.println("Il y a quelqu'un !");
    if (alarme) {
      playNote(note, sizeof(note) / sizeof(note[0]));
    }
  } else {
    Serial.println("Tout est calme");
  }

  // Servo test
  servo.write(0);
  delay(2000);
  servo.write(90);
  delay(1000);
}

void TakeValue() {
  float valDht[2] = {0};
  if (!dht.readTempAndHumidity(valDht)) {
    temp = valDht[0];
    humi = valDht[1];
  } else {
    Serial.println("Erreur lecture DHT !");
  }
}

void Turn(int angle) {
  int y;
  if (angle == 0) {
    y = 1;
  } else {
    y = -1;
  }

  int z = 45 + 45 * y;

  for (int x = angle; x < z; x += y) {
    servo.write(90 - x);
    delay(5);
  }
}

void Test() {
  temp = temp + random(0,2)-1;
  humi = humi + random(0,2)-1;
}
