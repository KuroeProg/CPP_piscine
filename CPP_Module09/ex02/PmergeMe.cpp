#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vect = other._vect;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::inputParser(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::string argument(av[i]);
        std::istringstream iss(argument);
        int val;

        if (!(iss >> val) || val < 0)
            throw std::invalid_argument("Error: invalid argument");
        _vect.push_back(val);
        _deq.push_back(val);
    }
}

void    PmergeMe::sortAndLen() {
    std::cout << "Before: ";
    printValue(_vect);
    clock_t sVect = clock();
    fordJohnsonSort(_vect);
    clock_t eVect = clock();
    clock_t sDeq = clock();
    fordJohnsonSort(_deq);
    clock_t eDeq = clock();

    std::cout << "After:  ";
    printValue(_vect);
    double vTime = static_cast<double>(eVect - sVect) / CLOCKS_PER_SEC * 1e6;
    double dTime = static_cast<double>(eDeq - sDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << _vect.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << vTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << dTime << " us" << std::endl;
}