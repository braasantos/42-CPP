#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        Bureaucrat b("Batman", 1);
        Form form("Form1", 11, 150);
        form.beSigned(b);
        b.signForm(form);
        std::cout << b << std::endl;
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}