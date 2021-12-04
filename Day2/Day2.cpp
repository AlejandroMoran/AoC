//
// Created by Moran on 12/3/2021.
//
#include <iostream>
#include <string>
#include "Day2.h"
#include "../Utilities/Utilities.h"
Day2::Day2() {
    Input = Utilities::ReadAllLinesInFile("C:/Users/Moran/ClionProjects/AoC/Day2/Day2.input");
}
void Day2::PrintSolution1() {
    std::cout << "Day 2:" << '\n';
    std::cout << CalculatePosition(false) << '\n';
}
void Day2::PrintSolution2() {
    std::cout << CalculatePosition(true) << '\n';
}

int Day2::CalculatePosition(bool bUseAim) {
    int HorizontalPosition = 0;
    int Depth = 0;
    int Aim=0;
    for(const std::string& CurrentLine: Input){
        std::stringstream CurrentLineStream(CurrentLine);
        std::string Direction;
        CurrentLineStream >> Direction;
        int Magnitude=0;
        CurrentLineStream >> Magnitude;
        if(Direction=="forward"){
            HorizontalPosition+=Magnitude;
            if(bUseAim){
                Depth+=Aim*Magnitude;
            }
        }
        else if(Direction=="up"){
            if(bUseAim){
                Aim-=Magnitude;
            }
            else {
                Depth-=Magnitude;
            }
        }
        else if(Direction=="down"){
            if(bUseAim){
                Aim+=Magnitude;
            }
            else {
                Depth += Magnitude;
            }
        }
        else{
            Utilities::VerifyNotReached();
        }
    }
    return HorizontalPosition*Depth;
}
