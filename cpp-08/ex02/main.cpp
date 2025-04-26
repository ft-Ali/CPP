#include <iostream>
#include <stack>
#include <deque>
#include "MutantStack.hpp"

void subjectTest() {
    std::cout << "--- Subject example ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

// Test des opérations d'itérateur et const-iterateur
void iteratorTest() {
    std::cout << "--- Iterator tests ---" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 10; ++i)
        mstack.push(i);

    std::cout << "Forward (const_iterator):" << std::endl;
    const MutantStack<int>& cm = mstack;
    for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Empty iteration (should print nothing):" << std::endl;
    MutantStack<int> empty;
    for (MutantStack<int>::iterator it = empty.begin(); it != empty.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

// Test du constructeur de copie et de l'opérateur d'affectation
void copyAssignTest() {
    std::cout << "--- Copy & Assignment tests ---" << std::endl;
    MutantStack<char> ms1;
    for (char c = 'a'; c <= 'e'; ++c)
        ms1.push(c);

    MutantStack<char> ms2(ms1); // copy constructor
    std::cout << "Copy-constructor output:" << std::endl;
    for (MutantStack<char>::iterator it = ms2.begin(); it != ms2.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    MutantStack<char> ms3;
    ms3 = ms1; // assignment
    std::cout << "Assignment output:" << std::endl;
    for (MutantStack<char>::iterator it = ms3.begin(); it != ms3.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

int main() {
    subjectTest();
    iteratorTest();
    copyAssignTest();
    return 0;
}
