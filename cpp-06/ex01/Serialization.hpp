#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>

// Data structure with some members
struct Data {
    int intValue;
    char charValue;
    double doubleValue;
    
    // Constructor for convenience
    Data(int i = 0, char c = 'A', double d = 3.14) 
        : intValue(i), charValue(c), doubleValue(d) {}
};

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer();
    
    // Private copy constructor and assignment operator
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    
public:
    // Static methods for serialization and deserialization
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif