#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    if (this->_grade_to_exec < 1 || this->_grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (this->_grade_to_exec > 137 || this->_grade_to_sign > 145)
        throw AForm::GradeTooLowException();
    this->_is_signed = false;
    this->_target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_is_signed = other.getIsSigned();
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->_is_signed)
    {
        std::cout << "Form not signed" << std::endl;
        return;
    }
    if (executor.getGrade() <= this->_grade_to_exec)
    {
        std::string str = this->_target + "_shrubbery";
        std::ofstream file((this->_target + "_shrubbery").c_str());
        if (!file)
        {
            std::cerr << "Error opening file!" << std::endl;
            return ;
        }
        file << "     *\n";
        file << "    ***\n";
        file << "   *****\n";
        file << "  *******\n";
        file << " *********\n";
        file << "***********\n";
        file << "    |||\n";
        file << "    |||\n";
        file << "    |||\n";
        file.close();
        std::cout << "ASCII tree has been created, please check the " << str << " file on the working directory" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}