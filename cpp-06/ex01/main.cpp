#include "Serialization.hpp"
#include <iostream>

int main() {
    // Create a Data object with custom values
    Data original(42, 'X', 99.99);
    
    // Print the original data and its address
    std::cout << "Original Data object:" << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "Values: int=" << original.intValue
              << ", char=" << original.charValue
              << ", double=" << original.doubleValue << std::endl;
    std::cout << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    // Deserialize back to a pointer
    Data* deserialized = Serializer::deserialize(serialized);
    
    // Print the deserialized data and its address
    std::cout << "Deserialized Data object:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Values: int=" << deserialized->intValue
              << ", char=" << deserialized->charValue
              << ", double=" << deserialized->doubleValue << std::endl;
    std::cout << std::endl;
    
    // Check if the pointers are equal
    if (&original == deserialized) {
        std::cout << "Serialization and deserialization successful: pointers match!" << std::endl;
    } else {
        std::cout << "Error: pointers don't match!" << std::endl;
    }
    
    return 0;
}