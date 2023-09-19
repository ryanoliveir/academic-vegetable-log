#include "Sensor.hpp"

int Sensor::nextId = 1;

Sensor::Sensor(float potassiumLevel, float calciumLevel, float walterLevel):
    potassiumLevel(potassiumLevel), 
    calciumLevel(calciumLevel), 
    waterLevel(walterLevel)
{
    idSensor = nextId++;
}

Sensor::Sensor(){};

float Sensor::getPotassiumLevel() const {
    return potassiumLevel;
}

float Sensor::getCalciumLevel() const {
return calciumLevel;
}

float Sensor::getWaterLevel() const {
    return waterLevel;
}

int Sensor::id() const{
    return idSensor;
}


void Sensor::setPotassiumLevel(float level) {
    potassiumLevel = level;
}

void Sensor::setCalciumLevel(float level) {
    calciumLevel = level;
}

void Sensor::setWaterLevel(float level) {
    waterLevel = level;
}

