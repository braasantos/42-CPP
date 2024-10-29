#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "[ERROR] wrong usage" << std::endl, 1);
    else
    {
        {
            std::vector<int> vec;
            if (addNumbers(vec, av))
                return 0;
            std::cout << "[Unsorted vector] -> ";
            for (size_t i = 0; i < vec.size(); i++)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
            clock_t vec_start= clock();
            FordJohnson(vec);
            clock_t vec_end = clock();
            std::cout << "[Sorted vector] -> ";
            for (size_t i = 0; i < vec.size(); i++)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
            double vec_time = double(vec_end - vec_start);
            std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed
                << vec_time << std::setprecision(5) << " us" << std::endl;
        }
        {
            std::deque<int> deq;
            if (addNumbers(deq, av))
                return (std::cout << "TESTE" << std::endl, 1);
            std::cout << "[Unsorted deque] -> ";
            for (size_t i = 0; i < deq.size(); i++)
                std::cout << deq[i] << " ";
            std::cout << std::endl;
            clock_t deq_start = clock();
            FordJohnson(deq);
            clock_t deq_end= clock();
            std::cout << "[Sorted deque] -> ";
            for (size_t i = 0; i < deq.size(); i++)
                std::cout << deq[i] << " ";
            std::cout << std::endl;
            double deq_time = double(deq_end - deq_start);
            std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << std::fixed
                << deq_time << std::setprecision(5) << " us" << std::endl;
        }
    }
}

//      std::vector: Uses a contiguous block of memory,
//      meaning all elements are stored in one continuous chunk.
//      This layout is highly cache-friendly, so accessing elements sequentially
//      (as during sorting) is very fast.
//      std::deque: Consists of multiple memory blocks, often with each block
//      containing a fixed number of elements. This design allows for efficient
//      insertions and deletions at both the front and back, but it’s less cache-friendly
//      because elements are not stored contiguously.

// Access Speed:

//      With std::vector, accessing an element by index is usually a 
//      single pointer arithmetic operation, which is very fast.
//      For std::deque, accessing an element involves first locating
//      the appropriate memory block, which may add some overhead. This additional indirection
//      increases access time compared to a vector.