/**
 * NEO_6M_GPS_Sensor.h
 * Purpose: defines class NEO_6M_GPS_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */


#ifndef NEO_6M_GPS_Sensor_H
#define NEO_6M_GPS_Sensor_H

#include <random>
#include <functional>

#include "DataBuffer.h"
#include "SensorType.h"
#include "DummyValueStorage.h"

/**
 * NEO_6M_GPS_Sensor class
 * @brief The NEO_6M_GPS_Sensor class provides an implementation of readSensor() for the Sensor NEO_6M_GPS_Sensor
 *
 * The NEO_6M_GPS_Sensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the NEO_6M_GPS_Sensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class NEO_6M_GPS_Sensor : public SensorType {
    public:
        /* --- constructor / destructor --- */
        NEO_6M_GPS_Sensor(const string& name_ = "NEO_6M_GPS_Sensor");

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        std::string name;
};

#endif // NEO_6M_GPS_Sensor_H
