# Vegetables LOG


```c++

#include <iostream>
#include <string>

class Sensor {
private:
    float waterLevel;
    float potassiumLevel;
    float calciumLevel;
    std::string dateTimeMeasured;
    int code;

public:
    float getWaterLevel() {
        return this->waterLevel;
    }

    void setWaterLevel(float waterLevel) {
        this->waterLevel = waterLevel;
    }

    float getPotassiumLevel() {
        return this->potassiumLevel;
    }

    void setPotassiumLevel(float potassiumLevel) {
        this->potassiumLevel = potassiumLevel;
    }

    float getCalciumLevel() {
        return this->calciumLevel;
    }

    void setCalciumLevel(float calciumLevel) {
        this->calciumLevel = calciumLevel;
    }

    std::string getDateTimeMeasured() {
        return this->dateTimeMeasured;
    }

    void setDateTimeMeasured(const std::string& dateTimeMeasured) {
        this->dateTimeMeasured = dateTimeMeasured;
    }

    int getCode() {
        return this->code;
    }

    void setCode(int code) {
        this->code = code;
    }
};

class MonitoredPoint {
    float idealWaterLevel;
    float idealPotassiumLevel;
    float idealCalciumLevel;
    Sensor sensor;

public:
    float getIdealWaterLevel() {
        return this->idealWaterLevel;
    }

    void setIdealWaterLevel(float idealWaterLevel) {
        this->idealWaterLevel = idealWaterLevel;
    }

    float analyzeNutrient(int nutrientID, float level) {
        return 0.0f;
    }


    void soilOverview() {
        std::cout << "Soil Overview:" << std::endl;
        std::cout << "Ideal Water Level: " << idealWaterLevel << std::endl;
        std::cout << "Current Water Level: " << sensor.getWaterLevel() << std::endl;
        std::cout << "Ideal Potassium Level: " << idealPotassiumLevel << std::endl;
        std::cout << "Current Potassium Level: " << sensor.getPotassiumLevel() << std::endl;
        std::cout << "Ideal Calcium Level: " << idealCalciumLevel << std::endl;
        std::cout << "Current Calcium Level: " << sensor.getCalciumLevel() << std::endl;
    }
};

class DataManager {

    MonitoredPoint monitoredPoint;

public:
    float getSoilNutrient(int nutrientID) {
        return 0.0f;
    }

    bool getSoilStatus() {
        return false;
    }
};

class Display {
public:

    int menu() {

        int choice;

        do {
            std::cout << "[1] Overview of the soil." << std::endl;
            std::cout << "[2] All sensor data." << std::endl;
            std::cout << "[3] One nutrient in all sensors." << std::endl;
            std::cout << "[4] Exit." << std::endl << std::endl;

            std::cout << "Provide option: " << std::endl;
            std::cin >> choice;
            std::cout << std::endl;

            if (choice < 0 || choice > 4)
                std::cout << "\tInvalid value!" << std::endl;
        } while (choice < 0 || choice > 4);

        return choice;
    }
};

void sensorData(Sensor& sensor, MonitoredPoint& monitoring_point);


int main() {

    int option;
    Display menu;

    MonitoredPoint alpha;
    Sensor sensor_x;

    MonitoredPoint charlie;
    Sensor sensor_y;

    sensorData(sensor_x, alpha);
    sensorData(sensor_y, charlie);

    do {

        option = menu.menu();

        switch (option) {
        case 1:
            std::cout << " Displaying soil overview..." << std::endl;
            alpha.soilOverview();

            std::cout << std::endl;
            break;

        case 2:
            std::cout << " Displaying data from the selected sensor..." << std::endl;
            break;

        case 3:
            std::cout << "Displaying a specific nutrient in all sensors..." << std::endl;
            break;

        default:
            std::cout << "Exiting..." << std::endl;
        }
    } while (option != 0);
}



void sensorData(Sensor& sensor, MonitoredPoint& monitoring_point) {
    // Provide data to the sensor

    sensor.setWaterLevel(60.0);
    sensor.setCalciumLevel(10.0);
    sensor.setPotassiumLevel(2.0);
    sensor.setDateTimeMeasured("2023-09-12T20:00");
    sensor.setCode(1010);

    monitoring_point.setIdealWaterLevel(40);
}

```
```c++
//./Sensor/Sensor.hpp
#pragma once


class Sensor {
    
    private:
        int id = 0;
        static int nextId;

    public:
        float identificationCode = 0.0f;
        float potassiumLevel = 0.0f;
        float calciumLevel = 0.0f;
        float waterLevel = 0.0f;

    public:
        Sensor(float potassiumLevel, float calciumLevel, float walterLevel);
        Sensor();
        float getPotassiumLevel() const;
        float getCalciumLevel() const;
        float getWaterLevel() const;

        void setPotassiumLevel(float level);
        void setCalciumLevel(float level);
        void setWaterLevel(float level);
};

```

