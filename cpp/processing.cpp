#include "processing.h"

//Purpose: Calculate moving average of a set of values inside vector window
//Input: vextor window (const so it cant be modified)
//Output: double moving average
double movingAverage(const std::vector<double>& window){
    double sum{};

    for(double value : window){
        sum += value;
    }

    return sum / window.size();
}

//Purpose: Calculate stress score of system
//Input: temp, cpu, ram, battery (all doubles)
//Output: double stress score
double stressScore(double temp, double cpu, double ram, double battery){
    return (temp * 0.4) + (cpu * 0.3) + (ram * 0.2) + (100 - battery) * 0.1;
}

//Purpose: Determine if stress score is normal or not
//Input: double stress score
//Output: bool true if normal, false if not
bool isNormal(double score){
    return score < 80.0;
}