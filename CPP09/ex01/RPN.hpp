#pragma once

#include <iostream>
#include <stack>

class RPN
{
    public:
        std::stack<int> stck;

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
};