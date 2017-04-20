#include "configuration.h"

float ampMean = 0;
float ampCount = 0;

unsigned long resetRequest = 0;

float updatedCurrentCounter() {

  if (resetRequest && millis() > resetRequest) {
    resetRequest = 0;

    ampMean = 0;
    ampCount = 0;
  }

  int rawValue = analogRead(CS_ANALOG_IN_PIN);
  float voltage = (rawValue / 1024.0) * 5000; // Gets you mV
  float amps = ((voltage - CS_ACS_OFFSET) / CS_MV_PER_AMP);

  // KLUDGE! I do not know how to calibrate de the value
  //         Most of the time we are between 10 mA an 15 mA above Fluke multimeter reading.
  amps = amps - 0.0125; // Minus 12.5 mA

  ampCount += 1;
  ampMean = (ampMean * (ampCount - 1) / ampCount) + (amps / ampCount);

  /*
    static unsigned long before = millis();

    unsigned long now = millis();
    if (now - before > 250) { // in Milli
      before = now;

      Serial.print("Raw Value = " );  // shows pre-scaled value
      Serial.print(rawValue);
      Serial.print("\t mV = ");       // shows the voltage measured
      Serial.print(voltage, 3);       // 3 digits after decimal point
      Serial.print("\t Amps = ");     // shows the current measured
      Serial.println(amps, 3);        // 3 digits after decimal point
    }

  */
  return ampMean;
}

void resetCurrentCounter() {
  // Strategy to offset the reset by 2 sec,
  // since near the moment of the reset Amp reading is not reliable
  resetRequest = millis() + RESET_DELAY_MS;

  ampMean = 0;
  ampCount = 0;
}
