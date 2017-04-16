#include "configuration.h"

int values[6] = { 0, 255, 100, 0, 0, 1 };
int printedValues[6] = { 0, 0, 0, 0, 0, 0 };

unsigned int row2color[6] = { 0, WHITE, RED, GREEN, BLUE, MAGENTA };

byte focusRow = BRIGHTNESS_ROW; // Initial row with the focus

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
  if (key == 1) {
    if (focusRow != BRIGHTNESS_ROW) {
      drawLabelFocus(focusRow, BACKGROUND); // Erase
      focusRow = BRIGHTNESS_ROW;
    }
  }

  if (key >= 2 && key <= 4) { // Assumption: RGB keys map to R/G/B_ROW idx
    if (focusRow != key) {
      drawLabelFocus(focusRow, BACKGROUND); // Erase
      focusRow = key;
      drawLabelFocus(key, YELLOW);
    }
  }

  if (key == 6) { // Set to mid values
    if (focusRow != COUNT_ROW) {
      drawLabelFocus(focusRow, BACKGROUND); // Erase
      focusRow = COUNT_ROW;
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


  if (key == 15) { // Set to max
    setFocusValue(LED_COUNT, 255);
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
  showLed();
}

void decreaseFocusValue(int amount) {
  values[focusRow] -= amount;
  if (values[focusRow] < amount) {
    if (focusRow == COUNT_ROW) {
      values[focusRow] = 0;
    } else {
      values[focusRow] = 0;
    }
  }

  drawLabelValue(focusRow);
  showLed();
}

void increaseFocusValue(int amount) {
  values[focusRow] += amount;
  if (focusRow == COUNT_ROW) {
    if (values[focusRow] > LED_COUNT) {
      values[focusRow] = LED_COUNT;
    }
  } else {
    if (values[focusRow] > 255) {
      values[focusRow] = 255;
    }
  }

  drawLabelValue(focusRow);
  showLed();
}

