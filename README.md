# Sensor++
Sensor++ is a C++ implementation for interfacing different kinds of sensors. The design is based on the strategy-design-pattern. 

[![Build Status](https://travis-ci.org/open-pete/SensorPP.svg?branch=development)](https://travis-ci.org/open-pete/SensorPP) [![Coverage Status](https://coveralls.io/repos/github/open-pete/SensorPP/badge.svg?branch=development)](https://coveralls.io/github/open-pete/SensorPP?branch=development)

## Requirements 

 1. Installation of qt
 2. Installation of python3-pip and gitpython

## Setup / Clone & Compile 

```bash
# set variables
repoName="SensorPP"
repoURL="https://github.com/open-pete/SensorPP.git"
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
./SensorPP

```

## Roadmap

### v1.1.0 Dummy Sensor
- [x] returning dummy values
- [x] storing time of readSensor
- [x] documentation
- [x] coverage report working
- [x] test-cases for dummy sensor
- [x] two readSensor implementations possible dummy-values for testing, real hardware implementation (depending on a variable during compile-time)
- [x] more then one value possible (for multi-sensors, or for sensors with more then one value (e.g. GPS) )
- [x] rename repo to SensorPP

### v1.2.0 Dummy Implementation of 5-10 sensors
- [ ] GPS
- [x] Power consumption / current / voltage
- [ ] Relais Status
- [ ] Battery Status / voltage
- [ ] Water Tank Status
- [ ] Temperature
- [ ] ...
