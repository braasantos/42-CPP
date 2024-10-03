#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Braulio"), _grade(0)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src)
        this->_grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}
int Bureaucrat:: getGrade() const
{
    return this->_grade;
}
std::string Bureaucrat:: getName() const
{
    return this->_name;
}
void Bureaucrat:: incrementGrade()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Incrementing grade" << std::endl;
    this->_grade--;
}
void Bureaucrat:: decrementGrade()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Decrementing grade" << std::endl;
    this->_grade++;
}

std::ostream& operator << (std::ostream& out, Bureaucrat const &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}

void Bureaucrat::signForm(Form const &form)
{
    if (form.getIsSigned())
    {
        std::cout << this->_name << " signed " << form.getName() << std::endl;
        return ;
    }
    else
    {
        if (this->_grade < form.getGradeToSign())
        {
            std::cout << this->_name << " couldn't sign " << form.getName() << " because grade too low" << std::endl;
            return ;
        }
        else
        {
            std::cout << this->_name << " couldn't sign " << form.getName() << " because grade too high" << std::endl;
            return ;
        }
        std::cout << this->_name << " couldn't sign " << form.getName() << " because of other unknown reason" << std::endl;
    }
}
