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
		if (str[j] == '-' || str[j] == '+')
        {
            j++;
            continue;
        }
		if (!std::isspace(str[j]))
			break ;
		j++;
	}
    for (size_t i = j; i < str.size(); i++)
    {
		if (str[i] == '.' || str[i] == 'f' || str[i] == '-' || str[i] == '+')
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

void printNaN(std::string str)
{
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void printChar(char c)
{
	std::cout << "char: ";
	long newC = static_cast<long>(c);
	if ((newC <= 32 && newC >= 0) || (newC < 256 && newC > 126))
		std::cout << "Non displayable" << std::endl;
	else if (newC < 0 || newC  > 255)
        std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(newC) << "'" << std::endl;
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
	if (flo <= std::numeric_limits<float>::max() && flo >= -std::numeric_limits<float>::min())
	{
		float ff = static_cast<float>(flo);
		if (ff == std::floor(ff) && ff < 1e7 && ff > -1e7)
			std::cout << ff << ".0f" << std::endl;
		else
			std::cout << ff << "f" << std::endl;
	}
	else
		std::cout << flo << "f" << std::endl;
}

void printDouble(double dou)
{
    std::cout << "double: ";
	if (dou <= std::numeric_limits<double>::max() && dou >= -std::numeric_limits<double>::min())
	{
		double dd = static_cast<double>(dou);
		if (dd == std::floor(dd) && dd < 1e7 && dd > -1e7)
			std::cout << dd << ".0" << std::endl;
		else
			std::cout << dd << std::endl;
	}
	else
		std::cout << dou << std::endl;
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
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"|| str == "inf");
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
