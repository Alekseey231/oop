#ifndef CONST_REVERSE_ITERATOR_HPP
#define CONST_REVERSE_ITERATOR_HPP

namespace my_math
{
    template<typename Type>
    ConstReverseIterator<Type>::ConstReverseIterator(const std::shared_ptr<Type[]>& val, int sz, int ind) : ConstIterator<Type>(val, sz, ind) {}

    template<typename Type>
    ConstReverseIterator<Type>::ConstReverseIterator(const Vector<Type>& vector) : ConstIterator<Type>(vector.begin()){}

    template<typename Type>
    ConstReverseIterator<Type>::ConstReverseIterator(const ConstReverseIterator<Type>& iter) : ConstIterator<Type>(iter) {}

    template<typename Type>
    ConstReverseIterator<Type>::ConstReverseIterator(const ReverseIterator<Type>& iter) : ConstIterator<Type>(iter.size, iter.index,  ptr(iter.ptr)){}
    
    template<typename Type>
    ConstReverseIterator<Type>::ConstReverseIterator(ConstReverseIterator<Type>&& other) : ConstIterator<Type>(std::move(other)){}


    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator=(const ConstReverseIterator<Type>& iter)
    {
        (*this) = this->ConstIterator<Type>::operator=(iter);
        return *this;
    }
    
    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator=(ConstReverseIterator<Type>&& iter)
    {
        this->ConstIterator<Type>::operator=(std::move(iter));
        return *this;
    }

    template<typename Type>
    ConstReverseIterator<Type>::difference_type ConstReverseIterator<Type>::operator-(const ConstReverseIterator<Type> &iter) const
    {
        return iter.ConstIterator<Type>::operator-(*this);
    }

    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator++()
    {
        this->ConstIterator<Type>::operator--();
        return *this;
    }

    template<typename Type>
    ConstReverseIterator<Type> ConstReverseIterator<Type>::operator++(int)
    {
        ConstReverseIterator<Type> iter(*this);
        ++(*this);
        return iter;
    }

    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator--()
    {
        this->ConstIterator<Type>::operator++();
        return *this;
    }

    template<typename Type>
    ConstReverseIterator<Type> ConstReverseIterator<Type>::operator--(int)
    {
        ConstReverseIterator<Type> iter(*this);
        --(*this);
        return iter;
    }

    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator+=(const int num)
    {
        this->ConstIterator<Type>::operator-=(num);
        return *this;
    }
    
    template<typename Type>
    ConstReverseIterator<Type>& ConstReverseIterator<Type>::operator-=(const int num)
    {
        this->ConstIterator<Type>::operator+=(num);
        return *this;
    }

    template<typename Type>
    ConstReverseIterator<Type> ConstReverseIterator<Type>::operator+(const int num) const
    {
        ConstReverseIterator<Type> it(*this);
        it+=num;
        return it;
    }
    
    template<typename Type>
    ConstReverseIterator<Type> ConstReverseIterator<Type>::operator-(const int num) const
    {
        ConstReverseIterator<Type> it(*this);
        it-=num;
        return it;
    }

};
#endif// ITERATOR_HPP