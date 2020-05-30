#include "RegulatorValve.h"

RegulatorValve::RegulatorValve(std::vector<int> PinOut, std::vector<int> TimeON)
  : PinOut_(PinOut), TimeON_(TimeON), bitOrder(0) {
  for (auto i : PinOut_) {
    pinMode(i, OUTPUT);    
  }

  //Setup PWM
  //set timer1 interrupt at 1kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 16;// = (16*10^6) / (1000*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei(); //allow interrupt
}

void RegulatorValve::setTimeON(int PinOut, int TimeON) {
  //Find the index
  std::vector<int>::iterator it;
  it = std::find (PinOut_.begin(), PinOut_.end(), PinOut);
  int index = it - PinOut_.begin();

  TimeON_[index] = TimeON;
}

int RegulatorValve::getTimeON(int PinOut) {
  //Find the index
  std::vector<int>::iterator it;
  it = std::find (PinOut_.begin(), PinOut_.end(), PinOut);
  int index = it - PinOut_.begin();

  return TimeON_[index];
}
