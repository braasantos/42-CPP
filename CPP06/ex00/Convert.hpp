#pragma once

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <limits>
#include <cmath>

enum type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
    NOTANUNBER
};


void printError(void);

void stCout(long double &str);

void printNaN(std::string str);

void printChar(long double &c);

void printInt(long double &num);

void printFloat(long double &flo);

void printDouble(long double &dou);

int checkDigi(std::string str);

int checkAlpha(std::string str);

bool isChar(std::string str);

bool isInt(const std::string& str);

bool isFloat(const std::string& str);

bool isDouble(const std::string& str);

bool isNaN(const std::string& str);

type returnTypes(std::string str);