```c++
//./Sensor/Sensor.cpp
#include "Sensor.hpp"

int Sensor::nextId = 1;

Sensor::Sensor(float potassiumLevel, float calciumLevel, float walterLevel):
    potassiumLevel(potassiumLevel), 
    calciumLevel(calciumLevel), 
    waterLevel(walterLevel)
{
    id = nextId++;
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

void Sensor::setPotassiumLevel(float level) {
    potassiumLevel = level;
}

void Sensor::setCalciumLevel(float level) {
    calciumLevel = level;
}

void Sensor::setWaterLevel(float level) {
    waterLevel = level;
}


```


```c++
//./MonitoredSpot/MonitoredSpot.hpp
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
        MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel, int coordinate_x, int coordinate_y);
        MonitoredSpot();
        float getIdealPotassiumLevel() const;
        float getIdealCalciumLevel() const;
        float getIdealWaterLevel() const;

        void setSensor(const Sensor& sensor);
        void setIdealPotassiumLevel(float newIdealPotassiumLevel);
        void setIdealCalciumLevel(float newIdealCalciumLevel);
        void setIdealWaterLevel(float newIdealWaterLevel);

        void soilOverview() const;
        
};
```


```c++
//./MonitoredSpot/MonitoredSpot.cpp
#include "MonitoredSpot.hpp"
#include <iostream>


MonitoredSpot::MonitoredSpot(float idealPotassiumLevel, float idealCalciumLevel, float idealWaterLevel, int coordinate_x, int coordinate_y):
    idealPotassiumLevel(idealPotassiumLevel),
    idealCalciumLevel(idealCalciumLevel),
    idealWaterLevel(idealWaterLevel),
    coordinate_x(coordinate_x),
    coordinate_y(coordinate_y),
    sensor(0.0, 0.0, 0.0)
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


void MonitoredSpot::soilOverview() const {
    std::cout << "Ideal Water Level: " << idealWaterLevel << std::endl;
    std::cout << "Current Water Level: " << sensor.getWaterLevel() << std::endl;
    std::cout << "Ideal Potassium Level: " << idealPotassiumLevel << std::endl;
    std::cout << "Current Potassium Level: " << sensor.getPotassiumLevel() << std::endl;
    std::cout << "Ideal Calcium Level: " << idealCalciumLevel << std::endl;
    std::cout << "Current Calcium Level: " << sensor.getCalciumLevel() << std::endl;
    
}


```




