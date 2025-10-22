#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter {
    public:
        static void convert(std::string const &lit);

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &);
        ScalarConverter &operator=(ScalarConverter const &);
        ~ScalarConverter();
};

#endif