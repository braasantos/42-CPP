#include "Replace.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string line;
        std::string fileToCreate = av[1];
        fileToCreate += ".replace";
        std::ofstream new_file(fileToCreate.c_str());
        std::ifstream file(av[1]);
        if (av[2][0] == '\0' || av[3][0] == '\0')
        {
            std::cout << "Please insert a valid string\n";
            return 0;
        }
        if (file.is_open())
        {
            while(std::getline(file, line))
            {
                std::string newline = trim(line);
                newline = replaceLine(line, av[2], av[3]);
                new_file << newline << std::endl;
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
