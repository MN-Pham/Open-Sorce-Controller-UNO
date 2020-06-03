#ifndef SWITCH_H_
#define SWITCH_H_

#include "Arduino.h"

/**
 * @class Switch Switch.h "Switch.h"
 * @brief A simple on/off switch.
 * @author Pham Minh Nhat and Bas De Quinze
 */
class Switch {
  public:
    Switch(int IOpin);
    int CurrentState();
    void On();
    void Off();
  private:
    int State;
    int IOpin_;
};

#endif SWITCH_H_
