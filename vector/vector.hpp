#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <ctime>
#include "../concepts/concept.h"
namespace my_math
{
    template<typename Type>
    Vector<Type>::Vector(size_t size_v) : BaseVector(size_v)
    {
        allocate(__LINE__);
    }

    template<typename Type>
    Vector<Type>::Vector(size_t size_value, const Vector<Type>::value_type *array) : BaseVector(size_value)
    {
        allocate(__LINE__);

        size_t i = 0;
        for(Iterator<Type> iter = begin(); iter; ++iter, ++i)
        {
            *iter = array[i];
        }
    }

    template<typename Type>
    Vector<Type>::Vector(std::initializer_list<Type> lt)  : BaseVector(lt.size())
    {
        if (!size_v)
            return;

        allocate(__LINE__);

        for (Iterator<Type> iter = begin(); auto elem : lt)
        {
            *(iter++) = elem;
        }
    }

    template<typename Type>
    Vector<Type>::Vector(const Vector<Type> &vector) : BaseVector(vector.size_v)
    {
        allocate(__LINE__);
        
        for (Iterator<Type> dst = begin(); auto elem : vector)
        {
            *(dst++) = elem;
        }
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>::Vector(const Vector<Type1> &vector) requires MyConvertableTo<Type, Type1> : BaseVector(vector.size())
    {
        allocate(__LINE__);
        
        for (Iterator<Type> dst = begin(); auto elem : vector)
        {
            *(dst++) = elem;
        }
    }

    template<typename Type>
    Vector<Type>::Vector(const ContainerInit<Type> auto &container) : BaseVector(container.size())
    {
        allocate(__LINE__);

        for(Iterator<Type> dst = begin(); auto elem : container)
        {
            *(dst++) = elem;
        }
    }

    template<typename Type>
    Vector<Type>::Vector(Vector<Type> &&vector) noexcept : BaseVector(vector.size_v), values(vector.values)
    {
        vector.values.reset();
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>::Vector(Vector<Type1> &&vector) noexcept requires MyConvertableTo<Type, Type1> : BaseVector(vector.size_v), values(vector.values)
    {
        vector.values.reset();
    }

    template<typename Type>
    template<typename IterType> 
    Vector<Type>::Vector(IterType start, IterType end) requires InputIterator<Type, IterType> : BaseVector(end-start)
    {
        allocate(__LINE__);
        
        std::cout << size_v << std::endl;
        for(auto it = begin(); start != end; ++start, ++it)
        {
            *it = *start;
        }
    }

    template<typename Type>
    Vector<Type>& Vector<Type>::operator=(const Vector<Type> &vector)
    {
        std::cout << "1222\n";
        size_v = vector.size();
        allocate(__LINE__);

        for(auto it = begin(); auto elem : vector)
        {
            *(it++) = elem;
        }
        return *this;
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator=(const Vector<Type1> &vector) requires MyConvertableTo<Type, Type1>
    {
        size_v = vector.size();
        allocate(__LINE__);

        for(auto it = begin(); auto elem : vector)
        {
            *(it++) = elem;
        }
        return *this;
    }

    template<typename Type>
    Vector<Type>& Vector<Type>::operator=(const ContainerInit<Type> auto &container)
    {
        size_v = container.size();
        allocate(__LINE__);

        for(auto it = begin(); auto elem : container)
        {
            *(it++) = elem;
        }
        return *this;
    }

    template <typename Type>
    Vector<Type>& Vector<Type>::operator=(Vector<Type>&& other) noexcept 
    {
        size_v = other.size_v;
        values = other.values;
        other.values.reset();

        return *this;
    }

    template <typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator=(Vector<Type1>&& other) noexcept requires MyConvertableTo<Type, Type1>
    {
        size_v = other.size_v;
        values = other.values;
        other.values.reset();

        return *this;
    }

    template<typename Type>
    bool Vector<Type>::operator ==(const Vector &vector) const
    {
        check_size(__LINE__);
        vector.check_size(__LINE__);

        bool is_equal = true;
        if(size_v != vector.size())
        {
            is_equal = false;
        }

        for(auto iter = begin(); auto elem : vector)
        {
            if(*(iter++) != elem)
            {
                is_equal = false;
            }
        }

        return is_equal;
    }


    template<typename Type>
    bool Vector<Type>::operator ==(const Vector &vector) const requires std::floating_point<Type>
    {
        check_size(__LINE__);
        vector.check_size(__LINE__);
  
        bool is_equal = true;
        if(size_v != vector.size())
        {
            is_equal = false;
        }

        
        for(Iterator<Type> iter = begin(); auto elem : vector)
        {
            if(std::abs(*(iter++) - elem) > std::numeric_limits<double>::epsilon())
            {
                is_equal = false;
            }
        }

        return is_equal;
    }


    template<typename Type>
    decltype(auto) Vector<Type>::length() const
    {
        check_size(__LINE__);

        Type res = 0;
        for(auto iter = begin(); iter != end(); ++iter)
        {
            res += (*iter) * (*iter);
        }
        return sqrt(res);
    }

    template<typename Type>
    Vector<Type>::value_type& Vector<Type>::at(const int index)
    {
        auto iter = begin();
        time_t cur_time = time(NULL);
        try
        {
            return iter[index];
        }
        catch(const ErrorIteratorApplyIndex &e)
        {
            throw ErrorVectorIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index);
        }
    }


    template<typename Type>
    Vector<Type>::value_type& Vector<Type>::operator[](const int index)
    {
        return at(index);
    }

    template<typename Type>
    const Vector<Type>::value_type& Vector<Type>::at(const int index) const
    {
        auto iter = begin();
        time_t cur_time = time(NULL);
        try
        {
            return iter[index];
        }
        catch(const ErrorIteratorApplyIndex& e)
        {
            throw ErrorVectorIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index);
        }
    }

    template<typename Type>
    const Vector<Type>::value_type& Vector<Type>::operator[](const int index) const
    {
        return at(index);
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator+(const Type1 &num) const requires SumTwoType<Type, Type1>
    {
        check_size(__LINE__);
        
        Vector<decltype(at(0) + num)> res(size_v);

        
        for(auto iter = begin(); auto &elem : res)
        {
            elem = *(iter++) + num;
        }
        
        return res;
    }
    
    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::sum_with_num(const Type1 &num) const requires SumTwoType<Type, Type1>
    {
        return operator+(num);    
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::sum_with_equal(const Type1 &num) requires SumOneType<Type, Type1>
    {
        return operator+=(num);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::operator+=(const Type1 &num) requires SumOneType<Type, Type1>
    {
        check_size(__LINE__);

        for(auto &elem : *this)
        {
            elem+=num;
        }

        return *this;
    }


    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator-(const Type1 &num) const requires SubTwoType<Type, Type1>
    {
        return operator+(-num);
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::sub_with_num(const Type1 &num) const requires SubTwoType<Type, Type1>
    {
        return operator-(num);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::sub_with_equal(const Type1 &num) requires SubOneType<Type, Type1>
    {
        return operator-=(num);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::operator-=(const Type1 &num) requires SubOneType<Type, Type1>
    {
        return operator+=(-num);
    }


    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator*(const Type1 &num) const requires MulTwoType<Type, Type1>
    {
        check_size(__LINE__);

        Vector<decltype(at(0) * num)> res(size_v);

        
        for(auto iter = begin(); auto &elem : res)
        {
            elem = *(iter++) * num;
        }
        
        return res;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::mul_with_num(const Type1 &num) const requires MulTwoType<Type, Type1>
    {
        return operator*(num);    
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::mul_with_equal(const Type1 &num) requires MulOneType<Type, Type1>
    {
        return operator*=(num);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::operator*=(const Type1 &num) requires MulOneType<Type, Type1>
    {
        check_size(__LINE__);

        for(auto &elem : *this)
        {
            elem*=num;
        }

        return *this;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator/(const Type1 &num) const requires DivTwoType<Type, Type1>
    {
        check_zero(num, __LINE__);

        return operator*(1./num);
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::div_with_num(const Type1 &num) const requires DivTwoType<Type, Type1>
    {
        return operator/(num);
    }

    template <typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::div_with_equal(const Type1 &num) requires DivOneType<Type, Type1>
    {
        return operator/=(num);
    }

    template <typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator/=(const Type1 &num) requires DivOneType<Type, Type1>
    {
        check_size(__LINE__);
        check_zero(num, __LINE__);

        for(auto &elem : *this)
        {
            elem/=num;
        }

        return *this;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator+(const Vector<Type1> &vec) const requires SumTwoType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);

        Vector<decltype(at(0) + vec.at(0))> res(size_v);

        auto iter = begin();
        auto iter_vec = vec.begin();
        
        for(auto &elem : res)
        {
            elem = *(iter++) + *(iter_vec++);
        }
        
        return res;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::sum_with_vec(const Vector<Type1> &vec) const requires SumTwoType<Type, Type1>
    {
        return operator+(vec);    
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator+=(const Vector<Type1> &vec) requires SumOneType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);
        
        for(auto iter = vec.begin(); auto &elem : *this)
        {
            elem += *(iter++);
        }
        
        return *this;
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::sum_with_equal(const Vector<Type1> &vec) requires SumOneType<Type, Type1>
    {
        return operator+=(vec);    
    }


    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator-(const Vector<Type1> &vec) const requires SubTwoType<Type, Type1>
    {
        return operator+(-vec);
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::sub_with_vec(const Vector<Type1> &vec) const requires SubTwoType<Type, Type1>
    {
        return operator-(vec);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::sub_with_equal(const Vector<Type1> &vec) requires SubOneType<Type, Type1>
    {
        return operator-=(vec);
    }

    template <typename Type>
    template <typename Type1>
    Vector<Type>& Vector<Type>::operator-=(const Vector<Type1> &vec) requires SubOneType<Type, Type1>
    {
        return operator+=(-vec);
    }

    template <typename Type>
    Vector<Type> Vector<Type>::operator-() const
    {
        return operator*(-1);
    }

    template <typename Type>
    Vector<Type> Vector<Type>::neg() const
    {
        return operator-();
    }

    //

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator^(const Vector<Type1> &vec) const requires MulTwoType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);

        Vector<decltype(at(0) * vec.at(0))> res(size_v);

        auto iter = begin();
        auto iter_vec = vec.begin();
        
        for(auto &elem : res)
        {
            elem = *(iter++) * *(iter_vec++);
        }
        
        return res;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::degree_with_vec(const Vector<Type1> &vec) const requires MulTwoType<Type, Type1>
    {
        return operator*(vec);    
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator^=(const Vector<Type1> &vec) requires MulOneType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);
        
        for(auto iter = vec.begin(); auto &elem : *this)
        {
            elem *= (*(iter++));
        }
        
        return *this;
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::degree_with_equal(const Vector<Type1> &vec) requires MulOneType<Type, Type1>
    {
        return operator^=(vec);    
    }

    //scalar
    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator*(const Vector<Type1> &vec) const requires SumMulTwoType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);

        auto res = (*this) ^ vec;

        return res.sum();
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::scalar_product(const Vector<Type1> &vec) const requires SumMulTwoType<Type, Type1>
    {
        return operator*(vec);    
    }

    //

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::operator&(const Vector<Type1> &vec) const requires SubMulTwoType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);

        check_dimension(__LINE__);

        Vector<decltype(at(0) * vec.at(0))> res(size_v);

        res.at(0) = at(1) * vec.at(2) - at(2)  * vec.at(1);
        res.at(1) = at(2) * vec.at(0) - at(0)  * vec.at(2);
        res.at(2) = at(0) * vec.at(1) - at(1)  * vec.at(0);

        return res;
    }

    template<typename Type>
    template<typename Type1>
    decltype(auto) Vector<Type>::vector_product(const Vector<Type1> &vec) const requires SubMulTwoType<Type, Type1>
    {
        return operator&(vec);
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::operator&=(const Vector<Type1> &vec) requires SubMulOneType<Type, Type1>
    {
        check_equal_dimension(vec.size(), __LINE__);

        check_dimension(__LINE__);

        Vector<decltype(at(0) * vec.at(0))> res(size_v);

        res.at(0) = at(1) * vec.at(2) - at(2)  * vec.at(1);
        res.at(1) = at(2) * vec.at(0) - at(0)  * vec.at(2);
        res.at(2) = at(0) * vec.at(1) - at(1)  * vec.at(0);

        *this = std::move(res);

        return *this;
    }

    template<typename Type>
    template<typename Type1>
    Vector<Type>& Vector<Type>::vector_product_equal(const Vector<Type1> &vec) requires SubMulOneType<Type, Type1>
    {
        return operator&=(vec);
    }

    template<typename Type>
    decltype(auto) Vector<Type>::normalize() const
    {
        check_size(__LINE__);
        check_zero_length(__LINE__);

        auto len = length();
        
        return operator/(len);
    }

    template<typename Type>
    double Vector<Type>::angle_between(const Vector &vector) const
    {
        check_equal_dimension(vector.size(), __LINE__);
        check_zero_length(__LINE__);
        vector.check_zero_length(__LINE__);

        auto angle = ((*this)^vector).sum() / (length() * vector.length());
        return acos(angle) * 180 / M_PI;
    }

    template<typename Type>
    bool Vector<Type>::is_vector_zero() const
    {
        return length()==0;
    }

    template<typename Type>
    Vector<Type>::value_type Vector<Type>::sum() const
    {
        check_size(__LINE__);
        Type res = 0;
        for(auto elem : *this)
        {
            res += elem;
        }
        return res;
    }

    template<typename Type>
    bool Vector<Type>::is_сollinear(const Vector<Type> &vector) const
    {
        check_size(__LINE__);
        bool res = false;

        if((this->angle_between(vector)) < std::numeric_limits<double>::epsilon())
        {
            res = true;
        }
        return res;

    }
    template<typename Type>
    bool Vector<Type>::is_orthgonal(const Vector<Type> &vector) const
    {
        check_size(__LINE__);
        bool res = false;

        if((this->angle_between(vector) - 90) < std::numeric_limits<double>::epsilon())
        {
            res = true;
        }
        return res;
    }

    template<typename Type>
    void Vector<Type>::check_zero_length(int line) const
    {
        time_t cur_time = time(NULL);
        if(is_vector_zero())
        {
            throw ErrorZeroLength(typeid(*this).name(), line, ctime(&cur_time));
        }
    }


    template<typename Type>
    void Vector<Type>::check_equal_dimension(Vector<Type>::size_type size1, int line) const
    {
        time_t cur_time = time(NULL);
        if(size_v != size1 or size_v == 0)
        {
            throw ErrorNotEqualDimension(typeid(*this).name(), line, ctime(&cur_time));
        }
    }

    template<typename Type>
    void Vector<Type>::check_dimension(int line) const
    {
        time_t cur_time = time(NULL);
        if(size_v != 3)
        {
            throw ErrorInvalidDimension(typeid(*this).name(), line, size_v, ctime(&cur_time));
        }
    }

    template<typename Type>
    void Vector<Type>::check_zero(const Type& num, int line) const
    {
        time_t cur_time = time(NULL);
        if(!num)
        {
            throw ErrorZeroDiv(typeid(*this).name(), line, ctime(&cur_time));
        }
    }


    template<typename Type>
    template<typename Type1>
    void Vector<Type>::check_zero(const Type1& num, int line) const 
    {
        time_t cur_time = time(NULL);
        if(!num)
        {
            throw ErrorZeroDiv(typeid(*this).name(), line, ctime(&cur_time));
        }
    }


    template<typename Type>
    void Vector<Type>::check_size(int line) const
    {
        time_t cur_time = time(NULL);
        if(!size_v)
        {
            throw ErrorEmpty(typeid(*this).name(), line, ctime(&cur_time));
        }
    }

    template<typename Type>
    void Vector<Type>::check_index(const size_t index, int line) const
    {
        time_t cur_time = time(NULL);
        if(index >= this->size_v)
        {
            throw ErrorVectorIndex(typeid(*this).name(), line, ctime(&cur_time));
        }
    }


    template<typename Type>
    void Vector<Type>::allocate(int line)
    {
        time_t cur_time = time(NULL);
        try
        {
            values = std::make_shared<Type[]>(size_v);
        }
        catch(std::bad_alloc &exception)
        {
            throw ErrorMemory(typeid(*this).name(), line, ctime(&cur_time));
        }
    }

    std::ostream &operator<<(std::ostream &os, const Container auto &container)
    {
        std::cout << "( ";
        for (auto elem : container)
            std::cout << elem << " ";
        std::cout << ")";
        return os;
    }
    
    /*template<Math Type, typename Type1>
    auto operator+(const Type1 &num, const Vector<Type> &vec) requires SumTwoType<Type, Type1>
    {
        auto my_vec = vec.operator+(num);
        return my_vec;
    }*/
};
#endif