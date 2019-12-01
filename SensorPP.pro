QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        mezorian/DateTimePP/src/DateTimePP.cpp \
        mezorian/DateTimePP/src/DateTimePPArithmetics.cpp \
        mezorian/DateTimePP/src/DateTimePPCurrentTime.cpp \
        mezorian/DateTimePP/src/DateTimePPDateTimeInfo.cpp \
        mezorian/DateTimePP/src/DateTimePPGeneralMisc.cpp \
        mezorian/DateTimePP/src/DateTimePPOperator.cpp \
        mezorian/DateTimePP/src/DateTimePPUnixTime.cpp \
        mezorian/HRand/src/HRand.cpp \
        src/ACS712_Current_Sensor.cpp \
        src/Battery_Status_Sensor.cpp \
        src/DataBuffer.cpp \
        src/DummySensor.cpp \
        src/GY_BME280_WeatherSensor.cpp \
        src/NEO_6M_GPS_Sensor.cpp \
        src/Relay_Status_Sensor.cpp \
        src/Sensor.cpp \
        src/WaterTank_Status_Sensor.cpp \
        test/ACS712_Current_SensorTest.cpp \
        test/Battery_Status_SensorTest.cpp \
        test/DummySensorTest.cpp \
        test/GY_BME280_WeatherSensorTest.cpp \
        test/MainTestFile.cpp \
        test/NEO_6M_GPS_SensorTest.cpp \
        test/Relay_Status_SensorTest.cpp \
        test/WaterTank_Status_SensorTest.cpp

INCLUDEPATH += include/ \
               mezorian/DateTimePP/include/ \
               mezorian/HRand/include/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/ACS712_Current_Sensor.h \
    include/Battery_Status_Sensor.h \
    include/CompileTimeOptions.h \
    include/DataBuffer.h \
    include/DummySensor.h \
    include/DummyValueStorage.h \
    include/GY_BME280_WeatherSensor.h \
    include/NEO_6M_GPS_Sensor.h \
    include/Relay_Status_Sensor.h \
    include/Sensor.h \
    include/SensorType.h \
    include/WaterTank_Status_Sensor.h \
    mezorian/DateTimePP/include/DateTimePP.h \
    mezorian/HRand/include/HRand.h \
    test/catch.hpp
