#include "configuration.h"

#include <FastLED.h>
#include "MyOledScreen.h"
#include "Pill.h"

CRGB leds[LED_COUNT];

#if OLED_MOSI == 11 && OLED_SCLK == 13
// Arduino Hardware SPI (Faster)
MyOledScreen oledScreen = MyOledScreen(OLED_CS, OLED_DC, OLED_RST);
#else
MyOledScreen oledScreen = MyOledScreen(OLED_CS, OLED_DC, OLED_MOSI, OLED_SCLK, OLED_RST);
#endif

// TODO: build a Pill array, then work with the array
Pill brightnessPill = Pill(0, 0, OLED_WHITE, '*', 0, 255, INIT_BRIGHTNESS);
Pill redPill = Pill(0, 16, OLED_RED, 'R', 0, 255, INIT_RED);
Pill greenPill = Pill(0, 32, OLED_GREEN, 'G', 0, 255, INIT_GREEN);
Pill bluePill = Pill(0, 48, OLED_BLUE, 'B', 0, 255, INIT_BLUE);
Pill countPill = Pill(49, 0, OLED_YELLOW, '#', 0, 100, INIT_COUNT);
Pill ampPill = Pill(49, 32, OLED_BLACK, ' ', 0, 5, 0);

Pill *focusPill = &brightnessPill; // Initial pill with the focus

void setup(void) {
  Serial.begin(9600);
  Serial.println("Init Led Strip ...");

  // Init LED Strip
  Serial.println("Init Led Strip ...");
  FastLED.addLeds<LED_CHIPSET, LED_PIN, LED_COLOR_ORDER>(leds, LED_COUNT).setCorrection( TypicalLEDStrip );
  showLed();

  Serial.println("Init Touchpad ...");
  initTouchpad();

  // Init OLED Screen
  Serial.println("Init OLED Screen ...");
  oledScreen.begin();
  oledScreen.fillScreen(OLED_BACKGROUND_COLOR);

  brightnessPill.draw();
  redPill.draw();
  greenPill.draw();
  bluePill.draw();
  countPill.draw();
  ampPill.draw();

  focusPill->drawFocus(true);
}

void loop() {
  checkKeypad();

  // Update Amps measure and display the new updated value
  ampPill.drawFloat(updatedCurrentCounter());
}

void onKeyPress (byte key) {
  switch (key) {
    case 1:
      // Brightness Pill
      updateFocus(&brightnessPill);
      break;

    case 2:
      // Red Pill
      updateFocus(&redPill);
      break;

    case 3:
      // Green Pill
      updateFocus(&greenPill);
      break;

    case 4:
      // Blue Pill
      updateFocus(&bluePill);
      break;

    case 6:
      // Count Pill
      updateFocus(&countPill);
      break;

    // ± 1
    case 5:
      focusPill->increaseValueBy(1);
      break;
    case 7:
      focusPill->decreaseValueBy(1);
      break;

    // ± 5
    case 9:
      focusPill->increaseValueBy(5);
      break;
    case 8:
      focusPill->decreaseValueBy(5);
      break;

    // ± 10
    case 11:
      focusPill->increaseValueBy(10);
      break;
    case 12:
      focusPill->decreaseValueBy(5);
      break;

    // ± 25
    case 10:
      focusPill->increaseValueBy(25);
      break;
    case 13:
      focusPill->decreaseValueBy(25);
      break;

    // Set Min/Max
    case 14: // Min
      focusPill->setValueToMinimum();
      break;
    case 15: // Max
      focusPill->setValueToMaximum();
      break;
  }

  showLed();

  Serial.print("Pad #");
  Serial.print(key, DEC);
  Serial.println(" Pressed");
}

void onKeyRelease (byte key) {
  Serial.print("Pad #");
  Serial.print(key, DEC);
  Serial.println(" Released");
}

void updateFocus(Pill *targetPill) {
  if (focusPill != targetPill) {
    focusPill->drawFocus(false);
    focusPill = targetPill;
    focusPill->drawFocus(true);
  }
}

void showLed() {
  CRGB myColor = CRGB(redPill.getValue(), greenPill.getValue(), bluePill.getValue());
  int myCount = countPill.getValue();

  FastLED.setBrightness(brightnessPill.getValue());

  for (int i = 0; i < LED_COUNT; i += 1) {
    leds[i] = (i < myCount ? myColor : CRGB::Black);
  }

  FastLED.show();

  // FIXME: A delay is require prior reset, in order to get more acurate reading
  resetCurrentCounter(); // New measure, reset the counter
}
