#include "FlowSensor.h"

/**
 * @param IO: The GPIO which is connected to the data bus of the sensor.
 * @param ID: ID of the sensor, see more in Sensor
 */
FlowSensor::FlowSensor(const int IO, const int ID) : IOpin_(IO), Sensor(ID) {
  pinMode(IOpin_, INPUT);
}

int FlowSensor::Measure() {
   unsigned long previousMicros = micros();
  //Usually, it is in the middle of one period when the function is called
  //Hence, the program should wait until the next edge to start measuring the period
  int startState;
  (digitalRead(IOpin_))?(startState=0):(startState=1);
  while(digitalRead(IOpin_) != startState) { //wait until the next edge
    if (micros() >= (previousMicros + WAIT_MAX)) { //Flow is too slow to be measured
      Freq = 0.0;
      return NO_FLOW;
    }
    delayMicroseconds(1);
  }
  
  //Start measure
  previousMicros = micros();
  while(digitalRead(IOpin_) == startState) { //wait until the next edge (first half of period)
    if (micros() >= (previousMicros + WAIT_MAX)) { //Flow is too slow to be measured
      Freq = 0.0;
      return NO_FLOW;
    }
    delayMicroseconds(1);
  }
  duration = micros()-previousMicros;
  
  //Continue to measure the second half of the period
  previousMicros = micros();
  while(digitalRead(IOpin_) != startState) { //wait until the next edge (second half of period)
    if (micros() >= (previousMicros + WAIT_MAX)) { //Flow is too slow to be measured
      Freq = 0.0;
      return NO_FLOW;
    }
    delayMicroseconds(1);
  }
  duration += (micros()-previousMicros);

  // need to bufferize to avoid glitches
  _duration = duration;
  duration = 0; // clear counters

  Freq = 1e6 / float(_duration);    //Duration is in uSecond so it is 1e6 / T
  return NO_ERR;
}

float FlowSensor::getFrequency() {
  return Freq;
}
float FlowSensor::getFlow() {
  if (Freq <= 25.0) {
    return 0.0;
  }
  if (Freq <= 190.0) {
    return 15.0;
  }
  else {
    return 75.0;
  }
}
