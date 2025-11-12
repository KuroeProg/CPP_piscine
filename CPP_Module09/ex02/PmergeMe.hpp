#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <stdexcept>
# include <ctime>
# include <iomanip>
# include <algorithm>

class PmergeMe {    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void inputParser(int ac, char **av);
        void sortAndLen();
        const std::vector<int> &getVector() const;

    private:
        std::vector<int> _vect;
        std::deque<int>  _deq;
        std::vector<size_t> jacobsthalPart(size_t n) const;
        void fJVect(std::vector<int> &vect);
        void fJDeq(std::deque<int> &deq);
        template <typename Tcontainer>
        void printValue(const Tcontainer &cont) const {
            for (typename Tcontainer::const_iterator iter = cont.begin();
                 iter != cont.end(); ++iter)
                std::cout << *iter << " ";
            std::cout << std::endl;
        }
};

#endif
