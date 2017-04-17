#include "Pill.h"

#include "configuration.h"
#include "MyOledScreen.h"

extern MyOledScreen oledScreen;

Pill::Pill(byte x, byte y, unsigned int color, char label, int min, int max, int value) :
  _x(x), _y(y), _color(color), _label(label), _min(min), _max(max), _value(value)
{}

void Pill::draw() {
  oledScreen.drawPill(_x, _y, _color, _label);
  setValue(_value);
}

void Pill::drawFocus(boolean isFocus) {
  unsigned int color = isFocus ? OLED_YELLOW : OLED_BACKGROUND_COLOR;
  oledScreen.drawPillFocus(_x, _y, color);
}

int Pill::getValue() {
  return _value;
}

void Pill::setValue(int value) {
  _value = value;

  String padding = ""; // 3 digit value (no padding)
  if (value < 100) {
    padding += " ";    // 2 digit value (add one padding => 1 left digit padding)
  }
  if (value < 10) {
    padding += " ";    // 1 digit value (add one padding => 2 left digit padding)
  }

  oledScreen.drawPillText(_x, _y, (_color == OLED_WHITE ? OLED_BLACK : OLED_WHITE), _color, padding + _value);
}

void Pill::setValueToMinimum() {
  setValue(_min);
}

void Pill::setValueToMaximum() {
  setValue(_max);
}

void Pill::increaseValueBy(int amount) {
  setValue(min(_max, _value + amount));
}

void Pill::decreaseValueBy(int amount) {
  setValue(max(_min, _value - amount));
}


