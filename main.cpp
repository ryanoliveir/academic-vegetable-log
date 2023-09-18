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


