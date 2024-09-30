#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream> 

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string _target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
        void execute(Bureaucrat const &executor) const;
};