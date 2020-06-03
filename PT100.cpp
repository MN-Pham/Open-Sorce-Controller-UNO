#include "PT100.h"

/**
 * @param adc: The analog-to-digital converter that the sensor is connected to.
 * @param channel: the channel of the ADC that the sensor is connected to.
 * @param ID: ID of the sensor, see more in Sensor
 */
PT100::PT100 (ADS1015 &adc, const int channel, const int ID)
    : ADC_(adc), channel_(channel), Sensor(ID) {
    Wire.begin();
    ADC_.setGain(ADS1015_CONFIG_PGA_1); // PGA gain set to 1, max=4.096V
}

/**
 * This function read value from the ADC and calculate the temperature.
 * @return NO_ERR 0 on success.
 * @return CONNECT_ERR 1 if the arduino cannot find the I2C slave.
 */ 
int PT100::Measure() {
    float voltage;
    if (!ADC_.isConnected()) {
        return CONNECT_ERR;
    }
    //signed 12 bit -> max count = 2047
    //voltage = 4.096/2047 * result
    voltage = (ADC_.getSingleEnded(channel_)*4.096)/2047.0;
    Temperature_ = (voltage-1.98)/0.007623;
    //Temperature_=voltage;
    return NO_ERR;
}

/**
 * @return The latest measured result of temperature.
 */
float PT100::getTemp() const {
    return Temperature_;
}
