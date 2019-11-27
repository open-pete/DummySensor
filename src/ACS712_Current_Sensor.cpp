/**
 * ACS712_Current_Sensor.cpp
 * Purpose: implements class ACS712_Current_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "ACS712_Current_Sensor.h"

/**
 * ACS712_Current_Sensor::readSensor
 * @brief readSensor() returns the current "current" in [Ampere] measured by the ACS712_Current_Sensor
 * @return a Databuffer which contains the current value in ampere, measured by the ACS712_Current_Sensor
 */
ACS712_Current_Sensor::ACS712_Current_Sensor(const std::string &name_)
    : name(name_) {

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        dvs.values.insert(std::make_pair<std::string, HRand>("ACS712_Current_Value", HRand(0.0,30.0,-0.25,0.25) ) );
    #endif
}

DataBuffer ACS712_Current_Sensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        result.data[name] = dvs.values.at("ACS712_Current_Value").getNewValue();
    #elif defined REAL_VALUES
        // TODO : do some hardware magic here
        result.data[name] = 42;
    #endif

    return result;

}
