#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &cpy) {
    *this = cpy;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
            this->_container = other._container;
    return *this;
}

RPN::~RPN() {}

void    RPN::calculAction(const std::string &expression) {
    std::string current_exp;

    for (std::size_t i = 0; i < expression.size(); ++i) {
        char actual_char = expression[i];

        if (isspace(actual_char))
            continue ;
        if (std::isdigit(actual_char)) {
            if (i + 1 < expression.size() && !std::isspace(expression[i + 1]))
                throw std::runtime_error("Error: invalid format (missing space)");
            _container.push(actual_char - '0');
            continue ;
        }

        if (actual_char == '+' || actual_char == '-'
            || actual_char == '*' || actual_char == '/') {
            if (_container.size() < 2)
                throw std::runtime_error("Error");

            int r = _container.top(); _container.pop();
            int l = _container.top(); _container.pop();
            int res = 0;
            if (actual_char == '+')
                res = l + r;
            else if (actual_char == '-')
                res = l - r;
            else if (actual_char == '*')
                res = l * r;
            else if (actual_char == '/') {
                if (r == 0)
                    throw std::runtime_error("Error: division by zero is impossible");
                res = l / r;
            }
            _container.push(res);
            continue ;
        }
        throw std::runtime_error("Error");
    }
    if (_container.size() != 1)
        throw std::runtime_error("Error: the expression is incomplete");
    std::cout << _container.top() << std::endl;
}