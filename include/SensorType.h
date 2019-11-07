/**
 * SensorType.h
 * Purpose: defines interface SensorType
 *
 * @author mezorian
 * @version 1.0.0
 */

#ifndef SENSORTYPE_H
#define SENSORTYPE_H

#include "DataBuffer.h"

/**
 * SensorType class
 * @brief The SensorType class is an interface which outsources the readSensor-function from Sensor-class
 *
 * The design of the SensorType-class is based on the design pattern 'strategy'.
 * In respect of this the SensorType-class is the so called 'IStrategy' within the Strategy-Pattern.
 *
 * SensorType can be implemented by different types of sensor-classes.
 * If one wants to inherit from SensorType one has to implement the readSensor()-function.
 *
 *
 */
class SensorType {
    public:
        SensorType() {};
        virtual DataBuffer readSensor() = 0;
};

#endif // SENSORTYPE_H
