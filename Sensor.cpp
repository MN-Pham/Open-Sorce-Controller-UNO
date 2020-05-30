#include "Sensor.h"

/**
 * @param ID: Each sensor must have an unique ID
 */
Sensor::Sensor(const int ID) : ID_(ID) {
    //Serial.begin(9600);
    //Serial.println("A sensor has been declared!");
}

Sensor::~Sensor() {};

int Sensor::getID() const {
    return ID_;
}