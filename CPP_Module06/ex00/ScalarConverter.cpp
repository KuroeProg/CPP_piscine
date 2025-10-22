#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string const &lit) {
    if (lit == "nan" || lit == "nanf" ||
        lit == "+inf" || lit == "+inff" ||
        lit == "-inf" || lit == "-inff") 
    {
        std::cout << "char: impossible\n" << "int: impossible\n";
        if (lit.find('f') != std::string::npos)
            std::cout << "float: " << lit << "\n"
            << "double: " << lit.substr(0, lit.size() - 1) << "\n";
        else
            std::cout << "float: " << lit << "f\n"
                    << "double: " << lit << "\n";
        return ;
    }

    std::string cleanf = lit;
    if (cleanf.back() == 'f' && cleanf.find('.') != std::string::npos)
        cleanf.erase(cleanf.size() - 1);

    std::stringstream flux(cleanf);
    double dnbr;
    flux >> dnbr;
    if (flux.fail() && lit.size() == 1 && !std::isdigit(lit[0]))
        dnbr = static_cast<double>(lit[0]);
    else if (flux.fail())
    {
        std::cout << "Error: invalid literal" << std::endl;
        return ;
    }
    char    character = static_cast<char>(dnbr);
    int     nbr = static_cast<int>(dnbr);
    float   fnbr = static_cast<float>(dnbr);

    if (std::isnan(dnbr) || std::isinf(dnbr) || nbr < 0 || nbr > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(character))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << character << "'" << std::endl;
    
    if (std::isnan(dnbr) || std::isinf(dnbr) ||
        dnbr > std::numeric_limits<int>::max() ||
        dnbr < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << nbr << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << fnbr << "f" << std::endl;
    std::cout << "double: " << dnbr << std::endl;
}


ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const &) {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}