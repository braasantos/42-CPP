#include "easyfind.hpp"

int main(void)
{
    {
        std::cout << " --------------- CONTAINER : EMPTY [vector] ---------------" << std::endl;
        std::vector<int> vec;
        int num = 2;
        try
        {
            ::esayfind(vec, num);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << " --------------- CONTAINER : [vector] ---------------" << std::endl;
        std::vector<int> vec;
        int i = 10;
        srand(time(NULL));
        while (i > 0)
        {   
            const int value = rand();
            vec.push_back(value);
            i--;
        }
        int num;
        for (int i = 0; i < 10; i++)
        {
            if (i == 5)
                num = vec[i];
        }
        vec.push_back(num);
        for (int i = 0; i < 11; i++)
            std::cout << vec[i] << std::endl;
        try
        {
            ::esayfind(vec, num);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << " --------------- CONTAINER : [list] ---------------" << std::endl;
        std::list<int> lst;
        srand(time(NULL));
        int i = 11;
        lst.push_front(1);
        while (i > 0)
        {   
            const int value = rand();
            lst.push_front(value);
            i--;
        }
        lst.push_front(1);
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
            std::cout << *it << std::endl;
        try
        {
            ::esayfind(lst, 1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // {
        // std::cout << " --------------- CONTAINER : [set] ---------------" << std::endl;
        // std::set<int> st;
        // int i = 0;
        // while (i < 10)
        // {   
        //     st.insert(i);
        //     i++;
        // }
        // for (std::set<int>::iterator it = st.begin(); it != st.end(); ++it)
        //     std::cout << *it << std::endl;
        //  try
        // {
        //     ::esayfind(st, 7);
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
    // }
    return 0;
}