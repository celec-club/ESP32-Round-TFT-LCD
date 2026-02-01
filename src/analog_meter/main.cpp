#include <Arduino.h>
#include <TFT_eSPI.h>     // Hardware-specific library
#include <TFT_eWidget.h>  // Widget library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

MeterWidget speed = MeterWidget(&tft);

#define LOOP_PERIOD 35  // Display updates every 35 ms

float mapValue(float ip, float ipmin, float ipmax, float tomin, float tomax);

void setup(void) {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_WHITE);  // Fill screen with white background
  Serial.begin(115200);       // For debug

  // Colour zones are set as a start and end percentage of full scale (0-100)
  // If start and end of a colour zone are the same then that colour is not used
  // Example here red starts at 75% and ends at 100% of full scale
  speed.setZones(75, 100, 50, 75, 25, 50, 0, 25);
  // Meter is 239 pixels wide and 126 pixels high
  // Center on 240x240 display: X = (240-239)/2 ≈ 0, Y = (240-126)/2 = 57
  // Draw analogue meter centered vertically
  speed.analogMeter(0, 57, 2.0, "m/s", "0", "0.5", "1.0", "1.5", "2.0");
}

void loop() {
  static int d = 0;
  static uint32_t updateTime = 0;

  if (millis() - updateTime >= LOOP_PERIOD) {
    updateTime = millis();

    d += 4;
    if (d > 360) d = 0;

    // Create a Sine wave for testing, value is in range 0 - 100
    float value = 50.0 + 50.0 * sin((d + 0) * 0.0174532925);

    float speed_value;
    speed_value =
        mapValue(value, (float)0.0, (float)100.0, (float)0.0, (float)2.0);

    speed.updateNeedle(speed_value, 0);
  }
}

float mapValue(float ip, float ipmin, float ipmax, float tomin, float tomax) {
  return tomin + (((tomax - tomin) * (ip - ipmin)) / (ipmax - ipmin));
}