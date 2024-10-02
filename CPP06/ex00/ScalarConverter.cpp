#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default Constructor was called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default Destructor was called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
    if (this != &src)
        return *this;
    return *this;
}

void ScalarConverter::convert(const char *str)
{
	type types;
    std::string newstr = str;
    if (newstr.length() < 1)
	{
        std::cout << "Not a valid input" << std::endl;
		return ;
	}
	long double newStr = std::strtold(newstr.c_str(), NULL);
	types = returnTypes(newstr);
	switch (types)
	{
		case CHAR:
		{
			long double c = static_cast<long double>(str[0]);
			stCout(c);
		}
			break;
		case INT:
			stCout(newStr);
			break;
		case DOUBLE:
			stCout(newStr);
			break;
		case FLOAT:
			stCout(newStr);
			break;
		case NOTANUNBER:
			printNaN(str);	
			break;
		default:
			std::cout << "Invalid string literal" << std::endl;
			break;
	}
}	