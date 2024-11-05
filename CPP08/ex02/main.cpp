#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "last element " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size " << mstack.size() << std::endl;
    mstack.push(18);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(19);
    mstack.push(1);
    mstack.push(55);
    mstack.push(18);
    mstack.push(1000);
    std::cout << "last element " << mstack.top() << std::endl;
    std::cout << "size " << mstack.size() << std::endl;
    {
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    // MutantStack<int> s(mstack);
    // s.push(18);
    // s.push(18);
    // s.push(18);
    // s.push(18);
    // MutantStack<int>::iterator it = s.begin();
    // MutantStack<int>::iterator ite = s.end();
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    return 0;
}