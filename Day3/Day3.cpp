//
// Created by Moran on 12/3/2021.
//
#include <iostream>
#include <string>
#include "../Utilities/Utilities.h"
#include "Day3.h"
Day3::Day3()
    :Input(Utilities::ReadAllLinesInFile("C:/Users/Moran/ClionProjects/AoC/Day3/Day3.input"))
{}
void Day3::PrintSolution1() {
    std::cout << "Day 3:" << '\n';
    std::cout << CalculatePowerConsumption() << '\n';
}
void Day3::PrintSolution2() {
    std::cout << CalculateLifeSupport() << '\n';
}
int Day3::CalculatePowerConsumption() {
    int Gamma =0;
    std::vector<int> OnesByPosition = CountOnesByPosition(Input);
    for(int CountOfOnes : OnesByPosition){
         int CountOfZeros=(int)Input.size()-CountOfOnes;
         if(CountOfOnes>CountOfZeros){
             Gamma++;
         }
         Gamma<<=1;
    }
    Gamma>>=1;
    int SignificantBitMask =1;
    SignificantBitMask<<=(int)Input[0].size();
    SignificantBitMask--;
    int Epsilon = ~Gamma & SignificantBitMask;
    return Epsilon*Gamma;
}
int Day3::CalculateLifeSupport(){
    int CurrentPosition=0;
    std::vector<std::string> CurrentInput=Input;
    while(CurrentInput.size()!=1){
        std::vector<int> OnesByPosition = CountOnesByPosition(CurrentInput);
        int CountOfOnes= OnesByPosition[CurrentPosition];
        int CountOfZeros=  (int)CurrentInput.size() - CountOfOnes;
        char Filter = '1';
        if(CountOfZeros > CountOfOnes){
            Filter = '0';
        }
        std::vector<std::string> NextInput;
        std::copy_if(
                CurrentInput.begin(),
                CurrentInput.end(),
                std::back_inserter(NextInput),
                [CurrentPosition, Filter](const std::string& CurrentLine){return CurrentLine[CurrentPosition]==Filter;}
                );
        CurrentInput=NextInput;
        CurrentPosition++;
    }
    int OxigenGenerator = std::stoi(CurrentInput[0], nullptr,2);
    CurrentPosition=0;
    CurrentInput=Input;
    while(CurrentInput.size()!=1){
        std::vector<int> OnesByPosition = CountOnesByPosition(CurrentInput);
        int CountOfOnes= OnesByPosition[CurrentPosition];
        int CountOfZeros=  (int)CurrentInput.size() - CountOfOnes;
        char Filter = '0';
        if(CountOfZeros > CountOfOnes){
            Filter = '1';
        }
        std::vector<std::string> NextInput;
        std::copy_if(
                CurrentInput.begin(),
                CurrentInput.end(),
                std::back_inserter(NextInput),
                [CurrentPosition, Filter](const std::string& CurrentLine){return CurrentLine[CurrentPosition]==Filter;}
        );
        CurrentInput=NextInput;
        CurrentPosition++;
    }
    int CO2Scrubber = std::stoi(CurrentInput[0], nullptr,2);

    return CO2Scrubber*OxigenGenerator;
}

std::vector<int> Day3::CountOnesByPosition(const std::vector<std::string> &CurrentInput) {
    Utilities::VerifyElseCrash(!CurrentInput.empty());
    std::vector<int>OnesByPosition(CurrentInput[0].size(),0);
    for(const std::string& CurrentLine : CurrentInput){
        for(int i = 0; i<CurrentLine.size(); i++ ){
            if(CurrentLine[i]=='1'){
                OnesByPosition[i]++;
            }
        }
    }
    return OnesByPosition;
}

