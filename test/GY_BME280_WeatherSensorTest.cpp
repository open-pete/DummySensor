/**
 * GY_BME280_WeatherSensorTest.cpp
 * Purpose: implements tests for class GY_BME280_WeatherSensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "GY_BME280_WeatherSensor.h"

TEST_CASE("test if GY_BME280_WeatherSensor returns values in the previously defined range") {

    Sensor Sensor1;
    double minValueTemperature=0.0, maxValueTemperature=0.0;
    double minValueHumidity=0.0, maxValueHumidity=0.0;
    double minValueAirpressure=0.0, maxValueAirpressure=0.0;
    string name="", dataSource="";

    SECTION("Test for temperature sensor") {
        minValueTemperature = -40.0;
        maxValueTemperature = 85.0;
        minValueHumidity = 0.0;
        maxValueHumidity = 100.0;
        minValueAirpressure = 300.0;
        maxValueAirpressure = 1100.0;

        name = "GY_BME280_WeatherSensor";
        dataSource = "Sensor";
    }

    // create GY_BME280_WeatherSensor
    std::cout << "created GY_BME280_WeatherSensor sensor " << endl;
    Sensor1.setSensorType(new GY_BME280_WeatherSensor);

    for (int i=0; i<100; i++) {

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range
        REQUIRE(result.data[name + "_Temperature"] >= minValueTemperature );
        REQUIRE(result.data[name + "_Temperature"] <= maxValueTemperature );
        REQUIRE(result.data[name + "_Humidity"] >= minValueHumidity );
        REQUIRE(result.data[name + "_Humidity"] <= maxValueHumidity );
        REQUIRE(result.data[name + "_Airpressure"] >= minValueAirpressure );
        REQUIRE(result.data[name + "_Airpressure"] <= maxValueAirpressure );

        // output measured value
        std::cout << "GY_BME280_WeatherSensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
