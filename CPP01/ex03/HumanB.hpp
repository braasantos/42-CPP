#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void set_name(std::string input);
    void setWeapon(Weapon& weapon);
};
