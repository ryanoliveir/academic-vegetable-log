#pragma once


class Sensor {
    
    private:
        int idSensor = 0;
        static int nextId;

    public:
        float potassiumLevel = 0.0f;
        float calciumLevel = 0.0f;
        float waterLevel = 0.0f;

    public:
        Sensor(float potassiumLevel, float calciumLevel, float walterLevel);
        Sensor();
        float getPotassiumLevel() const;
        float getCalciumLevel() const;
        float getWaterLevel() const;
        int id() const;


        void setPotassiumLevel(float level);
        void setCalciumLevel(float level);
        void setWaterLevel(float level);
};

