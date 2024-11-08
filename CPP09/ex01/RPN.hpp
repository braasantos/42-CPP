#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    public:
        std::stack<std::string> stck;
        RPN();
        RPN(RPN const &src);
        RPN& operator=(RPN const &src);
        ~RPN();

        int isValid(int c);
        int issign(int c);
        float doMath(int num1, int num2, int c);
        void show();
        int operations(char c);
        int pushToStack(char c);
        int createStack(const std::string &str, const std::string delimiter);
        int checkToken(std::string token);
};