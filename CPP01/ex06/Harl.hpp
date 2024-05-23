#pragma once

#include <iostream>
#include <string>

enum Command
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID,
};
Command getCommand(std::string command);
void error(void);
void debug(void);
void info(void);
void warning(void);
void invalid(void);