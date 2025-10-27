#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template <typename T>

typename T::iterator easyfind(T &storage, int nbr) {
    typename T::iterator iter = std::find(storage.begin(), storage.end(), nbr);
    if (iter == storage.end())
        throw std::runtime_error("Value not found");
    return iter;
}


#endif