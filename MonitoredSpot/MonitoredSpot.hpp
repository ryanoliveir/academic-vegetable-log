#pragma once
#include "../Sensor/Sensor.hpp"

class MonitoredSpot {
    public:
        float idealPotassiumLevel = 0.0f;
        float idealCalciumLevel = 0.0f;
        float idealWaterLevel = 0.0f;
        int coordinate_x = 0;
        int coordinate_y = 0;
        Sensor sensor;

    public:
        MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel, int coordinate_x, int coordinate_y, Sensor sensor);
        MonitoredSpot();
        float getIdealPotassiumLevel() const;
        float getIdealCalciumLevel() const;
        float getIdealWaterLevel() const;

        void setSensor(const Sensor& sensorUpdated);
        void setIdealPotassiumLevel(float newIdealPotassiumLevel);
        void setIdealCalciumLevel(float newIdealCalciumLevel);
        void setIdealWaterLevel(float newIdealWaterLevel);

        void soilOverview();
        
};