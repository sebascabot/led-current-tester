#include <FastLED.h>

#include "configuration.h"

CRGB leds[LED_COUNT];

void initLed() {
  FastLED.addLeds<LED_CHIPSET, LED_PIN, LED_COLOR_ORDER>(leds, LED_COUNT).setCorrection( TypicalLEDStrip );
  showLed();
}

void showLed() {
  FastLED.setBrightness( values[BRIGHTNESS_ROW] );
  for (int i = 0; i < LED_COUNT; i += 1) {
    if (i < values[COUNT_ROW]) {
      leds[i] = CRGB(values[RED_ROW], values[GREEN_ROW], values[BLUE_ROW]);
    } else {
      leds[i] = CRGB(0, 0, 0);
    }
  }

  FastLED.show();
}

