/**
 * NEO_6M_GPS_Sensor.cpp
 * Purpose: implements class NEO_6M_GPS_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "CompileTimeOptions.h"
#include "NEO_6M_GPS_Sensor.h"

/**
 * NEO_6M_GPS_Sensor::readSensor
 * @brief readSensor() returns the current GPS coordinates in decimal degree measured by the NEO_6M_GPS_Sensor
 * @return a Databuffer which contains the currentGPS coordinates in decimal degree, measured by the NEO_6M_GPS_Sensor
 */
NEO_6M_GPS_Sensor::NEO_6M_GPS_Sensor(const std::string &name_)
    : name(name_) {

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        dvs.values.insert(std::make_pair<std::string, HRand>("NEO_6M_GPS_Longitude_Value", HRand(0.0,360.0,-0.25,0.25) ) );
        dvs.values.insert(std::make_pair<std::string, HRand>("NEO_6M_GPS_Latitude_Value", HRand(0.0,360.0,-0.25,0.25) ) );
    #endif
}

DataBuffer NEO_6M_GPS_Sensor::readSensor() {
    DataBuffer result;

    result.dataSource = "Sensor";
    result.useDataSource = true;

    #ifdef DUMMY_VALUES
        DummyValueStorage& dvs = DummyValueStorage::getInstance();
        result.data[name + "_Longitude"] = dvs.values.at("NEO_6M_GPS_Longitude_Value").getNewValue();
        result.data[name + "_Latitude"] = dvs.values.at("NEO_6M_GPS_Latitude_Value").getNewValue();
    #elif defined REAL_VALUES
        // TODO : do some hardware magic here
        result.data[name + "_Longitude"] = 42;
        result.data[name + "_Latitude"] = 42;
    #endif

    return result;

}
