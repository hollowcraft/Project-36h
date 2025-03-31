const int pin2 = 2;
const int pin4 = 4;

int température;
int humidité;

void setup() {
  // Initialisation des broches et du moniteur série
  pinMode(pin2, INPUT);
  pinMode(pin4, INPUT);
  Serial.begin(9600); // Démarrage de la communication série
}

void loop() {
  // Lecture des données des capteurs
  température = digitalRead(pin2);
  humidité = digitalRead(pin4);

  // Écriture des données dans le moniteur série
  Serial.print("Température: ");
  Serial.print(température);
  Serial.print(" | Humidité: ");
  Serial.println(humidité);

  delay(1000); // Attente d'une seconde avant la prochaine lecture
}
