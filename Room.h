#ifndef ROOM_H_
#define ROOM_H_

#include "RegulatorValve.h"
#include "DHT22.h"

/**
 * @class Room Room.h "Room.h"
 * @brief A room can have one sensor and multiple regulator valves.
 * @author Pham Minh Nhat
 */
class Room {
  public:
    Room(int ID, int DHTPin, std::vector<int> ValvePin, std::vector<int> TimeON);
    DHT22 DHTsensor_;
    RegulatorValve control_;  
};

#endif ROOM_H_
