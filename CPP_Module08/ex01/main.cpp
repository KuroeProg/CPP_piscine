
#include "Span.hpp"
#include <string>
#include <iostream>

int     main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        {
        unsigned int n = 10000;
        Span bigSpan(n);
        std::vector<int> bigNumbers;
        bigNumbers.reserve(n);
        for (unsigned int i = 0; i < n; ++i)
            bigNumbers.push_back(rand());
        bigSpan.addNbrRange(bigNumbers.begin(), bigNumbers.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    }
        return 0;
}