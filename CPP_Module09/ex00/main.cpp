#include "BitcoinExchange.hpp"
# include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error Usage : ./btc [file.csv]" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange bitcoin("data.csv");
        bitcoin.parseInput(av[1]);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}