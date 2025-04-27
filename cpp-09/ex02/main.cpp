#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe numbers..." << std::endl;
        return 1;
    }

    try {
        PmergeMe pmerge;
        pmerge.process(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
