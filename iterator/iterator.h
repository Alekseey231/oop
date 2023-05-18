#ifndef ITERATOR_H
#define ITERATOR_H

#include <compare>
#include <iostream>
#include <memory>
#include <iterator>
#include <initializer_list>
#include "../vector/vector.h"
#include "base_iterator.h"
#include "../exceptions/exceptions_iterator.h"
#include "../concepts/concept.h"

namespace my_math
{
    template<Math Type>
    class Vector;

    template<typename Type>
    class ConstIterator;
    
    template<typename Type>
    class Iterator : public BaseIterator
    {
        friend class Vector<Type>;
        friend class ConstIterator<Type>;
        public:
            using iterator_category = std::random_access_iterator_tag;

            using value_type = Type;
            using difference_type = int;
            using pointer = Type*;
            using reference = Type&;

        public:
            Iterator() = default;
            Iterator(Vector<Type>&);
            Iterator(const Iterator<Type>&);
            Iterator(Iterator<Type>&& other);
            
            Iterator<Type>& operator=(const Iterator<Type>& iter);
            Iterator<Type>& operator=(Iterator<Type>&& iter);

            reference operator*();
            reference operator*() const;

            pointer operator->();
            pointer operator->() const;

            operator bool() const noexcept;

            reference operator[](int index);
            reference operator[](int index) const;

            Iterator& operator++();
            Iterator operator++(int);
            Iterator<Type> operator+(const int num) const;  
            friend Iterator<Type> operator+(const int num, Iterator<Type> iter) {return iter.operator+(num);};
            Iterator<Type>& operator+=(const int num);

            Iterator<Type> operator--(int);
            Iterator<Type>& operator--();
            Iterator<Type> operator-(const int num) const;
            Iterator<Type>& operator-=(const int num);

            Iterator<Type>::difference_type operator-(const Iterator<Type> &iter) const;

            auto operator<=>(const Iterator<Type>& iter) const { return this->index <=> iter.index;};
            bool operator==(const Iterator<Type>& iter) const;

            ~Iterator() override = default;

            explicit operator int() const {return index;};
        protected:
            Iterator(const std::shared_ptr<Type[]>& val, int sz, int ind = 0):  BaseIterator(sz, ind), ptr(val) {}

        private:
            std::weak_ptr<Type[]> ptr;
            Iterator<Type>::pointer get_ptr() const;
            Iterator<Type>::reference get_ref() const;
            void check_correct_index_apply(int line) const;
            void check_correct_index_change(int line) const;
            void check_available_object(int line) const;
    };
};

#include "iterator.hpp"
#endif
