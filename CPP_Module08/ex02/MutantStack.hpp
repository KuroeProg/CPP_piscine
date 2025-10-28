#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>

class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
        MutantStack &operator=(const MutantStack &other) {
            std::stack<T>::operator=(other);
            return *this;
        }
        typedef typename std::stack<T>::container_type:: iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_it;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        const_it begin() const {
            return this->c.begin();
        }
        const_it end() const {
            return this->c.end();
        }
};

#endif