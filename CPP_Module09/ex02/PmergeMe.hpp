#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <stdexcept>
# include <ctime>
# include <iomanip>

class PmergeMe {
    private:
        std::vector<int> _vect;
        std::deque<int> _deq;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void inputParser(int ac, char **av);
        void sortAndLen();
    
    private:
        template <typename Tcontainer>
        void fordJohnsonSort(Tcontainer &cont) {
        if (cont.size() <= 1)
            return;

        Tcontainer s, l;
        typename Tcontainer::iterator iter = cont.begin();
        while (iter != cont.end()) {
            typename Tcontainer::iterator next = iter;
            ++next;
            if (next != cont.end()) {
                if (*iter < *next) {
                    s.push_back(*iter);
                    l.push_back(*next);
                } else {
                    s.push_back(*next);
                    l.push_back(*iter);
                }
                iter = ++next;
            } else {
                l.push_back(*iter);
                break;
            }
        }
        fordJohnsonSort(l);

        for (size_t i = 0; i < s.size(); ++i) {
            typename Tcontainer::iterator pos = std::lower_bound(l.begin(), l.end(), s[i]);
            l.insert(pos, s[i]);
        }
        cont = l;
    }
    template <typename Tcontainer>
    void printValue(const Tcontainer &cont) const {
        for (typename Tcontainer::const_iterator iter = cont.begin(); iter != cont.end(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }
};

#endif