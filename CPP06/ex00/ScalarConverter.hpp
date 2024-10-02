#pragma once

#include "Convert.hpp"

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter &operator=(ScalarConverter const & src);
        static void convert(const char *str);
        virtual void pureFunction() = 0;
};