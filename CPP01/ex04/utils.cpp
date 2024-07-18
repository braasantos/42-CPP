#include "Replace.hpp"

std::string replaceLine(std::string line, std::string toFound, std::string toReplace)
{
    std::string result;
    size_t startPos = 0;
    size_t foundPos = line.find(toFound, startPos); // fincds the first occurance of toFound on the line stating by the startPos
    while (foundPos != std::string::npos) // indicates that no match found
    {
        result += line.substr(startPos, foundPos - startPos);
        result += toReplace;
        startPos = foundPos + toFound.length(); // updates the start position
        foundPos = line.find(toFound, startPos); // continues the loop
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