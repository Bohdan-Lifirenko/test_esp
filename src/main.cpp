#include "Arduino.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Chip info:");

  Serial.print("Chip model: ");
  Serial.println(ESP.getChipModel());

  Serial.print("Cores: ");
  Serial.println(ESP.getChipCores());

  Serial.print("Flash size: ");
  Serial.println(ESP.getFlashChipSize());
}

void loop() {
     Serial.print("Cores: ");
     delay(1000);
}