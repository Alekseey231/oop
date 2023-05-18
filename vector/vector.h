#ifndef VECTOR_H
#define VECTOR_H

#include "base_vector.h"
#include <memory>
#include <type_traits>
#include <limits>
#include <iostream>
#include <cmath>
#include <concepts>
#include "../iterator/iterator.h"
#include "../iterator/const_iterator.h"
#include "../iterator/reverse_iterator.h"
#include "../iterator/const_reverse_iterator.h"
#include "../exceptions/exceptions_vector.h"
#include "../concepts/concept.h"


namespace my_math
{
    std::ostream &operator<<(std::ostream &os, const Container auto &container);

    template <typename Type>
    class Iterator;

    template<Math Type>
    class Vector;

    template<Math Type>
    class Vector final: public BaseVector
    {
    public:
        using value_type = Type;
        using iterator = Iterator<Type>;
        using const_iterator = ConstIterator<Type>;
        using reverse_iterator = ReverseIterator<Type>;
        using const_reverse_iterator = ConstReverseIterator<Type>;

        Vector() = default;
        explicit Vector(size_t size_value);
        Vector(size_t size_value, const Vector<Type>::value_type *array);
        Vector(std::initializer_list<Type> lt);
        Vector(const Vector<Type> &vector);
        template<typename Type1>
        Vector(const Vector<Type1> &vector) requires MyConvertableTo<Type, Type1>;
        Vector(Vector<Type> &&vector) noexcept;
        template<typename Type1>
        Vector(Vector<Type1> &&vector) noexcept requires MyConvertableTo<Type, Type1>;
        template<typename IterType>
        Vector(IterType begin, IterType end) requires InputIterator<Type, IterType>;
        Vector(const ContainerInit<Type> auto &container);

        Vector& operator=(const Vector<Type> &vector); 
        template<typename Type1>
        Vector& operator=(const Vector<Type1> &vector) requires MyConvertableTo<Type, Type1>; 
        Vector& operator=(Vector<Type>&& other) noexcept; 
        template<typename Type1>
        Vector& operator=(Vector<Type1>&& other) noexcept requires MyConvertableTo<Type, Type1>;
        Vector& operator=(const ContainerInit<Type> auto &container);

        ~Vector() override = default;

        decltype(auto) length() const;
        decltype(auto) normalize() const;
        bool is_vector_zero() const;
        double angle_between(const Vector &vector) const;
        bool is_сollinear(const Vector<Type>&) const;
        bool is_orthgonal(const Vector<Type>&) const;


        Vector::value_type& at(const int index);
        Vector::value_type& operator[](const int index);

        const Vector::value_type& at(const int index) const;
        const Vector::value_type& operator[](const int index) const; 

        bool operator ==(const Vector &vector) const requires std::floating_point<Type>;
        bool operator ==(const Vector &vector) const;


