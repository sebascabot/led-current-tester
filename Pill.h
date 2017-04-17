#ifndef PILL_H
#define PILL_H

#include <Arduino.h>

class Pill {
  private:
  
    byte _x;
    byte _y;
    unsigned int _color;
    char _label;
    int _min;
    int _max;
    int _value;

  public:
    Pill(byte x, byte y, unsigned int color, char label, int min, int max, int value);

    void draw();
    void drawFocus(boolean isFocus);
    int getValue();
    
    // Following method, redraw after the change
    void setValue(int value);
    void setValueToMinimum();
    void setValueToMaximum();
    void increaseValueBy(int amount);
    void decreaseValueBy(int amount);

};

#endif

