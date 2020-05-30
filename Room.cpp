#include "Room.h"

Room::Room(int ID, int DHTPin, std::vector<int> ValvePin, std::vector<int> TimeON)
  : DHTsensor_(DHTPin, ID), control_(ValvePin, TimeON) {}
