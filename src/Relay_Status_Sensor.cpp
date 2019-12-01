/**
 * Relay_Status_Sensor.cpp
 * Purpose: implements class Relay_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "Relay_Status_Sensor.h"

/**
 * Relay_Status_Sensor::readSensor
 * @brief readSensor() returns the current values for multiple relays measured by the Relay_Status_Sensor
 * @return a Databuffer which contains the values for multiple relays, measured as 1 or 0 by the Relay_Status_Sensor
 */
Relay_Status_Sensor::Relay_Status_Sensor(const std::string &name_)
    : name(name_) {

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        dvs.values.insert(std::make_pair<std::string, HRand>("Relay_Status_1_Value", HRand(0.0,10.0,-2.5,2.5) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("Relay_Status_2_Value", HRand(0.0,10.0,-2.5,2.5) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("Relay_Status_3_Value", HRand(0.0,10.0,-2.5,2.5) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("Relay_Status_4_Value", HRand(0.0,10.0,-2.5,2.5) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("Relay_Status_5_Value", HRand(0.0,10.0,-2.5,2.5) ) );
    #endif
}

/**
 * Relay_Status_Sensor::readSensor
 * @brief
 * @return
 */
DataBuffer Relay_Status_Sensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        if (dvs.values.at("Relay_Status_1_Value").getNewValue() >= 5.0) {
            result.data[name + "_Relay1"] = 1;
        } else {
            result.data[name + "_Relay1"] = 0;
        }

        if (dvs.values.at("Relay_Status_2_Value").getNewValue() >= 5.0) {
            result.data[name + "_Relay2"] = 1;
        } else {
            result.data[name + "_Relay2"] = 0;
        }

        if (dvs.values.at("Relay_Status_3_Value").getNewValue() >= 5.0) {
            result.data[name + "_Relay3"] = 1;
        } else {
            result.data[name + "_Relay3"] = 0;
        }

        if (dvs.values.at("Relay_Status_4_Value").getNewValue() >= 5.0) {
            result.data[name + "_Relay4"] = 1;
        } else {
            result.data[name + "_Relay4"] = 0;
        }

        if (dvs.values.at("Relay_Status_5_Value").getNewValue() >= 5.0) {
            result.data[name + "_Relay5"] = 1;
        } else {
            result.data[name + "_Relay5"] = 0;
        }

    #elif defined REAL_VALUES
        // TODO : do some hardware magic here
        result.data[name] = 42;
    #endif

    return result;

}
