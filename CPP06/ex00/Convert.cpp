#include "Convert.hpp"

void printError(void)
{
	std::cout << "Invalid input, only [Numbers] [Strings] [Char] [Printables]" << std::endl;
	exit(1);
}

int checkDigi(std::string str)
{
	size_t j = 0;
	while (j < str.size())
	{
		if (str[j] == '-' || str[j] == '+' || str[j] == '.')
        {
            j++;
            continue;
        }
		if (!std::isspace(str[j]))
			break ;
		j++;
	}
	if (!std::isdigit(str[j]))
			return 1;
    for (size_t i = j; i < str.size(); i++)
    {
		if (str[i] == '.' || str[i] == 'f')
		{
			i++;
			continue;
		}
		if (!std::isdigit(str[i]))
			return 1;
    }
    return 0;
}	

int checkAlpha(std::string str)
{
	size_t j = 0;
	while (j < str.size())
	{
		if (!std::isspace(str[j]))
			break ;
		j++;
	}
    for (size_t i = j; i < str.size(); i++)
    {
		if (!std::isalpha(str[i]))
			return 1;
    }
    return 0;
}	

void printNaN(double str)
{
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(str) << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void printChar(float f)
{
    std::cout << "char: ";

    if (f < 0 || f > 255)
        std::cout << "impossible" << std::endl;
	else
	{
        long newC = static_cast<long>(f);
        if ((newC <= 32 && newC >= 0) || (newC < 256 && newC > 126))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(newC) << "'" << std::endl;
    }
}


void printInt(int num)
{
    std::cout << "int: ";
	if (num <= std::numeric_limits<int>::max() && num >= -std::numeric_limits<int>::min())
		std::cout << static_cast<int>(num) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printFloat(float flo)
{
	std::cout << "float: ";
	if (flo <= std::numeric_limits<float>::max() && flo >= -std::numeric_limits<float>::max())
	{
		if (flo == std::floor(flo) && flo < 1e7 && flo > -1e7) // rounds to the less than or equal
			std::cout << flo << ".0f" << std::endl;
		else
			std::cout << flo << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void printDouble(double dou)
{
    std::cout << "double: ";
	if (dou <= std::numeric_limits<double>::max() && dou >= -std::numeric_limits<double>::max())
	{
		if (dou == std::floor(dou) && dou < 1e7 && dou > -1e7)
			std::cout << dou << ".0" << std::endl;
		else
			std::cout << dou << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}


bool isChar(std::string str)
{
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool isInt(const std::string& str)
{
	if (checkDigi(str))
		return 0;
    char* end;
    long num = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min();
}

bool isFloat(const std::string& str)
{
	if (checkDigi(str))
		return 0;
	if (!checkAlpha(str))
		return 0;
    return (str.find('f') != std::string::npos);
}

bool isDouble(const std::string& str)
{
	if (checkDigi(str))
		return 0;
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

bool isNaN(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"|| str == "inf")
    	return 1;
	char *end = NULL;
	double num = std::strtod(str.c_str(), &end);
	if (str.size() >= 1 && (num <= -2147483648 || num >= 2147483647) && ((end[0] == 'f' && end[1] == '\0') || end[0] == '\0'))
		return 1;
	return 0;
}

type returnTypes(std::string str)
{
	if (isNaN(str))
		return NOTANUNBER;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isDouble(str))
		return DOUBLE;
	else if (isFloat(str))
		return FLOAT;
	else
		return INVALID;
}
