#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

enum forms
{
    ROBO,
    PRESI,
    SHU,
    NOTFOUND
};

class Intern
{
    public :
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();
        AForm* makeForm(std::string form_name, std::string target);

};