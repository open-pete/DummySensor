#include <iostream>
#include "Sensor.h"
#include "DummySensor.h"

int main() {
    Sensor Sensor1;
    Sensor1.setSensorType(new DummySensor());
    std::cout << "created temperature sensor " << endl;
    std::cout << "DummySensor.read == " << Sensor1.readSensor() << endl;
}
