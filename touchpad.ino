#include "configuration.h"

#include <Wire.h>

unsigned long keyPressed[KEY_COUNT]; // In milli
unsigned int keyPress = 0; // One bit for each button

void initTouchpad() {
  Serial.println("Wire begin ...");
  Wire.begin();
}

void checkKeypad () {
  static boolean pendingRequest = false;

  if (!pendingRequest) {
    Wire.requestFrom(ttp229, 2, true);
    pendingRequest = true;
  }

  if (Wire.available()) {
    processKeyEvent();
    pendingRequest = false;
  }
}

void processKeyEvent () {
  unsigned int data;
  unsigned long now;

  // Read the 16 bit TouchPad data input (one bit per pad)
  data = Wire.read();
  data <<= 8;
  data |= Wire.read();

  if (keyPress == 0 && data == 0) {
    return; // Nothing to do. No button pressed and no transition
  }

  now = millis();

  // Call Press/Release hadler for each button with debouncing

  for (byte key = 0; key < KEY_COUNT; key += 1) {
    unsigned int padBit = 1 << (15 - key);
    int before = keyPressed[key];

    if (data & padBit) { // Pad Touch

      if (!before) {
        keyPress |= padBit;
        keyPressed[key] = now;

        // Trigger a press
        onKeyPress(key + 1); // Map 0-15 => 1-16
      }
    } else { // Pad Untouch
      if (before && (now - before > DEBOUNCE_TIME)) {
        keyPress &= padBit;
        keyPressed[key] = 0;

        // Trigger release
        onKeyRelease(key + 1); // Map 0-15 => 1-16
      }
    }
  }
}
