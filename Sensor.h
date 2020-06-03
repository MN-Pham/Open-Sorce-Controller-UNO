#ifndef SENSOR_H_
#define SENSOR_H_

#include "Arduino.h"

/**
 * @class Sensor Sensor.h "Sensor.h"
 * @brief The Base class for all kind of sensors.
 * If a new sensor is added, it must be the Derived class of Sensor.
 * @author Pham Minh Nhat and Bas De Quinze
 */
class Sensor {
    public:
        Sensor(const int ID);
        virtual ~Sensor();
        virtual int Measure();
        int getID () const;
    private:
        int ID_;
};

#endif SENSOR_H_
