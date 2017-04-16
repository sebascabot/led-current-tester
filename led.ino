#include <FastLED.h>

#include "configuration.h"

CRGB leds[NUM_LEDS];

void initLed() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  FastLED.show();
}

void refreshLed() {

  for (int i = 0; i < values[COUNT_ROW]; i += 1) {
    leds[i] = CRGB(values[RED_ROW], values[GREEN_ROW], values[BLUE_ROW]);
  }

  for (int i = values[COUNT_ROW]; i < NUM_LEDS; i += 1) {
    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();
}

