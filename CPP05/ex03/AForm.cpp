#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade_to_sign(0), _grade_to_exec(0), _is_signed(false)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const name, int grade_to_sign, int grade_to_exec) : _name(name) , _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _is_signed(false)
{
    std::cout << "AForm constructor called" << std::endl;
    if (grade_to_exec < 1 || grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_exec > 150 || grade_to_sign > 150)
        throw AForm::GradeTooLowException();
    _is_signed = false;
}

AForm::AForm(AForm const & src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec)
{
    std::cout << "AForm copy constructor called" << std::endl;
    *this = src;
}

AForm & AForm::operator=(AForm const & src)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &src)
        _is_signed = src.getIsSigned();
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_is_signed;
}

int AForm::getGradeToSign() const
{
    return this->_grade_to_sign;
}

int AForm::getGradeToExec() const
{
    return this->_grade_to_exec;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator << (std::ostream& out, AForm const &obj)
{
    std::cout << "AForm name: " << obj.getName() << std::endl;
    if (obj.getIsSigned())
        std::cout << "AForm is signed" << std::endl;
    else
        std::cout << "AForm is not signed" << std::endl;
    std::cout << "AForm grade to sign " << obj.getGradeToSign() << std::endl;
    std::cout << "AForm grade to execute " << obj.getGradeToExec();
    return out;
}