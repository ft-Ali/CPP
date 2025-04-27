#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>  // pour atof
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    std::getline(file, line); // ignore header
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
            float value = static_cast<float>(atof(valueStr.c_str()));
            _data[date] = value;
        }
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it != _data.begin() && (it == _data.end() || it->first != date))
        --it;
    if (it != _data.end())
        return it->second;
    throw std::runtime_error("Error: no valid date found in database.");
}
