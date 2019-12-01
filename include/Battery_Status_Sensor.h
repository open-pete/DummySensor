/**
 * Battery_Status_Sensor.h
 * Purpose: defines class Battery_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */


#ifndef Battery_Status_Sensor_H
#define Battery_Status_Sensor_H

#include <random>
#include <functional>

#include "DataBuffer.h"
#include "SensorType.h"
#include "DummyValueStorage.h"

/**
 * Battery_Status_Sensor class
 * @brief The Battery_Status_Sensor class provides an implementation of readSensor() for the Sensor Battery_Status_Sensor
 *
 * The Battery_Status_Sensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the Battery_Status_Sensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class Battery_Status_Sensor : public SensorType {
    public:
        /* --- constructor / destructor --- */
        Battery_Status_Sensor(const string& name_ = "Battery_Status_Sensor");

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        std::string name;
};

#endif // Battery_Status_Sensor_H
