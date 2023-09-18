#pragma once

class MonitoredSpot {
    public:
        float idealPotassiumLevel;
        float idealCalciumLevel;
        float idealWaterLevel;

    public:
        MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel);
        float getIdealPotassiumLevel() const;
        float getIdealCalciumLevel() const;
        float getIdealWaterLevel() const;
};