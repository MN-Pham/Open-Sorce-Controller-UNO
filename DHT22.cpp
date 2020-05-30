#include "DHT22.h"

/**
 * @param IO: The GPIO which is connected to the data bus of the sensor.
 * @param ID: ID of the sensor, see more in Sensor
 */
DHT22::DHT22(const int IO, const int ID) : IOpin_(IO), Sensor(ID) {
    pinMode(IOpin_, INPUT);
}

/**
 * @return The lastest measured result of temperature.
 */
float DHT22::getTem() const {
    return float(temperature_)/10;
}

/**
 * @return The latest measured result of humidity.
 */
float DHT22::getHum() const {
    return float(humidity_)/10;
}

/**
 * This function sends request signal to the sensor and receive data.
 * @return NO_ERR 0 on success.
 * @return TIME_ERR 1 if there is no response from the sensor.
 * @return SUM_ERR 2 if the check sum is wrong.
 */
int DHT22::Measure() {
    int timeCount=0;
    delay(500);
    pinMode(IOpin_, OUTPUT);
    digitalWrite(IOpin_, LOW);
    delay(1);
    pinMode(IOpin_, INPUT);
    while (digitalRead(IOpin_)) {
        if (timeCount==TIME_MAX)
            break;
        delayMicroseconds(1);
        timeCount++;
    }
    if (timeCount==TIME_MAX) {
        return TIME_ERR;
    }
    else {
        while (!digitalRead(IOpin_)) {;}
        while (digitalRead(IOpin_)) {;}

        humidity_=readHum();
        temperature_=readTem();
        sum_=readSum();
    }
    if (checkSum(humidity_, temperature_, sum_))
        return NO_ERR;
    else
        return SUM_ERR;
}

/**
 * This function converts binary string received from DHT22 to humidity value.
 * @return 10*Humidity value.
 */
uint16_t DHT22::readHum() {
  uint16_t h=0;
  for (int i=0; i<16; i++)
  {
    while(!digitalRead(IOpin_)){;}
    delayMicroseconds(30);
    if (digitalRead(IOpin_))
      h = (h<<1)|(0x01);
    else
      h = (h<<1);
    while(digitalRead(IOpin_)){;}
  }
  return h;
}

/**
 * This function converts binary string received from DHT22 to temperature value.
 * @return 10*Temperature value.
 */
int16_t DHT22::readTem()
{
  int16_t t=0;
  for (int i=0; i<16; i++)
  {
    while(!digitalRead(IOpin_)) {;}
    delayMicroseconds(30);
    if (digitalRead(IOpin_))
      t = (t<<1)|(0x01);
    else
      t = (t<<1);
    while(digitalRead(IOpin_)) {;}
  }
  return t;
}

/**
 * This function read the check sum string from the DHT22.
 * @return 8-bit check sum value.
 */
uint8_t DHT22::readSum()
{
  uint8_t s=0;
  for (int i=0; i<8; i++)
  {
    while(!digitalRead(IOpin_)) {;}
    delayMicroseconds(30);
    if (digitalRead(IOpin_))
      s = (s<<1)|(0x01);
    else
      s = (s<<1);
    while(digitalRead(IOpin_)) {;}
  }
  return s;
}

/**
 * This function compare calculated checksum with received chechsum.
 * @return true if two value are the same.
 */
bool DHT22::checkSum(uint16_t h, int16_t t, uint8_t s)
{
  if (((h/256 + h%256 + t/256 + t%256)%256) == s) //Get 8 last bits of the sum
    return true;
  else
    return false;
}
