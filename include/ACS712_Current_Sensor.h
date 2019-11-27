/**
 * ACS712_Current_Sensor.h
 * Purpose: defines class ACS712_Current_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */


#ifndef ACS712_Current_Sensor_H
#define ACS712_Current_Sensor_H

#include <random>
#include <functional>

#include "DataBuffer.h"
#include "SensorType.h"
#include "DummyValueStorage.h"

/**
 * ACS712_Current_Sensor class
 * @brief The ACS712_Current_Sensor class provides an implementation of readSensor() for the Sensor ACS712_Current_Sensor
 * The ACS712_Current_Sensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the ACS712_Current_Sensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class ACS712_Current_Sensor : public SensorType {
    public:
        /* --- constructor / destructor --- */
        ACS712_Current_Sensor(const string& name_ = "ACS712_Current_Sensor");

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        std::string name;
};

#endif // ACS712_Current_Sensor_H
