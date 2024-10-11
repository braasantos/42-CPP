#include "Span.hpp"

int main()
{
    Span sp = Span(2);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // sp.addNumber(11);
    // sp.addNumber(18);
    // sp.addNumber(1000);
    // sp.addNumber(17);
    // sp.addNumber(20);
    // sp.addNumber(13);
    // sp.addNumber(60);
    // sp.addNumber(55);
    // sp.addNumber(55);
    // sp.addNumber(32);
    // sp.addNumber(28);
    // sp.addAutomatic();
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // sp.longestSpan();
    return 0;
}