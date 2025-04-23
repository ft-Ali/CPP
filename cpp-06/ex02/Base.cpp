#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Base destructor
Base::~Base() {}

// Function to randomly generate A, B, or C instance
Base* generate(void) {
    // Seed the random number generator if not already done
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // Generate a random number between 0 and 2
    int random = std::rand() % 3;
    
    // Create an instance of A, B, or C based on the random number
    switch (random) {
        case 0:
            std::cout << "Generated class A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated class B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated class C" << std::endl;
            return new C();
        default:
            return NULL; // Should never happen
    }
}

// Function to identify the type using a pointer
void identify(Base* p) {
    // Use dynamic_cast to check the actual type
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Function to identify the type using a reference
// We can't use pointers here, so we use dynamic_cast with references
// If the cast fails, it will throw an exception
void identify(Base& p) {
    // We'll use a try-catch block for each possible type
    // Catch std::exception instead of std::bad_cast to avoid including typeinfo
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Avoid unused variable warning
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b; // Avoid unused variable warning
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c; // Avoid unused variable warning
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
    
    std::cout << "Unknown type" << std::endl;
}