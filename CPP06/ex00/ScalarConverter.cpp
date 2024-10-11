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
	types = returnTypes(newstr);
	switch (types)
	{
		case CHAR:
		{
			float c = static_cast<float>(str[0]);
			printChar(c);
			printInt(c);
			printFloat(c);
			printDouble(c);
		}
			break;
		case INT:
		{
			int i = atoi(newstr.c_str());
			printChar(i);
			printInt(i);
			printFloat(i);
			printDouble(i);
			break;
		}
		case DOUBLE:
		{
			double d = atof(newstr.c_str());
			printChar(d);
			printInt(d);
			printFloat(d);
			printDouble(d);
			break;
		}
		case FLOAT:
		{
    		float f = static_cast<float>(atof(newstr.c_str()));
			printChar(f);
			printInt(f);
			printFloat(f);
			printDouble(f);
			break;
		}
		case NOTANUNBER:
		{
    		float f = static_cast<float>(atof(newstr.c_str())); 
			printNaN(f);
			break;
		}
		default:
			std::cout << "Invalid string literal" << std::endl;
			break;
	}
}	