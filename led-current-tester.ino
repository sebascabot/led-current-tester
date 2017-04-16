#include "configuration.h"

int values[5] = { 0, 1, 100, 0, 0 };
int printedValues[5] = { 0, 0, 0, 0, 0 };

unsigned int row2color[5] = { 0, WHITE, RED, GREEN, BLUE };

byte focusRow = COUNT_ROW; // Initial row with the focus

void setup(void) {
  Serial.begin(9600);

  initTouchpad();
  initOledScreen();
  initLed();
}

void loop() {
  checkKeypad();
}

void onKeyPress (byte key) {
  if (key <= 4) {
    if (focusRow != key) {
      drawLabelFocus(focusRow, BACKGROUND); // Erase
      focusRow = key;
      drawLabelFocus(key, YELLOW);
    }
  }

  if (key == 7) {
    decreaseFocusValue(1);
  }

  if (key == 5) {
    increaseFocusValue(1);
  }

  if (key == 8) {
    decreaseFocusValue(5);
  }

  if (key == 9) {
    increaseFocusValue(5);
  }

  if (key == 10) {
    increaseFocusValue(25);
  }

  if (key == 13) {
    decreaseFocusValue(25);
  }

  if (key == 11) {
    increaseFocusValue(10);
  }

  if (key == 12) {
    decreaseFocusValue(10);
  }

  if (key == 14) { // Set to min (0)
    setFocusValue(0, 0);
  }

  if (key == 6) { // Set to mid values
    setFocusValue(150, 128);
  }

  if (key == 15) { // Set to max
    setFocusValue(NUM_LEDS, 255);
  }

  Serial.print("Pad #");
  Serial.print(key, DEC);
  Serial.println(" Pressed");
}

void onKeyRelease (byte key) {
  Serial.print("Pad #");
  Serial.print(key, DEC);
  Serial.println(" Released");
}

void setFocusValue (int countValue, int rgbValue) {
  if (focusRow == COUNT_ROW) {
    values[focusRow] = countValue;
  } else {
    values[focusRow] = rgbValue;
  }
  drawLabelValue(focusRow);
  refreshLed();
}

void decreaseFocusValue(int amount) {
  if (values[focusRow] < amount) {
    if (focusRow == COUNT_ROW) {
      values[focusRow] += NUM_LEDS;
    } else {
      values[focusRow] += 255;
    }
  }
  values[focusRow] -= amount;

  drawLabelValue(focusRow);
  refreshLed();
}

void increaseFocusValue(int amount) {
  values[focusRow] += amount;
  if (focusRow == COUNT_ROW) {
    if (values[focusRow] > NUM_LEDS) {
      values[focusRow] %= NUM_LEDS;
    }
  } else {
    if (values[focusRow] > 255) {
      values[focusRow] %= 255;
    }
  }

  drawLabelValue(focusRow);
  refreshLed();
}

