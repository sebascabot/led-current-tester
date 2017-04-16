#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// LED

#define LED_PIN     5
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    100

#define BRIGHTNESS  200

// OLED Screen

#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

#define BACKGROUND 0x8888

// TouchPad

#define ttp229 (0xAF>>1)
#define KEY_COUNT 15
#define DEBOUNCE_TIME 50

// MAIN

#define COUNT_ROW 1
#define RED_ROW 2
#define GREEN_ROW 3
#define BLUE_ROW 4

#endif

