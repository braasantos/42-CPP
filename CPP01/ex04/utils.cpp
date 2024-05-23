#include "Replace.hpp"

std::string replaceLine(std::string line, std::string toFound, std::string toReplace)
{
    std::string result;
    size_t startPos = 0;
    size_t foundPos = line.find(toFound, startPos);
    while (foundPos != std::string::npos)
    {
        result += line.substr(startPos, foundPos - startPos);
        result += toReplace;
        startPos = foundPos + toFound.length();
        foundPos = line.find(toFound, startPos);
    }
    result += line.substr(startPos);
    return result;
}


std::string trim(std::string line)
{
    std::string name ;
    for(int i = 0; line[i]; i++)
    {
        if (line[i] != 9 && line[i] != 32)
            name += line[i];
    }
    return name;
}