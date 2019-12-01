/**
 * GY_BME280_WeatherSensor.cpp
 * Purpose: implements class GY_BME280_WeatherSensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "GY_BME280_WeatherSensor.h"

/**
 * GY_BME280_WeatherSensor::readSensor
 * @brief readSensor() returns the current values for temperature, humidity and airpressure measured by the GY_BME280_WeatherSensor
 * @return a Databuffer which contains the temperature, humidity and airpressure, measured in degree celsius, in percent and in hPa by the GY_BME280_WeatherSensor
 */
GY_BME280_WeatherSensor::GY_BME280_WeatherSensor(const std::string &name_)
    : name(name_) {

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        dvs.values.insert(std::make_pair<std::string, HRand>("GY_BME280_Temperature_Value", HRand(-10.0,35.0,-0.25,0.25) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("GY_BME280_Humidity_Value", HRand(0.0,100.0,-0.25,0.25) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("GY_BME280_Airpressure_Value", HRand(800,1100.0,-2.5,2.5) ) );
    #endif
}

/**
 * GY_BME280_WeatherSensor::readSensor
 * @brief
 * @return
 */
DataBuffer GY_BME280_WeatherSensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        result.data[name + "_Temperature"] = dvs.values.at("GY_BME280_Temperature_Value").getNewValue();
        result.data[name + "_Humidity"] = dvs.values.at("GY_BME280_Humidity_Value").getNewValue();
        result.data[name + "_Airpressure"] = dvs.values.at("GY_BME280_Airpressure_Value").getNewValue();
    #elif defined REAL_VALUES
        // TODO : do some hardware magic here
        result.data[name] = 42;
    #endif

    return result;

}
