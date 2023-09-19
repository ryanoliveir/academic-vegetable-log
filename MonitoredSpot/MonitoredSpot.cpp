#include "MonitoredSpot.hpp"
#include <iostream>


MonitoredSpot::MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel, int coordinate_x, int coordinate_y, Sensor sensor):
    idealPotassiumLevel(idealPotassiumLevel),
    idealCalciumLevel(idealCalciumLevel),
    idealWaterLevel(idealWaterLevel),
    coordinate_x(coordinate_x),
    coordinate_y(coordinate_y),
    sensor(sensor)
{};

MonitoredSpot::MonitoredSpot(){};

float MonitoredSpot::getIdealPotassiumLevel() const {
    return idealPotassiumLevel;
}

float MonitoredSpot::getIdealCalciumLevel() const {
    return idealCalciumLevel;
}

float MonitoredSpot::getIdealWaterLevel() const {
    return idealWaterLevel;
}


void MonitoredSpot::setSensor(const Sensor& sensorUpdated) {
    sensor = sensorUpdated;
    
}

void MonitoredSpot::setIdealPotassiumLevel(float newIdealPotassiumLevel) {
    idealPotassiumLevel = newIdealPotassiumLevel;
}

void MonitoredSpot::setIdealCalciumLevel(float newIdealCalciumLevel) {
    idealCalciumLevel = newIdealCalciumLevel;
}

void MonitoredSpot::setIdealWaterLevel(float newIdealWaterLevel) {
    idealWaterLevel = newIdealWaterLevel;
}


void MonitoredSpot::soilOverview() {
    std::cout << "Ideal Water Level: " << idealWaterLevel << std::endl;
    std::cout << "Current Water Level: " << sensor.getWaterLevel() << std::endl;
    std::cout << "Ideal Potassium Level: " << idealPotassiumLevel << std::endl;
    std::cout << "Current Potassium Level: " << sensor.getPotassiumLevel() << std::endl;
    std::cout << "Ideal Calcium Level: " << idealCalciumLevel << std::endl;
    std::cout << "Current Calcium Level: " << sensor.getCalciumLevel() << std::endl;
    
}



