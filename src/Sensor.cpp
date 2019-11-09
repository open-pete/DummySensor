/**
 * Sensor.cpp
 * Purpose: implements class Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "Sensor.h"

/**
 * Sensor::readSensor
 * @brief readSensor() reads the sensor and returns the double measurement-value
 *
 * readSensor() reads the sensor, which was set by setSensorType and returns the
 * current measurement-value as a double.
 * In practice readSensor does not really read the sensor, but it delegates the
 * measuring to the implementation of the SensorType-interface.
 *
 * If the Sensor object was created with setDateTimeDuringReadSensor=true
 * the readSensor() function sets the startDateTime of the resulting DataBuffer object to the time
 * after the sensorType.readSensor() function has completely executed.
 *
 * If the Sensor object was created with setDateTimeDuringReadSensor=false
 * the readSensor() function does not set the startDateTime of the resulting DataBuffer.
 * In this case the startDateTime stays initialized with 0.0.0000 00:00:00:0000
 *
 * @return returns the current measurement-value as a double
 */
DataBuffer Sensor::readSensor() {
    // read sensor value
    DataBuffer result = sensorType->readSensor();

    // set datetime in UTC
    if (setDateTimeDuringReadSensor) {
        result.startDateTime = result.startDateTime.now(true);
    }

    // return DataBuffer
    return result;
}
