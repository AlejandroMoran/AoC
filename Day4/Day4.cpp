//
// Created by Moran on 1/12/2022.
//

#include "Day4.h"
#include <iostream>
#include <string>
#include "../Utilities/Utilities.h"
#include "Day4.h"
Day4::Day4()
        :Input(Utilities::ReadAllLinesInFile("C:/Users/Moran/ClionProjects/AoC/Day4/Day4.input"))
{
    //Read chosen numbers
    Utilities::VerifyElseCrash(!Input.empty());
    std::stringstream ChosenNumbersStream{Input[0]};
    std::string CurrentNumber;
    while(std::getline(ChosenNumbersStream, CurrentNumber, ',')) {
        ChosenNumbers.push_back(std::atoi(CurrentNumber.c_str()));
    }

    //Read the boards
    int NextBingoLine = 2;
    while(NextBingoLine + 5 <= Input.size()){
        BingoBoard CurrentBoard;
        for(int i = NextBingoLine; i < NextBingoLine + 5; ++i) {
            std::stringstream BoardLineStream{Input[i]};
            for(int j = 0; j < 5; ++j){
                int RowNumber = 0;
                BoardLineStream >> RowNumber;
                CurrentBoard.Numbers.push_back(RowNumber);
                CurrentBoard.Marked.push_back(false);
            }
        }
        BingoBoards.push_back(CurrentBoard);
        NextBingoLine += 6;
    }

    //Solve all the boards
    for(BingoBoard& CurrentBoard : BingoBoards){
        CurrentBoard.Solve(ChosenNumbers);
    }

    //Sort the bingo boards
    std::sort(BingoBoards.begin(), BingoBoards.end(),
        [](const BingoBoard& Left, const BingoBoard& Right){
            return Left.Rank < Right.Rank;
        });
}
void Day4::BingoBoard::Solve(const std::vector<int> &ChosenNumbers) {
    for(int i = 0; i < ChosenNumbers.size(); ++i){
        //Check if the board have the  chosen number
        auto FindIndex = std::find(Numbers.begin(),Numbers.end(),ChosenNumbers[i]);
        if(FindIndex == ChosenNumbers.end())
            continue;

        //Mark Chosen Number
        int CurrentNumberIndex = FindIndex - Numbers.begin();
        Marked[CurrentNumberIndex] = true;

        //Check if colum completed
        bool bSolved = true;
        int CurrentColum = CurrentNumberIndex % 5;
        for(int j = CurrentColum; j < Marked.size(); j += 5){
            if(!Marked[j]) {
                bSolved = false;
                break;
            }
        }
        //If solved store rank and final score
        if(bSolved){
            Rank = i;
            int SumOfUnmarked = 0;
            for(int j = 0; j < 25; ++j){
                if(!Marked[j])
                    SumOfUnmarked += Numbers[j];
            }
            FinalScore = SumOfUnmarked * ChosenNumbers[i];
            break;
        }

        //Check if row completed
        bSolved = true;
        int RowStartIndex = (CurrentNumberIndex / 5) * 5;
        for(int j = RowStartIndex; j < RowStartIndex + 5; ++j){
            if(!Marked[j]) {
                bSolved = false;
                break;
            }
        }
        //If solved store rank and final score
        if(bSolved) {
            Rank = i;
            int SumOfUnmarked = 0;
            for(int j = 0; j < 25; ++j){
                if(!Marked[j])
                    SumOfUnmarked += Numbers[j];
            }
            FinalScore = SumOfUnmarked * ChosenNumbers[i];
            break;
        }
    }
}
void Day4::PrintSolution1() {

    std::cout << "Day 4:" << '\n';
    Utilities::VerifyElseCrash(BingoBoards.size() >= 1);
    std::cout << BingoBoards[0].FinalScore << '\n';
}
void Day4::PrintSolution2() {
    std::cout << BingoBoards[BingoBoards.size()-1].FinalScore << '\n';
}
