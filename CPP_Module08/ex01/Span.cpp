#include "Span.hpp"

Span::Span(unsigned int N)
   : _MaximumSize(N) {
}

Span::Span(const Span &cpy) {
    *this = cpy;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _nbr = other._nbr;
        _MaximumSize = other._MaximumSize;
    }
    return *this;
}

void    Span::addNumber(int n) {
    if (_nbr.size() >= _MaximumSize)
        throw std::runtime_error("Not enough space left");
    _nbr.push_back(n);
}

/* For shortestSpan we will initialize 'minimum' by the first
** difference numbers (we sort the number, and we compare the
** difference between the 1st and the 2nd value) And after we
** are doing a for loop for getting the minimum difference
** between two numbers. */

int    Span::shortestSpan() const {
    if (_nbr.size() < 2)
        throw std::runtime_error("Not enough number");
    std::vector<int> sortedNbr = _nbr;
    std::sort(sortedNbr.begin(), sortedNbr.end());
    int minimum = sortedNbr[1] - sortedNbr[0];
    for (size_t i = 0; i < sortedNbr.size() - 1; ++i) {
        int diff = sortedNbr[i + 1] - sortedNbr[i];
        if (diff < minimum)
            minimum = diff;
    }
    return minimum;
}

int     Span::longestSpan() const {
    if (_nbr.size() < 2)
        throw std::runtime_error("Not enough number");
    int MinimumNbr = *std::min_element(_nbr.begin(), _nbr.end());
    int MaximumNbr = *std::max_element(_nbr.begin(), _nbr.end());

    return (MaximumNbr - MinimumNbr);
}

