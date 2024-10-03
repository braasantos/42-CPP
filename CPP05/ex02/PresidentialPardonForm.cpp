#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    if (this->_grade_to_exec < 1 || this->_grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (this->_grade_to_exec > 5 || this->_grade_to_sign > 25)
        throw AForm::GradeTooLowException();
    this->_is_signed = false;
    this->_target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_is_signed = other.getIsSigned();
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->_is_signed)
    {
        std::cout << "Form not signed" << std::endl;
        return;
    }
    if (executor.getGrade() <= this->_grade_to_exec)
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
    else
        throw AForm::GradeTooLowException();
}