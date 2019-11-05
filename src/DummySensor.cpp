/**
 * DummySensor.cpp
 * Purpose: implements class DummySensor
 *
 * @author mezorian
 */

#include "DummySensor.h"


/**
 * DummySensor::readSensor
 * @brief readSensor() returns the current temperature measured by the temperature-sensor
 * @return a Databuffer which contains temperature value in degree celsius, measured by the temperature-sensor
 */
DataBuffer DummySensor::readSensor() {
    // randomize
    srand(time(NULL));

    DataBuffer result;
    result.dataSource = "WeatherStation";
    result.useDataSource = true;

    result.data["Lufttemperatur_2m"] = rand() % 50;

    return result;
}
