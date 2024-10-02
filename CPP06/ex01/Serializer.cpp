#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called" << std::endl;
}
Serializer::~Serializer()
{
    std::cout << "Default destructor called" << std::endl;
}
Serializer::Serializer(Serializer const &src)
{
    *this = src;
}
Serializer & Serializer::operator=(Serializer const &src)
{
    if (this != &src)
        return *this;
    return *this;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}