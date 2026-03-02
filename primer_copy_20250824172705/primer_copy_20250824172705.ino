#include "Leg.cpp"

Leg *rightLeg1= new Leg(7,2);
void setup() {
 Serial.begin(9600);

}


void loop() {
  (*rightLeg1).Run(millis());
}
  