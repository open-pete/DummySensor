# DummySensor
A C++ implementation of a SensorClass which reads no real values from sensors but outputs dummy-data

[![Build Status](https://travis-ci.org/open-pete/DummySensor.svg?branch=development)](https://travis-ci.org/open-pete/DummySensor) [![Coverage Status](https://coveralls.io/repos/github/open-pete/DummySensor/badge.svg?branch=development)](https://coveralls.io/github/open-pete/DummySensor?branch=development)

## Requirements 

 1. Installation of qt
 2. Installation of python3-pip and gitpython

## Setup / Clone & Compile 

```bash
# set variables
repoName="DummySensor"
repoURL="https://github.com/open-pete/DummySensor.git"
branch="master"
manifest="default.xml"

# clone this repository
git clone ${repoURL}
cd ${repoName}

# download all depency repos
git clone https://github.com/mezorian/EasyDepend.git
cp EasyDepend/*.py .
python3 example.py

# build
source /opt/qt55/bin/qt55-env.sh
/opt/qt55/bin/qmake
make clean
make

# run
./DummySensor

```

## Roadmap

### v1.1.0 Dummy Sensor
- [x] returning dummy values
- [x] storing time of readSensor
- [ ] well documented
- [ ] coverage report working
- [ ] well tested
- [ ] two readSensor implementations possible dummy-values for testing, real hardware implementation (depending on a variable during compile-time)
- [ ] more then one value possible (for multi-sensors, or for sensors with more then one value (e.g. GPS) )

### v1.2.0 Dummy Implementation of 5-10 sensors
- [ ] GPS
- [ ] Power consumption / current / voltage
- [ ] Relais Status
- [ ] Battery Status / voltage
- [ ] Water Tank Status
- [ ] Temperature
- [ ] ...
