#include "PT100.h"

/**
 * @param adc: The analog-to-digital converter that the sensor is connected to.
 * @param channel: the channel of the ADC that the sensor is connected to.
 * @param ID: ID of the sensor, see more in Sensor
 */
PT100::PT100 (ADS1015 &adc, const int channel, const int ID)
    : ADC_(adc), channel_(channel), Sensor(ID) {
    Wire.begin();
}

/**
 * This function read value from the ADC.
 * @return NO_ERR 0 on success.
 * @return CONNECT_ERR 1 if the arduino cannot find the I2C slave.
 * @todo Calculate temperature from the resistance of PT100.
 */ 
int PT100::Measure() {
    float voltage;
    if (!ADC_.isConnected()) {
        return CONNECT_ERR;
    }
    voltage = ADC_.getSingleEnded(channel_);
	Temperature_ = (voltage-1.98)/0.007623;
    return NO_ERR;
}

/**
 * @return The latest measured result of temperature.
 */
float PT100::getTemp() const {
    return Temperature_;
}
