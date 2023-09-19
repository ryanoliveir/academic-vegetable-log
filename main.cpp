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

// void pupulateSpots(MonitoredSpot& alpha_point, MonitoredSpot& bravo_point, MonitoredSpot& charlie_point, MonitoredSpot& delta_point, MonitoredSpot& echo_point);
// void populateSensors(Sensor& sensor_alpha, Sensor& sensor_bravo, Sensor& sensor_charlie,Sensor&   sensor_delta, Sensor& sensor_echo);
void showMonitoredSpotsData(const std::vector<std::string>& labels, const std::vector<MonitoredSpot>& monitoredSpots);
void displaySensorData(const std::vector<Sensor>& sensors);

void displaySpecificNutrientData(const std::vector<Sensor>& sensors, const std::string& nutrient);


int main() {

    int option;
    
    
    Display menu;

    std::vector<std::string> spotNames = { "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO"};

    // MonitoredSpot alpha;
    // MonitoredSpot bravo;
    // MonitoredSpot charlie;
    // MonitoredSpot delta;
    // MonitoredSpot echo;

    // std::vector<MonitoredSpot> monitoredSpots = { alpha, bravo, charlie, delta, echo };
    // pupulateSpots(alpha, bravo, charlie, delta, echo);


    // Sensor sensor_alpha;
    // Sensor sensor_bravo;
    // Sensor sensor_charlie;
    // Sensor sensor_delta;
    // Sensor sensor_echo;

    // std::vector<Sensor> sensors = { sensor_alpha, sensor_bravo, sensor_charlie, sensor_delta, sensor_echo };
    // populateSensors(sensor_alpha, sensor_bravo, sensor_charlie, sensor_delta, sensor_echo);



    // alpha.setSensor(sensor_alpha);
    // bravo.setSensor(sensor_bravo);
    // charlie.setSensor(sensor_charlie);
    // delta.setSensor(sensor_delta);
    // echo.setSensor(sensor_echo);



    Sensor sensor_alpha(0.5f, 0.8f, 0.6f);
    Sensor sensor_bravo(0.4f, 0.7f, 0.5f);
    Sensor sensor_charlie(0.6f, 0.9f, 0.7f);
    Sensor sensor_delta(0.3f, 0.6f, 0.4f);
    Sensor sensor_echo(0.7f, 0.8f, 0.8f);

    // Create MonitoredSpot objects
    MonitoredSpot alpha(0.5f, 0.7f, 0.6f, 0, 0, sensor_alpha);
    MonitoredSpot bravo(0.4f, 0.6f, 0.5f, 0, 0, sensor_bravo);
    MonitoredSpot charlie(0.6f, 0.8f, 0.7f, 0, 0, sensor_charlie);
    MonitoredSpot delta(0.3f, 0.5f, 0.4f, 0, 0, sensor_delta);
    MonitoredSpot echo(0.7f, 0.8f, 0.8f, 0, 0, sensor_echo);

    std::vector<MonitoredSpot> monitoredSpots = { alpha, bravo, charlie, delta, echo };
    std::vector<Sensor> sensors = { sensor_alpha, sensor_bravo, sensor_charlie, sensor_delta, sensor_echo };

     std::string nutrientType;


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
            displaySensorData(sensors);
            break;

        case 3:
            std::cout << "Displaying a specific nutrient in all sensors..." << std::endl;
            std::cout << "Enter the nutrient type (Potassium/Calcium/Water): ";
            std::cin >> nutrientType;
            displaySpecificNutrientData(sensors, nutrientType);
            break;

        default:
            std::cout << "Exiting..." << std::endl;
            option = 0;
            break;
        }
    } while (option != 0);
}



// void populateSensors(Sensor& sensor_alpha, Sensor& sensor_bravo, Sensor& sensor_charlie, Sensor& sensor_delta, Sensor& sensor_echo) {
//     // Populate sensor_alpha with data
//     sensor_alpha.setPotassiumLevel(0.5f);
//     sensor_alpha.setCalciumLevel(0.8f);
//     sensor_alpha.setWaterLevel(0.6f);

//     // Populate sensor_bravo with data
//     sensor_bravo.setPotassiumLevel(0.4f);
//     sensor_bravo.setCalciumLevel(0.7f);
//     sensor_bravo.setWaterLevel(0.5f);

//     // Populate sensor_charlie with data
//     sensor_charlie.setPotassiumLevel(0.6f);
//     sensor_charlie.setCalciumLevel(0.9f);
//     sensor_charlie.setWaterLevel(0.7f);

