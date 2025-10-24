#include "Array.hpp"

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> nbr(5);
    for (unsigned int i = 0; i < nbr.size(); ++i)
        nbr[i] = i * 10;

    std::cout << "nbr contents:" << std::endl;
    for (unsigned int i = 0; i < nbr.size(); ++i)
        std::cout << nbr[i] << std::endl;

    Array<int> empty;
    std::cout << "size of empty = " << empty.size() << std::endl;

    Array<int> cpy(nbr);
    cpy[0] = 1024;
    std::cout << "After modifications of cpy:" << std::endl;
    std::cout << "nbr[0] = " << nbr[0]
              << ", cpy[0] = " << cpy[0] << std::endl;

    Array<int> assign;
    assign = nbr;
    assign[1] = 754;
    std::cout << "After assign:" << std::endl;
    std::cout << "nbr[1] = " << nbr[1]
              << ", assign[1] = " << assign[1] << std::endl;
    try {
        nbr[10] = 42;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
