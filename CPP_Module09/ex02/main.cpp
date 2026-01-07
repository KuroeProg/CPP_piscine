#include  "PmergeMe.hpp"

static bool isVectSorted(const std::vector<int> &vect) {
    if (vect.size() < 2)
        return true;
    for (size_t i = 1; i < vect.size(); ++i) {
        if (vect[i - 1] > vect[i])
            return false;
    }
    return true;
}


int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: usage: ./PmerMge <positive integers>" << std::endl;
        return (1);
    }
    try {
        PmergeMe sort;
        sort.inputParser(ac, av);
        sort.sortAndLen();
    std::vector<int> checkSorted = sort.getVector(); 
        if (!isVectSorted(checkSorted)) {
            std::cerr << "Error: vector not sorted correctly!" << std::endl;
            return 1;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}   