#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_csvData = other._csvData;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
    databaseCheck(databaseFile);
}

void    BitcoinExchange::databaseCheck(const std::string &dataB) {

    std::ifstream file(dataB.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string current_line;
    std::getline(file, current_line);

    while (std::getline(file, current_line)) {
        if (current_line.empty())
            continue;

        size_t separ = current_line.find(',');
        if (separ == std::string::npos)
            continue;

        std::string date = current_line.substr(0, separ);
        std::string str = current_line.substr(separ + 1);

        while (!date.empty() && std::isspace(date.front()))
            date.erase(0, 1);
        while (!date.empty() && std::isspace(date.back()))
            date.erase(date.size() - 1);
        while (!str.empty() && std::isspace(str.front()))
            str.erase(0, 1);
        while (!str.empty() && std::isspace(str.back()))
            str.erase(str.size() - 1);
        if (!checkDate(date))
            continue;
        char *end = NULL;
        float actual_rate = std::strtof(str.c_str(), &end);
        if (*end != '\0' || actual_rate < 0)
            continue;
        _csvData[date] = actual_rate;
    }
}

bool    BitcoinExchange::checkDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int yy = std::atoi(date.substr(0, 4).c_str());
    int mm = std::atoi(date.substr(5, 2).c_str());
    int dd = std::atoi(date.substr(8, 2).c_str());

    if (yy < 2000 || mm < 1 || mm > 12 || dd < 1)
        return false;
    if (date < "2009-01-03") /* date de creation du bitcoin */
        return false;
    
    static const int lastDayInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lastDay = lastDayInMonths[mm];

    if (mm == 2) {
        bool bisextile = (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0));
        if (bisextile)
            lastDay = 29;
    }
    if (dd > lastDay)
        return false;
    return true;
}

bool    BitcoinExchange::checkValue(const std::string &str, float &val) const {
    char *end;
    val = std::strtof(str.c_str(), &end);

    if (*end != '\0') {
        std::cerr << "Error: bad input => " << str << std::endl;
        return false;
    }
    if (val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


float   BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator c_iter = _csvData.lower_bound(date);

    if (c_iter == _csvData.begin() && (c_iter == _csvData.end() || c_iter->first != date))
        throw std::runtime_error("Error: date placement is incorrect.");
    if (c_iter == _csvData.end() || c_iter->first != date)
        --c_iter;
    return (c_iter->second);
}

void    BitcoinExchange::parseInput(const std::string &inpFile) const {
    std::ifstream file(inpFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    std::string currentLine;
    std::getline(file, currentLine);
    while (std::getline(file, currentLine)) {
        if (currentLine.empty())
            continue ;
        
        size_t separ = currentLine.find('|');
        if (separ == std::string::npos) {
            std::cerr << "Error: bad input => " << currentLine << std::endl;
            continue;
        }
        std::string date = currentLine.substr(0, separ);
        std::string str = currentLine.substr(separ + 1);

        while (!date.empty() && std::isspace(date.front()))
            date.erase(0, 1);
        while (!date.empty() && std::isspace(date.back()))
            date.erase(date.size() - 1);
        while (!str.empty() && std::isspace(str.front()))
            str.erase(0, 1);
        while (!str.empty() && std::isspace(str.back()))
            str.erase(str.size() - 1);
        if (date.empty() || str.empty()) {
            std::cerr << "Error: bad input => " << currentLine << std::endl;
            continue ;
        }
        float val;
        if (!checkDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue ;
        }
        if (!checkValue(str, val))
            continue ;
        try {
            float mult = getExchangeRate(date);
            std::cout << date << " => " << val << " = " << val * mult << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
