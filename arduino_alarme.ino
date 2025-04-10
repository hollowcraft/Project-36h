#define trigPin 13
#define echoPin 12
#define ledPin 7
#define echoPin2 6
#define trigPin2 5


void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);
 pinMode (ledPin, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 if (distance <= 10){
 tone(9,600,100);
 digitalWrite(ledPin, HIGH);
 }
 

 else {
  
 noTone(9);
 digitalWrite(ledPin, LOW);
 }


 long duration2, distance2;
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = ((duration2)/2) / 29.1;
 if (distance2 <= 10){
 tone(9,600,100);
 digitalWrite(ledPin, HIGH);
 }
 

 else {
  
 noTone(9);
 digitalWrite(ledPin, LOW);
 }
 
}
