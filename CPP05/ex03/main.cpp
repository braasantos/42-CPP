#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
    {
        std::cout << "Usage: ./Bureaucrat < name > < grade >" << std::endl;
        return 1;
    }
    (void)av;
    try
    {
        std::cout << "---------------BUERAUCRAT---------------" << std::endl;
        Bureaucrat b("Batman", 1);
        Bureaucrat c("Chuck", 1);
        Bureaucrat h("Harvey", 1);
        std::cout << "---------------FORMS--------------" << std::endl;
        PresidentialPardonForm p("Pardon");
        RobotomyRequestForm r("Robotomy");
        ShrubberyCreationForm s("Shrubbery");
        std::cout << "-------------BATMAN AND PARDON--------------" << std::endl;
        // AForm form;
        p.beSigned(b);
        b.signForm(p);
        b.executeForm(p);
        std::cout << "-------------CHECK AND ROBOTOMY---------------" << std::endl;
        r.beSigned(c);
        c.signForm(r);
        c.executeForm(r);
        std::cout << "-----------HARVEY AND SHRUBBERY-----------------" << std::endl;
        s.beSigned(h);
        h.signForm(s);
        h.executeForm(s);
        std::cout << "---------------INTERN----------------" << std::endl;
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        std::cout << "---------------THE END------------" << std::endl;
        
        // std::cout << b << std::endl;
        // std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}