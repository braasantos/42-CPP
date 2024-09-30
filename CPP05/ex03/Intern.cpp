#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern &src) 
{
    *this = src;
}
Intern &Intern::operator=(const Intern &src)
{
    if (this != &src)
        return *this;
    return *this;
}
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}
AForm* Intern::makeForm(std::string form_name, std::string target)
{
    if (form_name == "PresidentialPardonForm")
    {
        std::cout << "Intern creates " << form_name << std::endl;
        return new PresidentialPardonForm(target);
    }
    else if (form_name == "RobotomyRequestForm")
    {
        std::cout << "Intern creates " << form_name << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (form_name == "ShrubberyCreationForm")
    {
        std::cout << "Intern creates " << form_name << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else
    {
        std::cout << "Form not found" << std::endl;
        return NULL;
    }
}