#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const &src)
{
    *this = src;
}
RPN& RPN::operator=(RPN const &src)
{
    if (this != &src)
        return *this;
    return *this;
}
RPN::~RPN(){}

int RPN::isValid(int c)
{
    if (isdigit(c))
        return 1;
    else if (c == '-' || c == '+' || c == '*' || c == '/')
        return 1;
    return 0;
}
int RPN::issign(int c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/')
        return 1;
    return 0;
}

float RPN::doMath(int num1, int num2, int c)
{
    if (c == '-')
        return num1 - num2;
    if (c == '+')
        return num1 + num2;
    if (c == '*')
        return num1 * num2;
    if (c == '/')
        return num1 / num2;
    return 0;
}

void RPN::show()
{
    std::cout << this->stck.top() << std::endl;
}

int RPN::checkToken(std::string token)
{
    for (int i = 0; token[i]; i++)
    {
        if (!isValid(token[i]))
            return 1;
    }
    //parei aqui a acabar de fazer a verificacao do digito
    return 0;
}

int RPN::createStack(const std::string &str, const std::string delimiter)
{
    size_t start = 0;
    size_t end = str.find(delimiter);
    std::string token;
    while (end != std::string::npos)
    {
        token = str.substr(start, end - start);
        if (checkToken(token))
            return 1;
        this->stck.push(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    this->stck.push(str.substr(start));
    return 0;
}

// int RPN::pushToStack(char c)
// {
//     if (isValid(c))
//     {
//         if (isdigit(c))
//         {
//             int digit = c - '0';
//             this->stck.push(digit);
//         }
//         else if (issign(c))
//         {
//             if (operations(c))
//                 return 1;
//         }
//         return 0;
//     }
//     // else
//     //     return (std::cerr << "[Error]" << std::endl, 1);
//     return 0;
// }

// int RPN::operations(char c)
// {
//     if (this->stck.size() <= 1)
//         return (std::cerr << "[ERROR]" << std::endl, 1);
//     int num1, num2, result;
//     num1= this->stck.top();
//     this->stck.pop();
//     num2 = this->stck.top();
//     this->stck.pop();
//     result = doMath(num2, num1, c);
//     this->stck.push(result);
//     return 0;
// }
