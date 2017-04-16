#ifndef PILL_H
#define PILL_H

#include <Arduino.h>
#ifndef SSD1331_CMD_FILL
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1331.h>
#endif
#include "configuration.h"

class Pill {
  private:
  
    byte _x;
    byte _y;
    unsigned int _color;
    char _label;
    int _value;
    Adafruit_SSD1331 _display;

  public:
    Pill(Adafruit_SSD1331 display, byte x, byte y, unsigned int color, char label, int value);
    ~Pill();
    void draw();
    void focus();
    void update(int value);
    void drawFocus();
    void drawValue();
};

#endif

