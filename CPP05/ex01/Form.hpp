#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int _grade_to_sign;
        const int _grade_to_exec;
        bool _is_signed;
    public:
        Form();
        Form(std::string const name, int grade_to_sign, int grade_to_exec);
        Form(Form const & src);
        Form & operator=(Form const & src);
        ~Form();
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void beSigned(Bureaucrat const &bureaucrat);
        class GradeTooHighException;
        class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};

class Form::GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};
std::ostream& operator << (std::ostream& out, Form const &obj);
