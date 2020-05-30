#ifndef PT100_H_
#define PT100_H_

#include "Arduino.h"
#include "SparkFun_ADS1015_Arduino_Library.h"
#include "Wire.h"
#include "Sensor.h"

#define NO_ERR      0
#define CONNECT_ERR 1

/**
 * @class PT100 PT100.h "PT100.h"
 * @brief Libary for PT100 analog temperature sensor.
 * The value is read using 12-bit ADC ADS1015 from SparkFun.
 * @author Pham Minh Nhat
 */
class PT100 : public Sensor {
    public:
        PT100(ADS1015 &adc, const int channel, const int ID);
        int Measure() override;
        float getTemp() const;
    private:
        float Temperature_;
        ADS1015 &ADC_;
        const int channel_;
};

#endif PT100_H_
