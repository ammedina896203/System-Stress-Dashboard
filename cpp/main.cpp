#include <iostream>
#include <iomanip>
#include <filesystem>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "processing.h"

int main(){

    std::cout << "Running...\n";

    bool fileExists = std::filesystem::exists("stress_data.csv");

    std::ofstream outputFile("stress_data.csv", std::ios::app);

    if(!fileExists){
        outputFile << "Timestamp, Temp_Raw, CPU_Raw, RAM_Raw, Battery_Raw, Temp_Filtered, CPU_Filtered, RAM_Filtered, Battery_Filtered, Stress_Score, Is_Normal\n";
    }

    std::vector<double> tempHistory;
    std::vector<double> cpuHistory;
    std::vector<double> ramHistory;
    std::vector<double> batteryHistory;

    const int WINDOW_SIZE = 5;

    while(true){

        double temp, cpu, ram, battery;
        if(!(std::cin >> temp >> cpu >> ram >> battery)){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        
        tempHistory.push_back(temp);
        cpuHistory.push_back(cpu);
        ramHistory.push_back(ram);
        batteryHistory.push_back(battery);
        
        if(tempHistory.size() > WINDOW_SIZE){
            tempHistory.erase(tempHistory.begin());
            cpuHistory.erase(cpuHistory.begin());
            ramHistory.erase(ramHistory.begin());
            batteryHistory.erase(batteryHistory.begin());
        }
        
        double tempFiltered = movingAverage(tempHistory);
        double cpuFiltered = movingAverage(cpuHistory);
        double ramFiltered = movingAverage(ramHistory);
        double batteryFiltered = movingAverage(batteryHistory);
        
        double score = stressScore(tempFiltered, cpuFiltered, ramFiltered, batteryFiltered);
        
        bool isNormalScore = isNormal(score);
        
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* timeinfo = std::localtime(&now_time);

        outputFile << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S") << ", "<< temp << ", " << cpu << ", " << ram << ", " << battery << ", "
                   << tempFiltered << ", " << cpuFiltered << ", " << ramFiltered << ", " << batteryFiltered << ", " << score << ", " << isNormalScore << "\n";
        outputFile.flush();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    outputFile.close();

    return 0;
}