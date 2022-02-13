//
// Created by Moran on 12/3/2021.
//

#include <fstream>
#include <cassert>
#include <string>
#include "Utilities.h"

std::vector<std::string> Utilities::ReadAllLinesInFile(const std::filesystem::path &Path) {
    VerifyElseCrash(std::filesystem::exists(Path));
    std::ifstream FileStream(Path);
    std::string CurrentLine;
    std::vector<std::string> AllLines;
    while(std::getline(FileStream, CurrentLine)){
        AllLines.push_back(CurrentLine);
    }
    return AllLines;
}

void Utilities::VerifyElseCrash(bool bAssert){
    assert(bAssert);
    if(!bAssert){
        std::terminate();
    }
}

void Utilities::VerifyNotReached() {
    VerifyElseCrash(false);
}
