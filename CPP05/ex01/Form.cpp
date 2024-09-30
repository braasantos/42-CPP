#include "Form.hpp"

Form::Form() : _name("default"), _grade_to_sign(0), _grade_to_exec(0), _is_signed(false)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const name, int grade_to_sign, int grade_to_exec) : _name(name) , _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _is_signed(false)
{
    std::cout << "Form constructor called" << std::endl;
    if (grade_to_exec < 1 || grade_to_sign < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_exec > 150 || grade_to_sign > 150)
        throw Form::GradeTooLowException();
    _is_signed = false;
}

Form::Form(Form const & src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec)
{
    std::cout << "Form copy constructor called" << std::endl;
    *this = src;
}

Form & Form::operator=(Form const & src)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &src)
        _is_signed = src.getIsSigned();
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_is_signed;
}

int Form::getGradeToSign() const
{
    return this->_grade_to_sign;
}

int Form::getGradeToExec() const
{
    return this->_grade_to_exec;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator << (std::ostream& out, Form const &obj)
{
    std::cout << "Form name: " << obj.getName() << std::endl;
    if (obj.getIsSigned())
        std::cout << "Form is signed" << std::endl;
    else
        std::cout << "Form is not signed" << std::endl;
    std::cout << "Form grade to sign " << obj.getGradeToSign() << std::endl;
    std::cout << "Form grade to execute " << obj.getGradeToExec();
    return out;
}