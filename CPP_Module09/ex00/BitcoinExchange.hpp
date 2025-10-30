#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>
# include <stdexcept>
# include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, float> _csvData;

        void    databaseCheck(const std::string &dataB);
        bool    checkDate(const std::string &date) const;
        bool    checkValue(const std::string &str, float &val) const;
        float   getExchangeRate(const std::string &date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange(const std::string &databaseFile);
        void    parseInput(const std::string &inpFile) const;
};


#endif