/**
 * NEO_6M_GPS_SensorTest.cpp
 * Purpose: implements tests for class NEO_6M_GPS_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "NEO_6M_GPS_Sensor.h"

TEST_CASE("test if NEO_6M_GPS_Sensor returns values in the previously defined range") {

    Sensor Sensor1;
    double minValue=0.0, maxValue=0.0;
    string name="", dataSource="";

    SECTION("Test for temperature sensor") {
        minValue = 0.0;
        maxValue = 360.0;
        name = "NEO_6M_GPS_Sensor";
        dataSource = "Sensor";
    }

    // create NEO_6M_GPS_Sensor
    std::cout << "created NEO_6M_GPS_Sensor sensor " << endl;
    Sensor1.setSensorType(new NEO_6M_GPS_Sensor);

    for (int i=0; i<100; i++) {

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range
        REQUIRE(result.data[name + "_Longitude"] >= minValue );
        REQUIRE(result.data[name + "_Longitude"] <= maxValue );
        REQUIRE(result.data[name + "_Latitude"] >= minValue );
        REQUIRE(result.data[name + "_Latitude"] <= maxValue );

        // output measured value
        std::cout << "NEO_6M_GPS_Sensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
