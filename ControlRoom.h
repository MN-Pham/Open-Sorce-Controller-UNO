#ifndef CONTROLROOM_H_
#define CONTROLROOM_H_

#include "RegulatorValve.h"
#include "Switch.h"
#include "DHT22.h"
#include "PT100.h"
#include "FlowSensor.h"
#include "ArduinoSTL.h"

/**
 * @class ControlRoom ControlRoom.h "Room.h"
 * @brief A control room contains valves and sensors to control the heat flow going through the house
 * @author Pham Minh Nhat and Bas De Quinze
 */
class ControlRoom {
  public:
    ControlRoom(std::vector<Switch> Switch_L, std::vector<DHT22> DHT22_L,std::vector<FlowSensor> Flow_L, std::vector<PT100> PT100_L, std::vector<int> ValvePin, std::vector<int> TimeON);
    std::vector<Switch> Switch_List;
    std::vector<DHT22> DHT22_List;
    std::vector<FlowSensor> Flow_List;
    std::vector<PT100> PT100_List;
    RegulatorValve PWM_List;
};


#endif CONTROLROOM_H_
