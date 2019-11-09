/**
 * DummySensor.cpp
 * Purpose: implements class DummySensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "DummySensor.h"

/**
 * DummySensor::readSensor
 * @brief readSensor() returns the current temperature measured by the temperature-sensor
 * @return a Databuffer which contains temperature value in degree celsius, measured by the temperature-sensor
 */
DataBuffer DummySensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES


    if (name == "GPS") {
        result.data["GPS_Longitude"] = (rand() % (maxValue+1)) + minValue;
        result.data["GPS_Latitude"] = (rand() % (maxValue+1)) + minValue;
    } else {
        result.data[name] = (rand() % (maxValue+1)) + minValue;
    }

    #elif defined REAL_VALUES
      // do some hardware magic
      result.data[name] = 42;
    #endif

    return result;

}
