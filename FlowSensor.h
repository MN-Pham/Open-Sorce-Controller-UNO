#ifndef FLOWSENSOR_H_
#define FLOWSENSOR_H_

#include "Sensor.h"
#include "Arduino.h"

#define NO_ERR   0
#define NO_FLOW  1
#define WAIT_MAX 30000 //LOW limit is 20Hz -> 25000 us for a half of period, a higher number is used to stop the loop if there is no change in a long time

/**
 * @class FlowSensor FlowSensor.h "FlowSensor.h"
 * @brief Libary for Gems Electronic flow sensor.
 * @author Pham Minh Nhat and Bas De Quinze
 */
class FlowSensor : public Sensor {
  public:
    FlowSensor(const int IO, const int ID);
    int Measure()override;
    float getFrequency();
    float getFlow();
  private:
    const int IOpin_;
    volatile unsigned long duration=0; // accumulates pulse width
    unsigned long _duration=0;
    float Freq;
};

#endif FLOWSENSOR_H_
