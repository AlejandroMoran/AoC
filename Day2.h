//
// Created by Moran on 12/3/2021.
//

#ifndef AOC_DAY2_H
#define AOC_DAY2_H
#include <vector>
#include <string>

class Day2 {
public:
    Day2();
    void PrintSolution1();
    void PrintSolution2();
    int CalculatePosition(bool bUseAim);
private:
    std::vector<std::string> Input;
};


#endif //AOC_DAY2_H
