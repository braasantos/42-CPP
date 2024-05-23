#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"


class HumanA
{
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
};