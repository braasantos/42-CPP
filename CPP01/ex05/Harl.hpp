#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl();
    ~Harl();
    void complain( std::string level );
};