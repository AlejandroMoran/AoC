//
// Created by Moran on 1/12/2022.
//

#ifndef AOC_DAY4_H
#define AOC_DAY4_H

#include <vector>
#include <string>

class Day4 {
public:
    Day4();
    void PrintSolution1();
    void PrintSolution2();
private:
    struct BingoBoard{
        std::vector<int> Numbers;
        std::vector<bool> Marked;
        void Solve(const std::vector<int>& ChosenNumbers);
        int FinalScore;
        int Rank;
    };
    const std::vector<std::string> Input;
    std::vector<int> ChosenNumbers;
    std::vector<BingoBoard> BingoBoards;

};


#endif //AOC_DAY4_H
