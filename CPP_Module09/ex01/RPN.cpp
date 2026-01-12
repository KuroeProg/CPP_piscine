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

static bool isOnlyIntegerExpression(const std::string &s) {
    std::size_t i = 0;

    while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i])))
        ++i;
    if (i == s.size())
        return false;

    if (s[i] == '+' || s[i] == '-')
        ++i;

    std::size_t digits = 0;
    while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
        ++i;
        ++digits;
    }
    if (digits == 0)
        return false;

    while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i])))
        ++i;

    return (i == s.size());
}

void RPN::calculAction(const std::string &expression) {
    while (!_container.empty())
        _container.pop();

    if (isOnlyIntegerExpression(expression)) {
        std::istringstream iss(expression);
        long v;
        iss >> v;
        _container.push(static_cast<int>(v));
        std::cout << _container.top() << std::endl;
        return;
    }

    for (std::size_t i = 0; i < expression.size(); ++i) {
        char actual_char = expression[i];

        if (std::isspace(static_cast<unsigned char>(actual_char)))
            continue;

        if (std::isdigit(static_cast<unsigned char>(actual_char))) {
            if (i + 1 < expression.size() && !std::isspace(static_cast<unsigned char>(expression[i + 1])))
                throw std::runtime_error("Error");
            _container.push(actual_char - '0');
            continue;
        }

        if (actual_char == '+' || actual_char == '-' || actual_char == '*' || actual_char == '/') {
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
            else {
                if (r == 0)
                    throw std::runtime_error("Error");
                res = l / r;
            }

            _container.push(res);
            continue;
        }

        throw std::runtime_error("Error");
    }

    if (_container.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _container.top() << std::endl;
}
