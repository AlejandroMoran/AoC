//
// Created by Moran on 12/3/2021.
//

#ifndef AOC_DAY3_H
#define AOC_DAY3_H


#include <vector>
#include <string>

class Day3 {
public:
    Day3();
    void PrintSolution1();
    void PrintSolution2();
private:
    const std::vector<std::string> Input;
    int CalculatePowerConsumption();
    static std::vector<int> CountOnesByPosition(const std::vector<std::string>& CurrentInput);
    int CalculateLifeSupport();
};
#endif //AOC_DAY3_H
