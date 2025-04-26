#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

// Function to test the easyfind function with a std::vector
void testVector() {
    std::cout << "--- Test vector ---" << std::endl;

    // Create a vector and populate it with values: 0, 10, 20, 30, 40
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i * 10);
    }

    // Test case 1: Find the first element (0)
    try {
        std::vector<int>::const_iterator it = easyfind<std::vector<int> >(vec, 0);
        std::cout << "Found (first element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 2: Find a middle element (20)
    try {
        std::vector<int>::const_iterator it = easyfind<std::vector<int> >(vec, 20);
        std::cout << "Found (middle element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 3: Find the last element (40)
    try {
        std::vector<int>::const_iterator it = easyfind<std::vector<int> >(vec, 40);
        std::cout << "Found (last element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 4: Try to find a non-existent element (25)
    try {
        std::vector<int>::const_iterator it = easyfind<std::vector<int> >(vec, 25);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Not found: " << e.what() << std::endl;
    }
}

// Function to test the easyfind function with a std::list
void testList() {
    std::cout << "--- Test list ---" << std::endl;

    // Create a list and populate it with values: 2, 4, 6, 8, 10
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) {
        lst.push_back(i * 2);
    }

    // Test case 1: Find the first element (2)
    try {
        std::list<int>::const_iterator it = easyfind<std::list<int> >(lst, 2);
        std::cout << "Found (first element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 2: Find a middle element (6)
    try {
        std::list<int>::const_iterator it = easyfind<std::list<int> >(lst, 6);
        std::cout << "Found (middle element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 3: Find the last element (10)
    try {
        std::list<int>::const_iterator it = easyfind<std::list<int> >(lst, 10);
        std::cout << "Found (last element): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test case 4: Try to find a non-existent element (5)
    try {
        std::list<int>::const_iterator it = easyfind<std::list<int> >(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Not found: " << e.what() << std::endl;
    }
}

// Main function to run the tests
int main() {
    testVector();
    testList(); 
    return 0;
}
