#include "Span.hpp"
#include <ctime>

int main()
{
    long N = 214;
    try
    {
        Span sp = Span(N);
        srand(time(NULL));
        for(int i = 0; i < N; i++)
        {
            const int value = rand();
            sp.addNumber(value);
        }
        std::cout << "Shortest: ";
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << std::endl;
        std::cout << "Longest: ";
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Span sp = Span(18);
        sp.addAutomatic();
        // sp.addNumber(10);
        std::cout << "Shortest: ";
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << std::endl;
        std::cout << "Longest: ";
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }