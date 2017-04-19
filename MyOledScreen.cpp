#include "MyOledScreen.h"

#include "configuration.h"

#define PILL_RADIUS 3
#define PILL_WIDTH 40
#define PILL_HEIGHT 13
#define PILL_TOP_PADDING 3
#define PILL_LEFT_FOCUS_SIGN_SPACE 7
#define PILL_TEXT_X_OFFSET 4
#define PILL_TEXT_Y_OFFSET 3
#define PILL_VALUE_X_OFFSET 14

MyOledScreen::MyOledScreen(uint8_t CS, uint8_t RS, uint8_t SID, uint8_t SCLK, uint8_t RST) :
  Adafruit_SSD1331(CS, RS, SID, SCLK, RST),
  Adafruit_GFX(TFTWIDTH, TFTHEIGHT)
{}

MyOledScreen::MyOledScreen(uint8_t CS, uint8_t RS, uint8_t RST) :
  Adafruit_SSD1331(CS, RS, RST),
  Adafruit_GFX(TFTWIDTH, TFTHEIGHT)
{}

unsigned int MyOledScreen::_getTextColor(unsigned int bgColor) {
  switch (bgColor) {
    case OLED_WHITE:
    case OLED_YELLOW:
      return OLED_BLACK;
    default:
      return OLED_WHITE;
  }
}

void MyOledScreen::drawPill(byte x, byte y, unsigned int bgColor, char label) {
  x = x + PILL_LEFT_FOCUS_SIGN_SPACE;

  fillRoundRect(x, y, PILL_WIDTH, PILL_HEIGHT, PILL_RADIUS, bgColor);

  setCursor(x + PILL_TEXT_X_OFFSET, y + PILL_TEXT_Y_OFFSET);
  setTextColor(_getTextColor(bgColor));
  setTextSize(1);
  print(label);
  print(':');
}

void MyOledScreen::drawPillFocus(byte x, byte y, unsigned int color) {
  // Left triangle (right pointing)
  unsigned int x1 = x;
  unsigned int y1 = y + 1;

  unsigned int x2 = x + 5;
  unsigned int y2 = y + 6;

  unsigned int x3 = x;
  unsigned int y3 = y + 11;

  fillTriangle(x1, y1, x2, y2, x3, y3, color);
}

void MyOledScreen::drawPillText(byte x, byte y, unsigned int bgColor, String text) {
  x = x + PILL_LEFT_FOCUS_SIGN_SPACE + PILL_TEXT_X_OFFSET + PILL_VALUE_X_OFFSET;
  y = y + PILL_TEXT_Y_OFFSET;

  setTextSize(1);

  setCursor(x, y);
  setTextColor(_getTextColor(bgColor), bgColor);
  print(text);
}

void MyOledScreen::drawPillFullText(byte x, byte y, unsigned int bgColor, String text) {
  x = x + PILL_LEFT_FOCUS_SIGN_SPACE + PILL_TEXT_X_OFFSET + 1;
  y = y + PILL_TEXT_Y_OFFSET;

  setTextSize(1);

  setCursor(x, y);
  setTextColor(_getTextColor(bgColor), bgColor);
  print(text);
}
