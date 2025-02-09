#include "Bureaucrat.hpp"

int main() {
    // Test 1: Create a Bureaucrat with a valid grade
    try {
        Bureaucrat b1("John Doe", 5);
        if (b1.getName() == "John Doe" && b1.getGrade() == 5) {
            std::cout << "Test 1 passed." << std::endl;
        } else {
            std::cerr << "Test 1 failed." << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Test 1 failed: " << e.what() << std::endl;
    }

    // Test 2: Create a Bureaucrat with an invalid grade (too high)
    try {
        Bureaucrat b2("Jane Doe", 0);
        std::cerr << "Test 2 failed: Exception not thrown." << std::endl;
    } catch (std::exception &e) {
        std::cout << "Test 2 passed: " << e.what() << std::endl;
    }

    // Test 3: Create a Bureaucrat with an invalid grade (too low)
    try {
        Bureaucrat b3("Jim Doe", 151);
        std::cerr << "Test 3 failed: Exception not thrown." << std::endl;
    } catch (std::exception &e) {
        std::cout << "Test 3 passed: " << e.what() << std::endl;
    }

    // Test 4: Increment and decrement grade
    try {
        Bureaucrat b4("Jake Doe", 2);
        b4.incrementGrade();
        if (b4.getGrade() == 1) {
            std::cout << "Test 4.1 passed." << std::endl;
        } else {
            std::cerr << "Test 4.1 failed." << std::endl;
        }
        b4.decrementGrade();
        if (b4.getGrade() == 2) {
            std::cout << "Test 4.2 passed." << std::endl;
        } else {
            std::cerr << "Test 4.2 failed." << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Test 4 failed: " << e.what() << std::endl;
    }

    return 0;
}