#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C OLED
#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    // Запуск I2C
    Wire.begin(OLED_SDA, OLED_SCL);

    // Адреса OLED зазвичай 0x3C
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED not found");
        while(true);
    }

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();

  display.setCursor(0, 10);
  display.println("Hello");
  display.println(" Hello");

  display.display();
  delay(10000);

  display.clearDisplay();

  display.setCursor(0, 10);
  display.println("GoodBy");
  display.println("GoodBy");

  display.display();
  delay(10000);
}