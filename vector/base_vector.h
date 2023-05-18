#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include <cstddef>

class BaseVector
{
    public:
        using size_type = std::size_t;

        BaseVector(size_type count = 0) : size_v(count) {};
        virtual ~BaseVector() = 0;
        virtual bool isEmpty() const noexcept {return size_v == 0;};
        virtual size_type size() const  noexcept {return size_v;};
    protected:
        size_type size_v = 0;
};

#include "base_vector.hpp"

#endif