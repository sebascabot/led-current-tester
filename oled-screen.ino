// RGB OLED Section
// -----------------

#include "configuration.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

#define RADIUS 3
#define ROW_WIDTH 44
#define ROW_HEIGHT 13
#define ROW_PADDING 3
#define LEFT_PADDING 8
#define TEXT_X_OFFSET 5
#define TEXT_Y_OFFSET 3

void initOledScreen() {
  display.begin();
  
  Serial.println("Begin FillScreen ...");
  display.fillScreen(BACKGROUND);
  Serial.println("End FillScreen");

  drawLabel(COUNT_ROW, "#: ");
  drawLabel(RED_ROW,   "R: ");
  drawLabel(GREEN_ROW, "G: ");
  drawLabel(BLUE_ROW,  "B: ");

  drawLabelFocus(focusRow, YELLOW);

  drawLabelValue(COUNT_ROW);
  drawLabelValue(RED_ROW);
  drawLabelValue(GREEN_ROW);
  drawLabelValue(BLUE_ROW);
}

void drawLabelFocus(byte row, unsigned int color) {


  // Left triangle
  unsigned int x1 = 0;
  unsigned int y1 = 1 + (row - 1) * (ROW_HEIGHT + ROW_PADDING);

  unsigned int x2 = 5;
  unsigned int y2 = y1 + 5;

  unsigned int x3 = 0;
  unsigned int y3 = y1 + 10;

  display.fillTriangle(x1, y1, x2, y2, x3, y3, color);
}

void drawLabelValue(byte row) {

#define FIXME 16

  unsigned int color = row2color[row];
  unsigned int textColor = (color == WHITE ? BLACK : WHITE);

  byte x = LEFT_PADDING;
  byte y = 0 + (row - 1) * (ROW_HEIGHT + ROW_PADDING);

  display.setTextSize(1);

  display.setCursor(x + TEXT_X_OFFSET + FIXME, y + TEXT_Y_OFFSET);
  display.setTextColor(color);
  display.print(String(printedValues[row], DEC));

  display.setCursor(x + TEXT_X_OFFSET + FIXME, y + TEXT_Y_OFFSET);
  display.setTextColor(textColor);
  display.print(String(values[row], DEC));

  printedValues[row] = values[row];
}

void drawLabel(byte row, char *txt) {
#define RADIUS 3
#define ROW_WIDTH 44
#define ROW_HEIGHT 13
#define TEXT_X_OFFSET 5
#define TEXT_Y_OFFSET 3
#define ROW_PADDING 3
#define LEFT_PADDING 8

  unsigned int color = row2color[row];
  unsigned int textColor = (color == WHITE ? BLACK : WHITE);

  byte x = LEFT_PADDING;
  byte y = 0 + (row - 1) * (ROW_HEIGHT + ROW_PADDING);

  display.fillRoundRect(x, y, ROW_WIDTH, ROW_HEIGHT, RADIUS, color);
  display.setCursor(x + TEXT_X_OFFSET, y + TEXT_Y_OFFSET);
  display.setTextColor(textColor);
  display.setTextSize(1);
  display.print(txt);
}
