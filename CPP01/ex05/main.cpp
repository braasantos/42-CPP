#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::string arr[4] =
    {
        "debug",
        "info",
        "warning",
        "error",
    };
    for (size_t i = 0; i < 4; i++)
        harl.complain(arr[i]);
    return 0;
}