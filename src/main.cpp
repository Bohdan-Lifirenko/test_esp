#include "Arduino.h"

unsigned long lastPrint1 = 0;  // для змінної 1 (1 раз в секунду)
unsigned long lastPrint2 = 0;  // для змінної 2 (2 рази в секунду)

int variable1 = 10;
int variable2 = 20;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  unsigned long currentTime = millis();
  
  // Вивести змінну 1 (кожну 1000мс = 1 раз в секунду)
  if (currentTime - lastPrint1 >= 1000) {
    Serial.print("Variable 1: ");
    Serial.println(variable1);
    lastPrint1 = currentTime;
  }
  
  // Вивести змінну 2 (кожну 500мс = 2 рази в секунду)
  if (currentTime - lastPrint2 >= 500) {
    Serial.print("Variable 2: ");
    Serial.println(variable2);
    lastPrint2 = currentTime;
  }
}