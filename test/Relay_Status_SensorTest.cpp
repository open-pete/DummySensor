/**
 * Relay_Status_SensorTest.cpp
 * Purpose: implements tests for class Relay_Status_Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "Relay_Status_Sensor.h"

TEST_CASE("test if Relay_Status_Sensor returns values in the previously defined range") {

    Sensor Sensor1;
    double possibleValue1=0.0, possibleValue2=0.0;
    string name="", dataSource="";

    SECTION("Test for Relay_Status_Sensor") {
        possibleValue1 = 0.0;
        possibleValue2 = 1.0;

        name = "Relay_Status_Sensor";
        dataSource = "Sensor";
    }

    // create Relay_Status_Sensor
    std::cout << "created Relay_Status_Sensor sensor " << endl;
    Sensor1.setSensorType(new Relay_Status_Sensor);

    for (int i=0; i<100; i++) {

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range
        REQUIRE( ( (result.data[name + "_Relay1"] == possibleValue1) ||
                   (result.data[name + "_Relay1"] == possibleValue2)  )  );
        REQUIRE( ( (result.data[name + "_Relay2"] == possibleValue1) ||
                   (result.data[name + "_Relay2"] == possibleValue2)  )  );
        REQUIRE( ( (result.data[name + "_Relay3"] == possibleValue1) ||
                   (result.data[name + "_Relay3"] == possibleValue2)  )  );
        REQUIRE( ( (result.data[name + "_Relay4"] == possibleValue1) ||
                   (result.data[name + "_Relay4"] == possibleValue2)  )  );
        REQUIRE( ( (result.data[name + "_Relay5"] == possibleValue1) ||
                   (result.data[name + "_Relay5"] == possibleValue2)  )  );

        // output measured value
        std::cout << "Relay_Status_Sensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
