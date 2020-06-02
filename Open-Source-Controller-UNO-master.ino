//#include "PT100.h"
//#include "RegulatorValve.h"
#include "FlowSensor.h"
#include "Wire.h"

#define LED1 6
#define LED2 7

uint8_t timeON_1 = 255;
uint8_t timeON_2 = 050;

FlowSensor flowsensor(2, 002);
//ADS1015 adcSensor;
//PT100 sensor1(adcSensor, 2, 001);
//RegulatorValve valve({LED1, LED2},{timeON_1, timeON_2});

//ISR(TIMER1_COMPA_vect) {
//
//  for (auto i : valve.PinOut_) {
//    std::vector<int>::iterator it;
//    it = std::find ((valve.PinOut_).begin(), (valve.PinOut_).end(), i);
//    int index = it - (valve.PinOut_).begin();
//    if (valve.TimeON_[index] & (1<<valve.bitOrder)) {
//      digitalWrite(i, HIGH);
//    }
//    else {
//      digitalWrite(i, LOW);  
//    }
//  }
//
//  if (valve.bitOrder==7) {
//    valve.bitOrder = 0;
//  }
//  else {
//    valve.bitOrder++;
//  }
//
//  OCR1A = valve.MAXcount[valve.bitOrder];
//  TCNT1 = 0;
//}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
//  if (adcSensor.begin(0x48) == true) {
//    Serial.println("Device found. I2C connections are good.");
//  }
//  else {
//    Serial.println("Device not found. Check wiring.");
//    while (1); // stall out forever
//  }
}

void loop() {
  // put your main code here, to run repeatedly:
//  sensor1.Measure();
//  Serial.print("Value: ");
//  Serial.println(sensor1.getTemp());
    flowsensor.Measure();
    Serial.print("Value:");
    Serial.println(flowsensor.getFrequency());
    Serial.println(flowsensor.getFrequency());
    Serial.print("Flow:");
    Serial.println(flowsensor.getFlow());
  delay(250);
}
