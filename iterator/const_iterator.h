#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include <compare>
#include <iostream>
#include <memory>
#include <iterator>
#include <initializer_list>
#include "../vector/vector.h"
#include "base_iterator.h"
#include "../exceptions/exceptions_iterator.h"

namespace my_math
{

    template<Math Type>
    class Vector;
    
    template<typename Type>
    class Iterator;

    template<typename Type>
    class ConstIterator : public BaseIterator
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
            ConstIterator() = default;
            ConstIterator(const ConstIterator<Type>&);
            ConstIterator(ConstIterator<Type>&&);
            ConstIterator(const Iterator<Type>& other);
            ConstIterator(const Vector<Type>&);

            ConstIterator<Type>& operator=(const ConstIterator<Type>& iter);
            ConstIterator<Type>& operator=(ConstIterator<Type>&& iter);

            const_reference const operator*() const;
            const_pointer operator->() const;

            operator bool() const;
            const_reference operator[](int index) const;

            ConstIterator& operator++();
            ConstIterator operator++(int);
            ConstIterator<Type> operator+(const int num) const;
            friend ConstIterator<Type> operator+(const int num, ConstIterator<Type> iter) {return iter.operator+(num);};
            ConstIterator<Type>& operator+=(const int num);

            ConstIterator<Type> operator--(int);
            ConstIterator<Type>& operator--();
            ConstIterator<Type> operator-(const int num) const;
            ConstIterator<Type>& operator-=(const int num);

            ConstIterator<Type>::difference_type operator-(const ConstIterator<Type> &iter) const;

            auto operator<=>(const ConstIterator<Type>& iter) const { return this->index <=> iter.index;};
            bool operator==(const ConstIterator<Type>& iter) const;

            ~ConstIterator() override = default;

            explicit operator int() const {return index;};
        
        protected:
            ConstIterator(const std::shared_ptr<Type[]>& val, int sz, int ind = 0):  BaseIterator(sz, ind), ptr(val) {}

        private:
            std::weak_ptr<Type[]> ptr;

            ConstIterator<Type>::pointer get_ptr() const;
            ConstIterator<Type>::reference get_ref() const;
            void check_correct_index_apply(int line) const;
            void check_correct_index_change(int line) const;
            void check_available_object(int line) const;
            
    };
};

#include "./const_iterator.hpp"

#endif