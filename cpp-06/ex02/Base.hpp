#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Base();
};

// Derived classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Function to generate a random instance of A, B, or C
Base* generate(void);

// Function to identify the actual type using pointer
void identify(Base* p);

// Function to identify the actual type using reference
void identify(Base& p);

#endif