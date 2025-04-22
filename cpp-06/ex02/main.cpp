#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "Testing random generation and type identification:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    
    // Generate and identify multiple instances
    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest #" << (i + 1) << ":" << std::endl;
        
        // Generate a random instance
        Base* instance = generate();
        
        // Identify the type using pointer
        std::cout << "Identifying with pointer: ";
        identify(instance);
        
        // Identify the type using reference
        std::cout << "Identifying with reference: ";
        identify(*instance);
        
        // Clean up
        delete instance;
    }
    
    return 0;
}