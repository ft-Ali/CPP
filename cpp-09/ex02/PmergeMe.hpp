#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void process(int argc, char** argv);

private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    void parseArguments(int argc, char** argv);
    void printSequence(const std::string& prefix, const std::vector<int>& container) const;
    void mergeInsertSortVector(std::vector<int>& vec, int left, int right);
    void mergeVector(std::vector<int>& vec, int left, int mid, int right);

    void mergeInsertSortDeque(std::deque<int>& deq, int left, int right);
    void mergeDeque(std::deque<int>& deq, int left, int mid, int right);

    bool isNumber(const std::string& str) const;
};

#endif
