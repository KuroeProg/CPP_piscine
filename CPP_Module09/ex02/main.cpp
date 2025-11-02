#include  "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: usage: ./PmerMge <positive integers>" << std::endl;
        return (1);
    }
    try {
        PmergeMe sort;
        sort.inputParser(ac, av);
        sort.sortAndLen();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}   