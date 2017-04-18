#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// LED strip (WS2812B)

#define LED_PIN         5
#define LED_COLOR_ORDER GRB
#define LED_CHIPSET     WS2812B
#define LED_COUNT       100

// OLED Screen

#define OLED_CS   10
#define OLED_RST  9
#define OLED_DC   8
// NOTE: Arduino Hardware SPI SCLK=13 an MOSI=11 is fast, otherwise slow.
#define OLED_SCLK 13
#define OLED_MOSI 11

// Color definitions
#define OLED_BLACK            0x0000
#define OLED_BLUE             0x001F
#define OLED_RED              0xF800
#define OLED_GREEN            0x07E0
#define OLED_CYAN             0x07FF
#define OLED_MAGENTA          0xF81F
#define OLED_YELLOW           0xFFE0
#define OLED_WHITE            0xFFFF

#define OLED_BACKGROUND_COLOR 0x8888

// TouchPad (TTP229)

#define TP_TTP229 (0xAF>>1)

#define TP_KEY_COUNT     15
#define TP_DEBOUNCE_TIME 50

// Current Sensor (ACS712, aka GY-712 module)
// ±  5 Amps - ACS712ELC-05A (185 mV / Amp)
// ± 20 Amps - ACS712ELC-20A (100 mV / Amp)
// ± 30 Amps - ACS712ELC-30A ( 66 mV / Amp)

#define CS_ANALOG_IN_PIN A0
#define CS_ACS_OFFSET    2500.0
#define CS_MV_PER_AMP    185.0

// MAIN

// Default initial value
#define INIT_BRIGHTNESS 200
#define INIT_RED        25
#define INIT_GREEN      50
#define INIT_BLUE       100
#define INIT_COUNT      1

#endif
