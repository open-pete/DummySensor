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
    Sensor Sensor1;
    int minValue = 0;
    int maxValue = 50;
    string name = "Temperatur";
    Sensor1.setSensorType(new DummySensor(minValue, maxValue, name));
    std::cout << "created temperature sensor " << endl;
    DataBuffer result = Sensor1.readSensor();
    std::cout << "DummySensor.read == " << result << endl;
    REQUIRE(result.data[name] >= (double) minValue);
    REQUIRE(result.data[name] <= (double) maxValue);
}
