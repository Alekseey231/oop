#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "../concepts/concept.h"
#include "../iterator/iterator.h"

namespace my_math
{
    template<Math Type>
    class Vector;

    template<typename Type>
    class ConstReverseIterator;

    template<typename Type>
    class ReverseIterator: public Iterator<Type>
    {
        friend class Vector<Type>;
        friend class ConstReverseIterator<Type>;
        public:
            using iterator_category = std::random_access_iterator_tag;

            using value_type = Type;
            using difference_type = int;
            using pointer = Type*;
            using reference = Type&;

        public:
            ReverseIterator() = default;
            ReverseIterator(Vector<Type>&);
            ReverseIterator(const ReverseIterator<Type>& iter);
            ReverseIterator(ReverseIterator<Type>&& other);
            
            ReverseIterator<Type>& operator=(const ReverseIterator<Type>& iter);
            ReverseIterator<Type>& operator=(ReverseIterator<Type>&& iter);

            ReverseIterator& operator++();
            ReverseIterator operator++(int);
            ReverseIterator<Type> operator+(const int num) const;
            friend ReverseIterator<Type> operator+(const int num, ReverseIterator<Type> iter) {return iter.operator+(num);};
            ReverseIterator<Type>& operator+=(const int num);

            ReverseIterator<Type> operator--(int);
            ReverseIterator<Type>& operator--();
            ReverseIterator<Type> operator-(const int num) const;
            ReverseIterator<Type>& operator-=(const int num);

            ReverseIterator<Type>::difference_type operator-(const ReverseIterator<Type> &iter) const;
        private:
            ReverseIterator(const std::shared_ptr<Type[]>& val, int sz, int ind = 0); 
    };
}

#include "./reverse_iterator.hpp"

#endif