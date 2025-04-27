#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string& str) const {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it))
            return false;
    }
    return !str.empty();
}

void PmergeMe::parseArguments(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (!isNumber(s))
            throw std::runtime_error("Error");
        long n = std::strtol(argv[i], NULL, 10);
        if (n < 0 || n > 2147483647)
            throw std::runtime_error("Error");
        _vector.push_back(static_cast<int>(n));
        _deque.push_back(static_cast<int>(n));
    }
}

void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& container) const {
    std::cout << prefix;
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j])
            temp.push_back(vec[i++]);
        else
            temp.push_back(vec[j++]);
    }
    while (i <= mid)
        temp.push_back(vec[i++]);
    while (j <= right)
        temp.push_back(vec[j++]);
    for (int k = left; k <= right; ++k)
        vec[k] = temp[k - left];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeInsertSortVector(vec, left, mid);
    mergeInsertSortVector(vec, mid + 1, right);
    mergeVector(vec, left, mid, right);
}

void PmergeMe::mergeDeque(std::deque<int>& deq, int left, int mid, int right) {
    std::deque<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (deq[i] <= deq[j])
            temp.push_back(deq[i++]);
        else
            temp.push_back(deq[j++]);
    }
    while (i <= mid)
        temp.push_back(deq[i++]);
    while (j <= right)
        temp.push_back(deq[j++]);
    for (int k = left; k <= right; ++k)
        deq[k] = temp[k - left];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeInsertSortDeque(deq, left, mid);
    mergeInsertSortDeque(deq, mid + 1, right);
    mergeDeque(deq, left, mid, right);
}

void PmergeMe::process(int argc, char** argv) {
    parseArguments(argc, argv);

    printSequence("Before: ", _vector);

    clock_t startVector = clock();
    mergeInsertSortVector(_vector, 0, _vector.size() - 1);
    clock_t endVector = clock();

    clock_t startDeque = clock();
    mergeInsertSortDeque(_deque, 0, _deque.size() - 1);
    clock_t endDeque = clock();

    printSequence("After: ", _vector);

    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
