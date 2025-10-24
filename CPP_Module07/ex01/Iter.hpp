#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename Titer, typename Ftype>
void iter(Titer *tab, size_t len, Ftype func) {
    for (size_t i = 0; i < len; ++i)
        func(tab[i]);
}

#endif