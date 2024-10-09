#include "iter.hpp"

int main(void)
{
    // Test 1: Integer array
    int intArr[5] = {1, 2, 3, 4, 5};
    std::cout << "Testing with integer array:" << std::endl;
    iter(intArr, 5, show);

    // Test 2: Double array
    double doubleArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "\nTesting with double array:" << std::endl;
    iter(doubleArr, 5, show);

    // Test 2: Float array
    float FloatArr[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "\nTesting with Float array:" << std::endl;
    iter(FloatArr, 5, show);

    // Test 3: String array
    std::string strArr[3] = {"Hello", "World", "!"};
    std::cout << "\nTesting with string array:" << std::endl;
    iter(strArr, 3, show);

    // Test 4: Char array
    char charArr[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << "\nTesting with char array:" << std::endl;
    iter(charArr, 6, show);

    return 0;
}
