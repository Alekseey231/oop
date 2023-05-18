#ifndef CONST_REVERSE_ITERATOR_H
#define CONST_REVERSE_ITERATOR_H

#include "../concepts/concept.h"
#include "../iterator/const_iterator.h"

namespace my_math
{
    template<Math Type>
    class Vector;

    template<typename Type>
    class ConstReverseIterator: public ConstIterator<Type>
    {
        friend class Vector<Type>;
        public:
            using iterator_category = std::random_access_iterator_tag;

            using value_type = Type;
            using difference_type = int;
            using pointer = Type*;
            using reference = Type&;
            using const_reference = const Type&;
            using const_pointer = const Type&;

        public:
            ConstReverseIterator() = default;
            ConstReverseIterator(const Vector<Type>&);
            ConstReverseIterator(const ConstReverseIterator<Type>& iter);
            ConstReverseIterator(const ReverseIterator<Type>& other);
            ConstReverseIterator(ConstReverseIterator<Type>&& other);
            
            ConstReverseIterator<Type>& operator=(const ConstReverseIterator<Type>& iter);
            ConstReverseIterator<Type>& operator=(ConstReverseIterator<Type>&& iter);

            ConstReverseIterator& operator++();
            ConstReverseIterator operator++(int);
            ConstReverseIterator<Type> operator+(const int num) const;
            friend ConstReverseIterator<Type> operator+(const int num, ConstReverseIterator<Type> iter) {return iter.operator+(num);};
            ConstReverseIterator<Type>& operator+=(const int num);

            ConstReverseIterator<Type> operator--(int);
            ConstReverseIterator<Type>& operator--();
            ConstReverseIterator<Type> operator-(const int num) const;
            ConstReverseIterator<Type>& operator-=(const int num);  

            ConstReverseIterator<Type>::difference_type operator-(const ConstReverseIterator<Type> &iter) const;
        private:
            ConstReverseIterator(const std::shared_ptr<Type[]>& val, int sz, int ind = 0); 
    };
}

#include "./const_reverse_iterator.hpp"

#endif