#include "ControlRoom.h"

ControlRoom::ControlRoom(std::vector<Switch> Switch_L,
                         std::vector<DHT22> DHT22_L,
                         std::vector<FlowSensor> Flow_L,
                         std::vector<PT100> PT100_L,
                         std::vector<int> ValvePin, std::vector<int> TimeON)
  : Switch_List(Switch_L), DHT22_List(DHT22_L), Flow_List(Flow_L), PT100_List(PT100_L),
    PWM_List(ValvePin, TimeON) {}
