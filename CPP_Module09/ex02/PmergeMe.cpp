#include "PmergeMe.hpp"

const std::vector<int> &PmergeMe::getVector() const { return _vect; }

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

void PmergeMe::inputParser(int ac, char **av) {
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

std::vector<size_t> PmergeMe::jacobsthalPart(size_t n) const {
    std::vector<size_t> order;
    size_t j_prev = 1;
    size_t j_curr = 1;
    size_t last = 1;

    if (n == 0)
        return order;

    order.push_back(0);

    while (true) {
        size_t j_next = j_curr + 2 * j_prev;
        if (j_next > n)
            break;
        for (size_t i = j_next; i > last; --i)
            order.push_back(i - 1);
        last = j_next;
        j_prev = j_curr;
        j_curr = j_next;
    }
    for (size_t i = n; i > last; --i)
        order.push_back(i - 1);

    return order;
}

void PmergeMe::fJVect(std::vector<int> &vect) {
    if (vect.size() <= 1)
        return;

    std::vector<int> s, l;
    for (size_t i = 0; i < vect.size(); i += 2) {
        if (i + 1 < vect.size()) {
            int a = vect[i], b = vect[i + 1];
            if (a > b)
                std::swap(a, b);
            s.push_back(a);
            l.push_back(b);
        } else {
            l.push_back(vect[i]);
        }
    }

    fJVect(l);

    if (s.empty()) {
        vect = l;
        return;
    }

    std::vector<size_t> jacob = jacobsthalPart(s.size());
    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i];
        std::vector<int>::iterator pos = std::lower_bound(l.begin(), l.end(), s[index]);
        l.insert(pos, s[index]);
    }

    vect = l;
}

void PmergeMe::fJDeq(std::deque<int> &deq) {
    if (deq.size() <= 1)
        return;

    std::deque<int> small, large;
    for (size_t i = 0; i < deq.size(); i += 2) {
        if (i + 1 < deq.size()) {
            int a = deq[i], b = deq[i + 1];
            if (a > b)
                std::swap(a, b);
            small.push_back(a);
            large.push_back(b);
        } else {
            large.push_back(deq[i]);
        }
    }

    fJDeq(large);

    if (small.empty()) {
        deq = large;
        return;
    }

    std::vector<size_t> jacob = jacobsthalPart(small.size());
    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i];
        std::deque<int>::iterator pos = std::lower_bound(large.begin(), large.end(), small[index]);
        large.insert(pos, small[index]);
    }

    deq = large;
}

void PmergeMe::sortAndLen() {
    std::cout << "Before: ";
    printValue(_vect);

    clock_t startVec = clock();
    fJVect(_vect);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    fJDeq(_deq);
    clock_t endDeq = clock();

    std::cout << "After:  ";
    printValue(_vect);

    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << _vect.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}
