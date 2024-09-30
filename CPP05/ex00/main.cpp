#include "Bureaucrat.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Usage: ./Bureaucrat < name > < grade >" << std::endl;
        return 1;
    }
    (void)av;
    // std::string name = av[1];
    // int grade = std::atoi(av[2]);
    try
    {
        Bureaucrat b2("Batman", 150);
        // Bureaucrat b1(name, grade);
        Bureaucrat b1 = b2;
        std::cout << b2 << std::endl;
        std::cout << b1 << std::endl;
        // while (b1.getGrade() > 1)
            // b1.incrementGrade();
        // b1.incrementGrade();
        b2.incrementGrade();
        // std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        // b1.decrementGrade();
        b2.decrementGrade();
        // std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}