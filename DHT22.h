#ifndef DHT22_H_
#define DHT22_H_

#include "Sensor.h"
#include "Arduino.h"

#define NO_ERR   0
#define TIME_ERR 1
#define SUM_ERR  2

#define TIME_MAX 30

/**
 * @class DHT22 DHT22.h "DHT22.h"
 * @brief Libary for DHT22 temperature and humidity sensor.
 * @author Pham Minh Nhat
 */
class DHT22: public Sensor {
    public:
        DHT22(const int IO, const int ID);
        int Measure()override;
        float getTem() const;
        float getHum() const;
    private:
        const int IOpin_;
        int16_t temperature_;
        int16_t humidity_;
        uint8_t sum_;
        uint16_t readHum();
        int16_t readTem();
        uint8_t readSum();
        bool checkSum(uint16_t h, int16_t t, uint8_t s);
};

#endif DHT22_H_
