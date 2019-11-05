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
#include "Config.h"

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
        DummySensor(int minValue_, int maxValue_, string name_) : minValue(minValue_), maxValue(maxValue_), name(name_) {};

        /* --- measuring --- */
        DataBuffer readSensor();

    private:
        int maxValue;
        int minValue;
        string name;
};

#endif // DummySensor_H
