#include "Pill.h"

#define PILL_RADIUS 3
#define PILL_WIDTH 40
#define PILL_HEIGHT 13
#define PILL_TOP_PADDING 3
#define PILL_LEFT_FOCUS_SIGN_SPACE 7
#define PILL_TEXT_X_OFFSET 4
#define PILL_TEXT_Y_OFFSET 3
#define PILL_VALUE_X_OFFSET 14


Pill::Pill(Adafruit_SSD1331 display, byte x, byte y, unsigned int color, char label, int value) : _display(display), _x(x), _y(y), _color(color), _label(label), _value(value) {
  /*nothing to create */
}

Pill::~Pill() {
  /*nothing to destroy */
}

void Pill::draw() {
  byte x = _x + PILL_LEFT_FOCUS_SIGN_SPACE;
  byte y = _y;

  _display.fillRoundRect(x, y, PILL_WIDTH, PILL_HEIGHT, PILL_RADIUS, _color);

  _display.setCursor(x + PILL_TEXT_X_OFFSET, y + PILL_TEXT_Y_OFFSET);
  _display.setTextColor(_color == WHITE ? BLACK : WHITE); // Avoid White on White
  _display.setTextSize(1);
  _display.print(_label);
  _display.print(':');
}

void Pill::focus() {
}

void Pill::update(int value) {
}

void Pill::drawFocus() {
  // Left triangle
  unsigned int x1 = _x;
  unsigned int y1 = _y + 1;

  unsigned int x2 = _x + 5;
  unsigned int y2 = _y + 6;

  unsigned int x3 = _x;
  unsigned int y3 = _y + 11;

  _display.fillTriangle(x1, y1, x2, y2, x3, y3, YELLOW);
}

void Pill::drawValue() {
  byte x = _x + PILL_LEFT_FOCUS_SIGN_SPACE + PILL_TEXT_X_OFFSET + PILL_VALUE_X_OFFSET; 
  byte y = _y + PILL_TEXT_Y_OFFSET;

  _display.setTextSize(1);

  _display.setCursor(x, y);
  _display.setTextColor(_color);
  _display.print(String(_value, DEC));

  _display.setCursor(x, y);
  _display.setTextColor(_color == WHITE ? BLACK : WHITE);
  _display.print(String(_value, DEC));
}
