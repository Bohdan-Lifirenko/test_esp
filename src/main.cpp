#include "Arduino.h"

#define TIMER_ONE 1000
#define TIMER_TWO 2000

void Task1(void *pvParameters);
void Task2(void *pvParameters);

unsigned long lastPrint1 = 0;  // для змінної 1 (1 раз в секунду)
unsigned long lastPrint2 = 0;  // для змінної 2 (2 рази в секунду)

int variable1 = 0;
int variable2 = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  xTaskCreate(Task1, "Task1", 1024, NULL, 1, NULL);
  xTaskCreate(Task2, "Task2", 1024, NULL, 1, NULL);
}

void loop() {
  
}

void Task1(void *pvParameters) {
  while (1)
  {
    lastPrint1 = millis();
    variable1++;

    Serial.print("Variable 1: ");
    Serial.println(variable1);

    delay(TIMER_ONE);
  }
  
}

void Task2(void *pvParameters) {
  while (1)
  {
    lastPrint2 = millis();
    variable2++;

    Serial.print("Variable 2: ");
    Serial.println(variable2);

    delay(TIMER_TWO);
  }
  
}