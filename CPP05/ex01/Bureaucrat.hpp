#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & src);
        ~Bureaucrat();
        int getGrade() const;
        std::string getName() const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException;
        class GradeTooLowException;
        void signForm(Form const &form);
};

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too high";
        }
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Grade too low";
        }
};

std::ostream& operator << (std::ostream& out, Bureaucrat const &obj);
