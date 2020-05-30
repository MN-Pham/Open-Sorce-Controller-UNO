#ifndef REGULATORVALVE_H_
#define REGULATORVALVE_H_

#include "ArduinoSTL.h"
#include "Arduino.h"

extern "C" void TIMER1_COMPA_vect(void) __attribute__((interrupt));

class RegulatorValve {    
  public:
    /**
       This class claims TIMER1 on arduino UNO to create PWM signal.
       There must be maximum one RegulatorValve object in a main()
       @param PinOut: an array of PWM output pin
       @param TimeON: When TimeON=0, the output is always LOW
                           TimeON=255, the output is always HIGH
       Duty cycle of PinOut[n] = 100*TimeON[n]/255 (%)
    */
    RegulatorValve(std::vector<int> PinOut, std::vector<int> TimeON);
    void setTimeON(int PinOut, int TimeON);
    int getTimeON(int PinOut);
    friend void TIMER1_COMPA_vect(void);
  protected:
    int bitOrder;
    std::vector<int> PinOut_;
    std::vector<int> TimeON_;
    uint8_t MAXcount[8] = {16, 32, 48, 64, 80, 96, 112, 128};
};

#endif REGULATORVALVE_H_
