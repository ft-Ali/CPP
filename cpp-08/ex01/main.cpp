#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include "Span.hpp"

void testSubject() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void testExceptions() {
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    } catch (const std::exception& e) {
        std::cout << "Expected exception (full): " << e.what() << std::endl;
    }
    try {
        Span sp(5);
        sp.addNumber(10);
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Expected exception (not enough): " << e.what() << std::endl;
    }
}

void testLargeRange() {
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(std::rand());
    }
    Span big(10000);
    big.addNumber(v.begin(), v.end());
    std::cout << "Big shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Big longest span: " << big.longestSpan() << std::endl;
}

int main() {
    testSubject();
    testExceptions();
    testLargeRange();
    return 0;
}
