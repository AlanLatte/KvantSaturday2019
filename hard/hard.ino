#define analogAmperage A0
#define Led_ 7
#define Tmblr_ A1
#include <stdlib.h>
bool switch_ = true;

void setup() {
  Serial.begin(9400);
  pinMode(Led_, OUTPUT);

}

void loop() {
  int Tmblr = analogRead(Tmblr_);  
  if (Tmblr == 0) {
    switch_ = !switch_;
  }
  float resistance = 3.25;
  short int analogOfAmperage;
  float voltageOf_AS;
  float amperage;
  analogOfAmperage  = analogRead(analogAmperage);                     // Считываем значения с аналогового порта для датчика тока. (ДТ)
  voltageOf_AS      = ( 5 / 1024.0 ) * analogOfAmperage;              // Формула для расчёта напряжения c ДТ.
  amperage          = (voltageOf_AS / resistance);   // Формула для расчёта силы тока. (V/R)
  if (switch_) {
    digitalWrite(Led_, HIGH);
    Serial.println(amperage);
  } else {
    digitalWrite(Led_, LOW);
    Serial.println(voltageOf_AS);
  }
  delay(1000);
}