//     // Populate sensor_delta with data
//     sensor_delta.setPotassiumLevel(0.3f);
//     sensor_delta.setCalciumLevel(0.6f);
//     sensor_delta.setWaterLevel(0.4f);

//     // Populate sensor_echo with data
//     sensor_echo.setPotassiumLevel(0.7f);
//     sensor_echo.setCalciumLevel(0.8f);
//     sensor_echo.setWaterLevel(0.8f);
// }

// void pupulateSpots(MonitoredSpot& alpha_point, MonitoredSpot& bravo_point, MonitoredSpot& charlie_point, MonitoredSpot& delta_point, MonitoredSpot& echo_point) {
//     // Populate alpha_point with data
//     alpha_point.setIdealPotassiumLevel(0.5f);
//     alpha_point.setIdealCalciumLevel(0.7f);
//     alpha_point.setIdealWaterLevel(0.6f);

//     // Populate bravo_point with data
//     bravo_point.setIdealPotassiumLevel(0.4f);
//     bravo_point.setIdealCalciumLevel(0.6f);
//     bravo_point.setIdealWaterLevel(0.5f);

//     // Populate charlie_point with data
//     charlie_point.setIdealPotassiumLevel(0.6f);
//     charlie_point.setIdealCalciumLevel(0.8f);
//     charlie_point.setIdealWaterLevel(0.7f);

//     // Populate delta_point with data
//     delta_point.setIdealPotassiumLevel(0.3f);
//     delta_point.setIdealCalciumLevel(0.5f);
//     delta_point.setIdealWaterLevel(0.4f);

//     // Populate echo_point with data
//     echo_point.setIdealPotassiumLevel(0.7);
//     echo_point.setIdealCalciumLevel(0.8);
//     echo_point.setIdealWaterLevel(0.8);
// }


void showMonitoredSpotsData(const std::vector<std::string>& labels, const std::vector<MonitoredSpot>& monitoredSpots) {
    // Iterate through the monitoredSpots vector
    for (size_t i = 0; i < monitoredSpots.size(); ++i) {
        MonitoredSpot spot = monitoredSpots[i];
        
        // Print label if available
        if (i < labels.size()) {
            std::cout << "[*]" << labels[i] << std::endl;
        }

        // Call soilOverview method for the current spot
        spot.soilOverview();
        
        std::cout << spot.sensor.getCalciumLevel() << std::endl;
        // Print a separator (e.g., "======")
        std::cout << "======" << std::endl;
    }
}


void displaySensorData(const std::vector<Sensor>& sensors) {
    int selectedSensorId;
    
    // Prompt the user to enter the sensor ID

    std::cout << "Available Sensor IDs:" << std::endl;
    for (const auto& sensor: sensors) {
        std::cout << "Sensor ID " << sensor.id() << std::endl;
    }

    std::cout << "Enter the ID of the sensor to display data: ";
    std::cin >> selectedSensorId;
    
    // Check if the selectedSensorId is valid
    if (selectedSensorId >= 1 && selectedSensorId <= sensors.size()) {
        const Sensor& selectedSensor = sensors[selectedSensorId - 1];
        std::cout << "Sensor ID: " << selectedSensorId << std::endl;
        std::cout << "Potassium Level: " << selectedSensor.getPotassiumLevel() << std::endl;
        std::cout << "Calcium Level: " << selectedSensor.getCalciumLevel() << std::endl;
        std::cout << "Water Level: " << selectedSensor.getWaterLevel() << std::endl;
    } else {
        std::cout << "Invalid sensor ID!" << std::endl;
    }
}


void displaySpecificNutrientData(const std::vector<Sensor>& sensors, const std::string& nutrient) {
    std::cout << "Displaying " << nutrient << " levels for all sensors:" << std::endl;

    // Loop through all sensors and display the specified nutrient's value
    for (size_t i = 0; i < sensors.size(); ++i) {
        const Sensor& currentSensor = sensors[i];
        std::cout << "Sensor ID " << (i + 1) << ": " << nutrient << " Level: ";
        
        // Check the specified nutrient and display its value accordingly
        if (nutrient == "Potassium") {
            std::cout << currentSensor.getPotassiumLevel() << std::endl;
        } else if (nutrient == "Calcium") {
            std::cout << currentSensor.getCalciumLevel() << std::endl;
        } else if (nutrient == "Water") {
            std::cout << currentSensor.getWaterLevel() << std::endl;
        } else {
            std::cout << "Invalid nutrient specified!" << std::endl;
            return;
        }
    }
}

