#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}
void Harl::complain(std::string level)
{
    for (size_t i = 0; i < level.size(); i++)
        level[i] = toupper(level[i]);

    void (Harl::*funcptr[4])(void) =
    { 
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error 
    };

    std::string levels[4] =
    { 
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR" 
    };
    
    for(int i = 0; funcptr[i]; i++)
    {
        if (levels[i] == level)
            (this->*funcptr[i])();
    }

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


// Function pointers in C++ provide a mechanism to 
// store and invoke functions dynamically at runtime. 
// They are particularly useful for scenarios where 
// the specific 
// function to be called is determined dynamically