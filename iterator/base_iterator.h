#ifndef BASE_ITER_H
#define BASE_ITER_H

#include <iostream>

class BaseIterator
{
public:
    using size_type = int;
    BaseIterator() = default;
    BaseIterator(size_type count, size_type ind) noexcept : index(ind), size(count) {};
    virtual ~BaseIterator() = 0;
protected:
    size_type index;
    size_type size;
};

BaseIterator::~BaseIterator() =  default;

#endif