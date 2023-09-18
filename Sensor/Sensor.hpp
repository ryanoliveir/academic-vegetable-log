#pragma once


class Sensor {
    
    public:
        float potassiumLevel;
        float calciumLevel;
        float walterLevel;

    public:
        Sensor(float potassiumLevel, float calciumLevel, float walterLevel);
        float getPotassiumLevel() const;
        float getCalciumLevel() const ;
        float getWalterLevel() const ;
};

