#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    if (this->_grade_to_exec < 1 || this->_grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (this->_grade_to_exec > 45 || this->_grade_to_sign > 72)
        throw AForm::GradeTooLowException();
    this->_is_signed = false;
    this->_target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_is_signed = other.getIsSigned();
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->_is_signed)
    {
        std::cout << "Form not signed" << std::endl;
        return;
    }
    if (executor.getGrade() <= this->_grade_to_exec)
    {
        std::cout << this->_name << " is making some drilling noises" << std::endl;
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "The robotomy has failed" << std::endl;
        throw AForm::GradeTooLowException();
    }
}