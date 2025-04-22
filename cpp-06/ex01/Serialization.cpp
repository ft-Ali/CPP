#include "Serialization.hpp"

// Private constructor implementation (never called, just to satisfy the compiler)
Serializer::Serializer() {}

// Private copy constructor implementation
Serializer::Serializer(const Serializer& other) {
    (void)other; // Unused parameter
}

// Private assignment operator implementation
Serializer& Serializer::operator=(const Serializer& other) {
    (void)other; // Unused parameter
    return *this;
}

// Convert a pointer to an unsigned integer
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convert an unsigned integer back to a pointer
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}