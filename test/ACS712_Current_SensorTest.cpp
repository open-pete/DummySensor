/**
 * ACS712_Current_SensorTest.cpp
 * Purpose: implements tests for class ACS712_Current_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "ACS712_Current_Sensor.h"

TEST_CASE("test if ACS712_Current_Sensor returns values in the previously defined range") {

    Sensor Sensor1;
    double minValue=0.0, maxValue=0.0;
    string name="", dataSource="";

    SECTION("Test for temperature sensor") {
        minValue = -30.0;
        maxValue = 30.0;
        name = "ACS712_Current_Sensor";
        dataSource = "Sensor";
    }

    // create ACS712_Current_Sensor
    std::cout << "created ACS712_Current_Sensor sensor " << endl;
    Sensor1.setSensorType(new ACS712_Current_Sensor);

    for (int i=0; i<100; i++) {

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range

        REQUIRE(result.data[name] >= minValue );
        REQUIRE(result.data[name] <= maxValue );

        std::cout << "ACS712_Current_Sensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