```c++
//./main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "./Sensor/Sensor.hpp"
#include "./MonitoredSpot/MonitoredSpot.hpp"

class Display {
public:

    int menu() {

        int choice;

        do {
            std::cout << "[1] Overview of the soil." << std::endl;
            std::cout << "[2] All sensor data." << std::endl;
            std::cout << "[3] One nutrient in all sensors." << std::endl;
            std::cout << "[4] Exit." << std::endl << std::endl;

            std::cout << "Provide option: " << std::endl;
            std::cin >> choice;
            std::cout << std::endl;

            if (choice < 0 || choice > 4)
                std::cout << "\tInvalid value!" << std::endl;
        } while (choice < 0 || choice > 4);

        return choice;
    }
};

void pupulateSpots(MonitoredSpot& alpha_point, MonitoredSpot& bravo_point, MonitoredSpot& charlie_point, MonitoredSpot& delta_point, MonitoredSpot& echo_point);
void populateSensors(Sensor& sensor_alpha, Sensor& sensor_bravo, Sensor& sensor_charlie,Sensor&   sensor_delta, Sensor& sensor_echo);
void showMonitoredSpotsData(const std::vector<std::string>& labels, const std::vector<MonitoredSpot>& monitoredSpots);

int main() {

    int option;
    
    
    Display menu;

    std::vector<std::string> spotNames = { "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO"};

    MonitoredSpot alpha;
    MonitoredSpot bravo;
    MonitoredSpot charlie;
    MonitoredSpot delta;
    MonitoredSpot echo;

    std::vector<MonitoredSpot> monitoredSpots = { alpha, bravo, charlie, delta, echo };
    pupulateSpots(alpha, bravo, charlie, delta, echo);


    Sensor sensor_alpha;
    Sensor sensor_bravo;
    Sensor sensor_charlie;
    Sensor sensor_delta;
    Sensor sensor_echo;

    std::vector<Sensor> sensors = { sensor_alpha, sensor_bravo, sensor_charlie, sensor_delta, sensor_echo };
    populateSensors(sensor_alpha, sensor_bravo, sensor_charlie, sensor_delta, sensor_echo);


    alpha.setSensor(sensor_alpha);
    bravo.setSensor(sensor_bravo);
    charlie.setSensor(sensor_charlie);
    delta.setSensor(sensor_delta);
    echo.setSensor(sensor_echo);




    do {

        option = menu.menu();

        switch (option) {
        case 1:
            std::cout << " Displaying soil overview..." << std::endl;
            showMonitoredSpotsData(spotNames, monitoredSpots);

            std::cout << std::endl;
            break;

        case 2:
            std::cout << "Displaying data from the selected sensor..." << std::endl;
            break;

        case 3:
            std::cout << "Displaying a specific nutrient in all sensors..." << std::endl;
            break;

        default:
            std::cout << "Exiting..." << std::endl;
        }
    } while (option != 0);
}



void populateSensors(Sensor& sensor_alpha, Sensor& sensor_bravo, Sensor& sensor_charlie, Sensor& sensor_delta, Sensor& sensor_echo) {
    // Populate sensor_alpha with data
    sensor_alpha.setPotassiumLevel(0.5f);
    sensor_alpha.setCalciumLevel(0.8f);
    sensor_alpha.setWaterLevel(0.6f);

    // Populate sensor_bravo with data
    sensor_bravo.setPotassiumLevel(0.4f);
    sensor_bravo.setCalciumLevel(0.7f);
    sensor_bravo.setWaterLevel(0.5f);

    // Populate sensor_charlie with data
    sensor_charlie.setPotassiumLevel(0.6f);
    sensor_charlie.setCalciumLevel(0.9f);
    sensor_charlie.setWaterLevel(0.7f);

    // Populate sensor_delta with data
    sensor_delta.setPotassiumLevel(0.3f);
    sensor_delta.setCalciumLevel(0.6f);
    sensor_delta.setWaterLevel(0.4f);

    // Populate sensor_echo with data
    sensor_echo.setPotassiumLevel(0.7f);
    sensor_echo.setCalciumLevel(0.8f);
    sensor_echo.setWaterLevel(0.8f);
}

void pupulateSpots(MonitoredSpot& alpha_point, MonitoredSpot& bravo_point, MonitoredSpot& charlie_point, MonitoredSpot& delta_point, MonitoredSpot& echo_point) {
    // Populate alpha_point with data
    alpha_point.setIdealPotassiumLevel(0.5f);
    alpha_point.setIdealCalciumLevel(0.7f);
    alpha_point.setIdealWaterLevel(0.6f);

    // Populate bravo_point with data
    bravo_point.setIdealPotassiumLevel(0.4f);
    bravo_point.setIdealCalciumLevel(0.6f);
    bravo_point.setIdealWaterLevel(0.5f);

    // Populate charlie_point with data
    charlie_point.setIdealPotassiumLevel(0.6f);
    charlie_point.setIdealCalciumLevel(0.8f);
    charlie_point.setIdealWaterLevel(0.7f);

    // Populate delta_point with data
    delta_point.setIdealPotassiumLevel(0.3f);
    delta_point.setIdealCalciumLevel(0.5f);
    delta_point.setIdealWaterLevel(0.4f);

    // Populate echo_point with data
    echo_point.setIdealPotassiumLevel(0.7);
    echo_point.setIdealCalciumLevel(0.8);
    echo_point.setIdealWaterLevel(0.8);
}


void showMonitoredSpotsData(const std::vector<std::string>& labels, const std::vector<MonitoredSpot>& monitoredSpots) {
    // Iterate through the monitoredSpots vector
    for (size_t i = 0; i < monitoredSpots.size(); ++i) {
        const MonitoredSpot& spot = monitoredSpots[i];
        
        // Print label if available
        if (i < labels.size()) {
            std::cout << "[*]" << labels[i] << std::endl;
        }

        // Call soilOverview method for the current spot
        spot.soilOverview();

        // Print a separator (e.g., "======")
        std::cout << "======" << std::endl;
    }
}



```


Find the definition problem mentioned above and why my output for the showMonitoredSpotsData() function is just values ​​with zeros and not the actual data



