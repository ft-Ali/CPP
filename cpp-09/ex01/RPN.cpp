#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(char op, int a, int b) const {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result = applyOperator(token[0], a, b);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return _stack.top();
}
