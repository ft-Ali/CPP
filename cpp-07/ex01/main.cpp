// ex01/main.cpp
#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void printElement(T const &x) {
    std::cout << x << std::endl;
}

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    ::iter(arrInt, 5, printElement);
    std::cout << "---" << std::endl;

    // Test avec std::string
    std::string arrStr[] = {"Hello", "42", "School"};
    ::iter(arrStr, 3, printElement);
    std::cout << "---" << std::endl;

    // Test avec char
    char arrChar[] = {'a', 'b', 'c', 'd'};
    ::iter(arrChar, 4, printElement);

    return 0;
}
