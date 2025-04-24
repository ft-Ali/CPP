#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    // Test avec int
    Array<int> a(3);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 42;

    std::cout << "int array: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // Test avec std::string
    Array<std::string> b(2);
    b[0] = "hello";
    b[1] = "world";

    std::cout << "string array: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    // Test const
    const Array<std::string> c = b;
    std::cout << "const access: " << c[1] << std::endl;

    // Test out of range
    try {
        std::cout << a[10] << std::endl; // devrait throw
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
