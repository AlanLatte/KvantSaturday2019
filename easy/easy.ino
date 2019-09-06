#include <stdlib.h>

#define ledInd 7
#define photoResistor A0
#define lineSensor A1
void setup() {
  Serial.begin(9600);
  pinMode(ledInd, OUTPUT);
}

void loop() {
  int phoRes = abs(analogRead(photoResistor) - 1024);
  int lineSen = abs(analogRead(lineSensor) - 1024);
  if (phoRes <= 350 && lineSen >= 1000){
    digitalWrite(ledInd, HIGH); 
    delay(5000);
  }
  else{
    digitalWrite(ledInd, LOW);
  }
}
