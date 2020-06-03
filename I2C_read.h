#ifndef I2C_READ_H_
#define I2C_READ_H_

#include "Arduino.h"
#include <Wire.h>

/**
 * @class Sensor Sensor.h "Sensor.h"
 * @brief A class to make finding the i2C address easier.
 *        Putting the result on the serial monitor.
 * @author Pham Minh Nhat and Bas De Quinze
 */
class I2C_read {
    public:
        I2C_read();
        ~I2C_read();
        void init(); // Initalize I2C and Serial output
        void read(); // Returns I2C address in 8 bit mode
};

#endif I2C_READ_H_
