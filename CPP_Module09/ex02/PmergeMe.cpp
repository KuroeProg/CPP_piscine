
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
    std::vector<size_t> seq;
    if (n == 0)
        return seq;

    seq.push_back(1);
    size_t j1 = 1, j2 = 1;
    while (true) {
        size_t next = j1 + 2 * j2;
        if (next > n)
            break;
        seq.push_back(next);
        j2 = j1;
        j1 = next;
    }

    for (size_t i = seq.size(); i > 0; --i)
        seq.push_back(seq[i - 1]);
    for (size_t i = seq.back() + 1; i <= n; ++i)
        seq.push_back(i);

    return seq;
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
        } else
            l.push_back(vect[i]);
    }
    fJVect(l);
    std::vector<size_t> jacob = jacobsthalPart(s.size());
    std::vector<bool> inserted(s.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i] - 1;
        if (index < s.size() && !inserted[index]) {
            std::vector<int>::iterator pos =
                std::lower_bound(l.begin(), l.end(), s[index]);
            l.insert(pos, s[index]);
            inserted[index] = true;
        }
    }
    for (size_t i = 0; i < s.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos =
                std::lower_bound(l.begin(), l.end(), s[i]);
            l.insert(pos, s[i]);
        }
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
        } else
            large.push_back(deq[i]);
    }

    fJDeq(large);

    std::vector<size_t> jacob = jacobsthalPart(small.size());
    std::vector<bool> inserted(small.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i] - 1;
        if (index < small.size() && !inserted[index]) {
            std::deque<int>::iterator pos =
                std::lower_bound(large.begin(), large.end(), small[index]);
            large.insert(pos, small[index]);
            inserted[index] = true;
        }
    }

    for (size_t i = 0; i < small.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int>::iterator pos =
                std::lower_bound(large.begin(), large.end(), small[i]);
            large.insert(pos, small[i]);
        }
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
