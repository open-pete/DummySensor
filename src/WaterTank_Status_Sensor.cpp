/**
 * WaterTank_Status_Sensor.cpp
 * Purpose: implements class WaterTank_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "WaterTank_Status_Sensor.h"

/**
 * WaterTank_Status_Sensor::readSensor
 * @brief readSensor() returns the current status of the fullness of the water tank in percent measured by the WaterTank_Status_Sensor
 * @return a Databuffer which contains the current status of the fullness of the water tank in percent, measured by the WaterTank_Status_Sensor
 */
WaterTank_Status_Sensor::WaterTank_Status_Sensor(const std::string &name_)
    : name(name_) {

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        dvs.values.insert(std::make_pair<std::string, HRand>("WaterTank_Status_Value", HRand(0.0,100.0,-2.0,-0.25,100.0) ) );
    #endif
}

DataBuffer WaterTank_Status_Sensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        result.data[name] = dvs.values.at("WaterTank_Status_Value").getNewValue();
    #elif defined REAL_VALUES
        // TODO : do some hardware magic here
        result.data[name] = 42;
    #endif

    return result;

}
