#include "Serializer.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong arguments" << std::endl;
        return 1;
    }
    Data data = {av[1]};
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Data pointer as uintptr_t: " << raw << std::endl;
    Data * otherData = Serializer::deserialize(raw);
    std::cout << "Recovered Data: " << otherData->name  << " " << &otherData << std::endl;
}