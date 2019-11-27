/**
 * WaterTank_Status_Sensor.h
 * Purpose: defines class WaterTank_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */


#ifndef WaterTank_Status_Sensor_H
#define WaterTank_Status_Sensor_H

#include <random>
#include <functional>

#include "DataBuffer.h"
#include "SensorType.h"
#include "DummyValueStorage.h"

/**
 * WaterTank_Status_Sensor class
 * @brief The WaterTank_Status_Sensor class provides an implementation of readSensor() for the Sensor WaterTank_Status_Sensor
 *
 * The WaterTank_Status_Sensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the WaterTank_Status_Sensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class WaterTank_Status_Sensor : public SensorType {
    public:
        /* --- constructor / destructor --- */
        WaterTank_Status_Sensor(const string& name_ = "WaterTank_Status_Sensor");

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        std::string name;
};

#endif // WaterTank_Status_Sensor_H
