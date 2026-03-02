int echoPin = 2; 
int trigPin = 3; 
int Firstzamer = 0;
void setup() { 
    int Firstzamer = 0;
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    Firstzamer = pulseIn(echoPin, HIGH); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(6,OUTPUT);
} 
 
void loop() { 
    int duration, cm; 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH); 
    if (duration > Firstzamer){
      digitalWrite(6,1);
      delay(10000);
      digitalWrite(6,0);






    }
    delay(1000);
}