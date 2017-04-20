#ifndef PILL_H
#define PILL_H

#include <Arduino.h>

class Pill {
  private:

    // FIXME: Find why this is not working ?
    // static Pill *_focus;

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
    void shiftValueBy(int amount);

    // Special: Only draw (overwrite the whole pill). No value store/update.
    void drawFloat(float value);
};

#endif

