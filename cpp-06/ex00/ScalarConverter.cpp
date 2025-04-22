#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

// Assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

// Checks if the literal is a character enclosed in single quotes (e.g., 'a')
bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

// Checks if the literal is a valid integer
bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty())
        return false;
    
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < literal.length(); i++) { // Check each character in the string
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

// Checks if the literal is a valid float (ends with 'f')
bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
        
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    
    // Allow float values like "42f" without requiring a decimal point
    return true;
}

// Checks if the literal is a valid double
bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    
    return hasDecimalPoint;
}

// Converts a char literal and prints its corresponding conversions
void ScalarConverter::convertChar(const std::string& literal) {
    char c = literal[1];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

// Converts an integer literal and prints its corresponding conversions
void ScalarConverter::convertInt(const std::string& literal) {
    int value;
    std::istringstream iss(literal);
    iss >> value;
    
    // Checks for overflow or invalid input
    if (iss.fail()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    // Converts to char
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

// Converts a float literal and prints its corresponding conversions
void ScalarConverter::convertFloat(const std::string& literal) {
    float value;
    
    if (literal == "nanf")
        value = std::numeric_limits<float>::quiet_NaN();
    else if (literal == "+inff")
        value = std::numeric_limits<float>::infinity();
    else if (literal == "-inff")
        value = -std::numeric_limits<float>::infinity();
    else {
        std::string floatStr = literal.substr(0, literal.length() - 1); // Remove 'f'
        value = std::strtof(floatStr.c_str(), NULL);
    }
    
    // Convert to char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    // Convert to int
    if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

// Converts a double literal and prints its corresponding conversions
void ScalarConverter::convertDouble(const std::string& literal) {
    double value;
    
    if (literal == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
        value = -std::numeric_limits<double>::infinity();
    else
        value = std::strtod(literal.c_str(), NULL); // strtod converts string to double
    
    // Converts to char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    // Converts to int
    if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    // Converts to float
    if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

// Determines the type of the literal and performs the appropriate conversion
void ScalarConverter::convert(const std::string& literal)  {
    if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else {
        // Handle the case when the input is a single character without quotes
        if (literal.length() == 1 && std::isprint(literal[0])) {
            char c = literal[0];
            
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        }
        else {
            std::cout << "Invalid literal format" << std::endl;
        }
    }
}