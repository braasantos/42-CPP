#include "whatever.hpp"

int main( void )
{
    
    std::cout << "----------- INT ---------------" << std::endl;
    {
        int a = 2;
        int b = 18;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }
    
    std::cout << "----------- STRING ---------------" << std::endl;
    {
        std::string c = "braulio";
        std::string d = "braulio";
        std::cout << "c = " << c << ", d = " << d << std::endl;
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    
    std::cout << "----------- FLOAT ---------------" << std::endl;
    {
        float a = 42.0f;
        float b = -3.02f;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }

    std::cout << "----------- DOUBLE ---------------" << std::endl;
    {
        double a = 18.0;
        double b = 0.01;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }

    return 0;
}