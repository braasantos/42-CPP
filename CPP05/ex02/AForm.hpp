#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string _name;
        const int _grade_to_sign;
        const int _grade_to_exec;
        bool _is_signed;
    public:
        AForm();
        AForm(std::string const name, int grade_to_sign, int grade_to_exec);
        AForm(  AForm const & src);
        AForm & operator=(  AForm const & src);
        virtual ~AForm();
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void beSigned(Bureaucrat const &bureaucrat);
        class GradeTooHighException;
        class GradeTooLowException;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

class  AForm::GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};

class  AForm::GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};
std::ostream& operator << (std::ostream& out,  AForm const &obj);