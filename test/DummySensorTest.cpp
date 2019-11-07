/**
 * DummySensorTest.cpp
 * Purpose: implements tests for class Dummy Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "DummySensor.h"

TEST_CASE("test if DummySensor returns a value between 0 and 49") {
    // randomize
    srand(time(NULL));

    Sensor Sensor1;
    int minValue, maxValue;
    string name, dataSource;

    SECTION("Test for temperature sensor") {
        minValue = 0;
        maxValue = 50;
        name = "Temperatur";
        dataSource = "Sensor";
    }

    for (int i=0; i<100; i++) {
        Sensor1.setSensorType(new DummySensor(minValue, maxValue, name, dataSource));
        std::cout << "created temperature sensor " << endl;
        DataBuffer result = Sensor1.readSensor();
        std::cout << "DummySensor.read == " << result << endl;
        REQUIRE(result.data[name] >= (double) minValue);
        REQUIRE(result.data[name] <= (double) maxValue);
    }

}
