#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    //Printing
    std::cout << "\n";
    std::cout << "THE MEMORY ADRESS: \n";
    std::cout << &string <<std::endl;
    std::cout << stringPTR <<std::endl;
    std::cout << &stringREF <<std::endl;
    std::cout << "\n";
    //Printing
    std::cout << "THE VALUE: \n";
    std::cout << string <<std::endl;
    std::cout << *stringPTR <<std::endl;
    std::cout << stringREF <<std::endl;
    std::cout << "\n";
}