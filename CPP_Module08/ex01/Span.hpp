#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <stdexcept>
/* The template itInputNumbers, associated with addNbrRange
** allow us to copy a big amount of number (for example, 10000,
** asked by the subject) without copying the number one by one
** with addnumber, who will actually as a big amount of power
** used, and can slow drastically the machine we are using
** currently. */
class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &cpy);
        ~Span();
        Span &operator=(const Span &other);
        void addNumber(int n);
        int  shortestSpan() const;
        int  longestSpan() const;
        
        template <typename ItInputNumbers>
        void addNbrRange(ItInputNumbers start, ItInputNumbers end) {
            if (_nbr.size() + std::distance(start, end) > _MaximumSize)
                throw std::runtime_error("You don't have the space too add this range");
            _nbr.insert(_nbr.end(), start, end);
        }
    private:
       unsigned int     _MaximumSize;
       std::vector<int> _nbr;
};


#endif