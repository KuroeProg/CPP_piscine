#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>

class RPN {
    private:
        std::stack<int> _container;
    public:
        RPN();
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &other);
        ~RPN();

        void    calculAction(const std::string &expression);
};

#endif