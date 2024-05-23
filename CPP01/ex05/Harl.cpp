#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}
void Harl::complain(std::string level)
{
    if (level == "debug")
        debug();
    else if (level == "info")
        info();
    else if (level == "warning")
        warning();
    else if (level == "error")
        error();
    else
        std::cout << "Unknown level" << std::endl;
}
void Harl::debug(void)
{
    std::cout << RED "DEBUG: " RESET;
    std::cout << "I love having extra bacon ";
    std::cout << "for my 7XL-double-cheese-triple-pickle-special-";
    std::cout << "ketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
    std::cout << RED "INFO: " RESET;
    std::cout << "I cannot believe adding extra ";
    std::cout << "bacon costs more money. You didn’t ";
    std::cout << "put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
    std::cout << RED "WARNING: " RESET;
    std::cout << "I think I deserve to have some extra ";
    std::cout << "bacon for free. I’ve been coming for ";
    std::cout << "years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
    std::cout << RED "ERROR: " RESET;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