        template<typename Type1>
        decltype(auto) operator+(const Type1 &num) const requires SumTwoType<Type, Type1>;
        template<typename Type1>
        friend decltype(auto) operator+(const Type1 &num, const Vector<Type> &vec) requires SumTwoType<Type, Type1> 
        {return vec.operator+(num);}
        template<typename Type1>
        decltype(auto) sum_with_num(const Type1 &num) const requires SumTwoType<Type, Type1>;
        template<typename Type1>
        Vector& sum_with_equal(const Type1 &num) requires SumOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator+=(const Type1 &num) requires SumOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator-(const Type1 &num) const requires SubTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) sub_with_num(const Type1 &num) const requires SubTwoType<Type, Type1>;
        template<typename Type1>
        Vector& sub_with_equal(const Type1 &num) requires SubOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator-=(const Type1 &num) requires SubOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator*(const Type1 &num) const requires MulTwoType<Type, Type1>;
        template<typename Type1>
        friend decltype(auto) operator*(const Type1 &num, const Vector<Type> &vec) requires MulTwoType<Type, Type1>
        {return vec.operator*(num);}
        template<typename Type1>
        decltype(auto) mul_with_num(const Type1 &num) const requires MulTwoType<Type, Type1>;
        template<typename Type1>
        Vector& mul_with_equal(const Type1 &num) requires MulOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator*=(const Type1 &num) requires MulOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator/(const Type1 &num) const requires DivTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) div_with_num(const Type1 &num) const requires DivTwoType<Type, Type1>;
        template<typename Type1>
        Vector& div_with_equal(const Type1 &num) requires DivOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator/=(const Type1 &num) requires DivOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator+(const Vector<Type1> &vec) const requires SumTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) sum_with_vec(const Vector<Type1> &vec) const requires SumTwoType<Type, Type1>;
        template<typename Type1>
        Vector& sum_with_equal(const Vector<Type1> &vec) requires SumOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator+=(const Vector<Type1> &vec) requires SumOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator-(const Vector<Type1> &vec) const requires SubTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) sub_with_vec(const Vector<Type1> &vec) const requires SubTwoType<Type, Type1>;
        template<typename Type1>
        Vector& sub_with_equal(const Vector<Type1> &vec) requires SubOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator-=(const Vector<Type1> &vec) requires SubOneType<Type, Type1>;

        Vector operator-() const;
        Vector neg() const;

        template<typename Type1>
        decltype(auto) operator^(const Vector<Type1> &vec) const requires MulTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) degree_with_vec(const Vector<Type1> &vec) const requires MulTwoType<Type, Type1>;
        template<typename Type1>
        Vector& degree_with_equal(const Vector<Type1> &vec) requires MulOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator^=(const Vector<Type1> &vec) requires MulOneType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator*(const Vector<Type1> &vec) const requires SumMulTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) scalar_product(const Vector<Type1> &vec) const requires SumMulTwoType<Type, Type1>;

        template<typename Type1>
        decltype(auto) operator&(const Vector<Type1> &vec) const requires SubMulTwoType<Type, Type1>;
        template<typename Type1>
        decltype(auto) vector_product(const Vector<Type1> &vec) const requires SubMulTwoType<Type, Type1>;
        template<typename Type1>
        Vector& vector_product_equal(const Vector<Type1> &vec) requires SubMulOneType<Type, Type1>;
        template<typename Type1>
        Vector& operator&=(const Vector<Type1> &vec) requires SubMulOneType<Type, Type1>;

        iterator begin() noexcept { return Iterator<Type>(values, size_v); }
        iterator end() noexcept { return Iterator<Type>(values, size_v, size_v); }
        const_iterator begin() const noexcept { return ConstIterator<Type>(values, size_v); }
        const_iterator end() const noexcept { return ConstIterator<Type>(values, size_v, size_v); }
        
        const_iterator cbegin() const noexcept { return ConstIterator<Type>(values, size_v); }
        const_iterator cend() const noexcept { return ConstIterator<Type>(values, size_v, size_v); }

        reverse_iterator rbegin() noexcept { return ReverseIterator<Type>(values, size_v, size_v-1); }
        reverse_iterator rend() noexcept { return ReverseIterator<Type>(values, size_v, -1); }
        const_reverse_iterator rbegin() const noexcept { return ConstReverseIterator<Type>(values, size_v, size_v-1); }
        const_reverse_iterator rend() const noexcept { return ConstReverseIterator<Type>(values, size_v, -1); }

        const_reverse_iterator crbegin() const noexcept { return ConstReverseIterator<Type>(values, size_v, size_v-1); }
        const_reverse_iterator crend() const noexcept { return ConstReverseIterator<Type>(values, size_v, -1); }
        
        value_type sum() const;
        
    private:
        void check_size(int line) const;
        void check_zero_length(int line) const;
        void check_equal_dimension(size_type size1, int line) const;
        void check_dimension(int line) const;
        void check_index(const size_t index, int line) const;
        void check_zero(const Type& num, int line) const;
        template<typename Type1>
        void check_zero(const Type1& num, int line) const;
        void allocate(int line);
        
        std::shared_ptr<Type[]> values = nullptr;
    };
};

#include "./vector.hpp"

#endif