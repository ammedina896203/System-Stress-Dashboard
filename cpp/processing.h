#pragma once
#include <vector>

//function prototypes
double movingAverage(const std::vector<double>& window);
double stressScore(double temp, double cpu, double ram, double battery);
bool isNormal(double score);