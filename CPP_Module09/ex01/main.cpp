#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: number of arguments invalid" << std::endl;
        return 1;
    }
    try {
        RPN expr;
        expr.calculAction(av[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}