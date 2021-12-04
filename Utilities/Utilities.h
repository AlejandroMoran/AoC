//
// Created by Moran on 12/3/2021.
//

#ifndef AOC_UTILITIES_H
#define AOC_UTILITIES_H


#include <vector>
#include <filesystem>
#include <string>
class Utilities {

public:
    static std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& Path);

    static void VerifyElseCrash(bool bAssert);

    static void VerifyNotReached();
};


#endif //AOC_UTILITIES_H
