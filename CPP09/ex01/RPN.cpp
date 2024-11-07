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

int RPN::pushToStack(char c)
{
    if (isValid(c))
    {
        if (isdigit(c))
        {
            int digit = c - '0';
            this->stck.push(digit);
        }
        else if (issign(c))
        {
            if (operations(c))
                return 1;
        }
        return 0;
    }
    else
        return (std::cerr << "[Error]" << std::endl, 1);
    return 0;
}

int RPN::operations(char c)
{
    if (this->stck.size() <= 1)
        return (std::cerr << "[ERROR]" << std::endl, 1);
    int num1, num2, result;
    int digit = this->stck.top();
    num1 = digit;
    this->stck.pop();
    digit = this->stck.top();
    num2 = digit;
    this->stck.pop();
    result = doMath(num2, num1, c);
    this->stck.push(result);
    return 0;
}
