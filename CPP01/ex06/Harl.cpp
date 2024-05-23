#include "Harl.hpp"

Command getCommand(std::string command)
{
    if (command == "DEBUG")
        return DEBUG;
    else if (command == "INFO")
        return INFO;
    else if (command == "WARNING")
        return WARNING;
    else if (command == "ERROR")
        return ERROR;
    else
        return INVALID;
}

void debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon ";
    std::cout << "for my 7XL-double-cheese-triple-pickle-special-";
    std::cout << "ketchup burger. I really do!" << std::endl;
}
void info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra ";
    std::cout << "bacon costs more money. You didn’t ";
    std::cout << "put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra ";
    std::cout << "bacon for free. I’ve been coming for ";
    std::cout << "years whereas you started working here since last month." << std::endl;
}
void error(void)
{
    std::cout << "[ ERROR ]" << std::endl;

    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void invalid(void)
{
    std::cout << "[ INVALID ]" << std::endl;
    std::cout << "I dont have an answer for that" << std::endl;
}