/**
 * DummySensor.h
 * Purpose: defines class DummySensor
 *
 * @author mezorian
 */


#ifndef DummySensor_H
#define DummySensor_H

#include "DataBuffer.h"

// --- TODO -- dummy code ---
#include <iostream>
#include <stdlib.h>

using namespace std;
// --- TODO -- dummy code ---

#include "SensorType.h"

/**
 * DummySensor class
 * @brief The DummySensor class provides an implementation of readSensor() for the Sensor TODO Dummy
 * The DummySensor class is an implementation of the interface SensorType and implements the function readSensor().
 * The design of it is based on the design pattern 'strategy'.
 * In respect of this the DummySensor-class is a so called 'ConcreteStrategy' within the Strategy-Pattern.
 */
class DummySensor : public SensorType {
    public:
        /* --- constructor --- */
        DummySensor(int minValue_, int maxValue_, string name_, string dataSource_) :
            minValue(minValue_), maxValue(maxValue_),
            name(name_), dataSource(dataSource_) {};

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        int maxValue;
        int minValue;
        string name;
        string dataSource;
};

#endif // DummySensor_H
