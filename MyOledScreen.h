#ifndef MYOLEDSCREEN_H
#define MYOLEDSCREEN_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

class MyOledScreen : public Adafruit_SSD1331 {
  private:

    unsigned int _getTextColor(unsigned int bgColor);

  public:

    MyOledScreen(uint8_t CS, uint8_t RS, uint8_t SID, uint8_t SCLK, uint8_t RST);
    MyOledScreen(uint8_t CS, uint8_t RS, uint8_t RST); // Hardware SPI (Fast)

    void drawPill(byte x, byte y, unsigned int bgColor, char label);
    void drawPillFocus(byte x, byte y, unsigned int color);
    void drawPillText(byte x, byte y, unsigned int bgColor, String text);
    void drawPillFullText(byte x, byte y, unsigned int bgColor, String text);
};

#endif

