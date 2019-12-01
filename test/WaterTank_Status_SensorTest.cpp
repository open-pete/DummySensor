/**
 * WaterTank_Status_SensorTest.cpp
 * Purpose: implements tests for class WaterTank_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "WaterTank_Status_Sensor.h"

TEST_CASE("test if WaterTank_Status_Sensor returns values in the previously defined range") {

    Sensor Sensor1;
    double minValue=0.0, maxValue=0.0;
    string name="", dataSource="";

    SECTION("Test for WaterTank_Status_Sensor") {
        minValue = 0.0;
        maxValue = 100.0;
        name = "WaterTank_Status_Sensor";
        dataSource = "Sensor";
    }

    // create WaterTank_Status_Sensor
    std::cout << "created WaterTank_Status_Sensor sensor " << endl;
    Sensor1.setSensorType(new WaterTank_Status_Sensor);

    for (int i=0; i<100; i++) {

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range
        REQUIRE(result.data[name] >= minValue );
        REQUIRE(result.data[name] <= maxValue );

        // output measured value
        std::cout << "WaterTank_Status_Sensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
