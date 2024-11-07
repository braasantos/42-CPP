#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "[ERROR] wrong usage" << std::endl, 1);
    else
    {
        {
            PmergeMe pm;
            if (pm.addNumbersVec(av))
                return 0;
            pm.printBefore();
            pm.before = clock();
            pm.FordJohnsonVec();
            pm.after = clock();
            pm.printAfter();
            pm.printTime();
        }
        {
            PmergeMeDeque pm;
            if (pm.addNumbersVec(av))
                return 0;
            pm.printBefore();
            pm.before = clock();
            pm.FordJohnsonVec();
            pm.after = clock();
            pm.printAfter();
            pm.printTime();
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