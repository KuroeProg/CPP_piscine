#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename SwapT>
void swap(SwapT &a, SwapT &b) {
    SwapT temp = a;
    a = b;
    b = temp;
}

template<typename MinT>
MinT const &min(MinT const &a, MinT const &b) {
    return (a < b ? a : b);
}

template<typename MaxT>
MaxT const &max(MaxT const &a, MaxT const &b) {
    return (a > b ? a : b);
}

#endif