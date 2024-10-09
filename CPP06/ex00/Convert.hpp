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

void printNaN(double str);

void printChar(float c);

void printInt(int num);

void printFloat(float flo);

void printDouble(double dou);

int checkDigi(std::string str);

int checkAlpha(std::string str);

bool isChar(std::string str);

bool isInt(const std::string& str);

bool isFloat(const std::string& str);

bool isDouble(const std::string& str);

bool isNaN(const std::string& str);

type returnTypes(std::string str);
