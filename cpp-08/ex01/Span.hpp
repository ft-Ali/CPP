#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template<typename InputIt>
    void addNumber(InputIt begin, InputIt end) {
        typename std::iterator_traits<InputIt>::difference_type dist = std::distance(begin, end);
        if (_numbers.size() + dist > _N) {
            throw std::out_of_range("Span is full");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int      _N;
    std::vector<int>  _numbers;
};

#endif