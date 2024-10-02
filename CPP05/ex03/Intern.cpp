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

forms returnForm(std::string form_name)
{
    if (form_name == "robotomy request")
        return ROBO;
    else if (form_name == "presidential pardon")
        return PRESI;
    else if (form_name == "shrubbery creation")
        return SHU;
    else
    {
        std::cout << "Form name not avaliable" << std::endl << "Please try one od the followings" << std::endl;
        std::cout << "[robotomy request]" << std::endl;
        std::cout << "[presidential pardon]" << std::endl;
        std::cout << "[shrubbery creation]" << std::endl;
        return NOTFOUND;
    }
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    forms form = returnForm(form_name); 
    switch (form)
    {
        case 0:
            std::cout << "Intern creates " << form_name << std::endl;
            return new RobotomyRequestForm(target);
        case 1:
            std::cout << "Intern creates " << form_name << std::endl;
            return new PresidentialPardonForm(target);
        case 2:
            std::cout << "Intern creates " << form_name << std::endl;
            return new ShrubberyCreationForm(target);    
        default:
            std::cout << "Form not found" << std::endl;
        break;
    }
    return NULL;
}