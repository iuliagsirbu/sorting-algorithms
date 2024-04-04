#ifndef SORTING_ALGORITHMS_SORTINGEXCEPTION_H
#define SORTING_ALGORITHMS_SORTINGEXCEPTION_H

#include <stdexcept>
#include <string>

class SortingException : public std::runtime_error {
public:
    explicit SortingException(const std::string &msg);
};


#endif //SORTING_ALGORITHMS_SORTINGEXCEPTION_H
