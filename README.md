# RGB LED Current Tester

Arduino sketch of a setup use to measure current consumption of WS2812B led

## Library to install (Must be install in Arduino)

- [FastLed][11]
- [Adafruit GFX][9]
- [Adafruit SSD1331][8]

## The hardware Setup

- Arduino UNO R3
- Capacitive touch pad (15 key) with TTP229 module
- OLED RGB Screen
- RGB LED strip of 300 × ws2812b
- ACS712 Current Sensors aka GY-712, model: 5A ACS712ELCTR-05B

### Component: RGB LED Strip — ws2812b

This setup has been build to measure current consumption and behavior of a 300
RGB LED strip of ws2812b. In order to drive the LED, the [FastLED][10] library
is used.

### Component: Current sensor — ACS712 ±5A

The datasheet [ACS712 - Allegro Microsystems][1]

The Arduino code I used: [How to use the ACS712 with an Arduino | Henry's Bench][2]


### Component: Touch Pad — TTP229 with Capacitive Touch Pad

I used a [16 Keys Capacitive touch TTP229 I2C module][3] in combinaison
with [Capacitive Touch Disk Pad][5].

My starting point was the code in the [Document Section of the TTP229][4].

### Component: 0.95" RGB OLED Screen

I used [0.95" RGB OLED Display with driver chip SSD1331][6] with the printed
WaveShare logo on the back.

I have taken a quick look at the [SSD1331 driver chip documentation][7], but I
only use the [Adafruit SSD1331 library][8] to make it work, no need to read the
doc. 

[1]: http://www.allegromicro.com/~/media/Files/Datasheets/ACS712-Datasheet.ashx
[2]: http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/the-acs712-current-sensor-with-an-arduino/
[3]: http://robotdyn.com/catalog/capacitive/16_keys_capacitive_touch_ttp229_i2c_module/
[4]: http://robotdyn.com/catalog/capacitive/16_keys_capacitive_touch_ttp229_i2c_module/#documentation
[5]: http://robotdyn.com/catalog/capacitive/capacitive_touch_disk_pad/
[6]: http://www.waveshare.com/0.95inch-rgb-oled-b.htm
[7]: http://www.waveshare.com/w/upload/c/c7/SSD1331.pdf
[8]: https://github.com/adafruit/Adafruit-SSD1331-OLED-Driver-Library-for-Arduino
[9]: https://github.com/adafruit/Adafruit-GFX-Library
[10]: http://fastled.io/
[11]: https://github.com/FastLED/FastLED

