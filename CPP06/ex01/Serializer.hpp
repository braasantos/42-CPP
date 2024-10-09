#pragma once

#include <iostream>
#include <string.h>
#include <stdint.h>

struct Data
{
    std::string name;
};

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        virtual void pureFunction( void ) = 0;
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};