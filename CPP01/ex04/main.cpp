#include "Replace.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string line;
        std::string fileToCreate = av[1];
        fileToCreate += ".replace";
        std::ofstream new_file(fileToCreate.c_str()); // creates the output file
        std::ifstream file(av[1]); // creates in input file where im gonna rad
        if (av[2][0] == '\0' || av[3][0] == '\0')
        {
            std::cout << "Please insert a valid string\n";
            return 0;
        }
        if (file.is_open()) // returns a bool if the file we opened sucessfully 
        {
            while(std::getline(file, line)) //gnl
            {
                std::string newline = trim(line); // treat the string 
                newline = replaceLine(line, av[2], av[3]); // replace
                new_file << newline << std::endl; // add to the input file
            }
            file.close();
            new_file.close();
            return 1;
        }
        else
        {
            std::cout << "Error opening the file\n";
            return 1;
        }
        return 0;
    }
    std::cout << "Wrong number of arguments\n";
    std::cout << "Please insert a <FILE>, <S1> and <S2>\n";
    return 0;
}
