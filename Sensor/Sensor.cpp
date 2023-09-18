#include "Sensor.hpp"


Sensor::Sensor(float potassiumLevel, float calciumLevel, float walterLevel):
    potassiumLevel(potassiumLevel), 
    calciumLevel(calciumLevel), 
    walterLevel(walterLevel)
{}
    

float Sensor::getPotassiumLevel() const {
    return potassiumLevel;
}

float Sensor::getCalciumLevel() const {
return calciumLevel;
}

float Sensor::getWalterLevel() const {
    return calciumLevel;
}

