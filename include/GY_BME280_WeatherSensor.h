/**
 * GY_BME280_WeatherSensor.h
 * Purpose: defines class GY_BME280_WeatherSensor
 *
 * @author mezorian
 * @version 1.0.0
 */


#ifndef GY_BME280_WeatherSensor_H
#define GY_BME280_WeatherSensor_H

#include <random>
#include <functional>

#include "DataBuffer.h"
#include "SensorType.h"
#include "DummyValueStorage.h"

/**
 * GY_BME280_WeatherSensor class
 * @brief The GY_BME280_WeatherSensor class provides an implementation of readSensor() for the Sensor GY_BME280_WeatherSensor
 *
 * The GY_BME280_WeatherSensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the GY_BME280_WeatherSensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class GY_BME280_WeatherSensor : public SensorType {
    public:
        /* --- constructor / destructor --- */
        GY_BME280_WeatherSensor(const string& name_ = "GY_BME280_WeatherSensor");

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        std::string name;
};

#endif // GY_BME280_WeatherSensor_H
