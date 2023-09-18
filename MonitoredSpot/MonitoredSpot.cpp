#include "MonitoredSpot.hpp"


MonitoredSpot::MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel):
    idealPotassiumLevel(idealPotassiumLevel),
    idealCalciumLevel(idealCalciumLevel),
    idealWaterLevel(idealWaterLevel)
{};



float MonitoredSpot::getIdealPotassiumLevel() const {
    return idealPotassiumLevel;
}

float MonitoredSpot::getIdealCalciumLevel() const {
return idealCalciumLevel;
}

float MonitoredSpot::getIdealWaterLevel() const {
    return idealWaterLevel;
}



