#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    
    // Private copy constructor and assignment operator
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    
    // Helper methods for type detection and conversion
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    
    static void convertChar(const std::string& literal);
    static void convertInt(const std::string& literal);
    static void convertFloat(const std::string& literal);
    static void convertDouble(const std::string& literal);
    
public:
    // Static method to convert a string representation
    static void convert(const std::string& literal);
};

#endif