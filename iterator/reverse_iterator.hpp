#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace my_math
{
    template<typename Type>
    ReverseIterator<Type>::ReverseIterator(const std::shared_ptr<Type[]>& val, int sz, int ind) : Iterator<Type>(val, sz, ind) {}

    template<typename Type>
    ReverseIterator<Type>::ReverseIterator(Vector<Type>& vector) : Iterator<Type>(vector.begin()){}

    template<typename Type>
    ReverseIterator<Type>::ReverseIterator(const ReverseIterator<Type>& iter) : Iterator<Type>(iter) {}
    
    template<typename Type>
    ReverseIterator<Type>::ReverseIterator(ReverseIterator<Type>&& other) : Iterator<Type>(std::move(other)){}


    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator=(const ReverseIterator<Type>& iter)
    {
        (*this) = this->Iterator<Type>::operator=(iter);
        return *this;
    }
    
    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator=(ReverseIterator<Type>&& iter)
    {
        this->Iterator<Type>::operator=(std::move(iter));
        return *this;
    }

    template<typename Type>
    ReverseIterator<Type>::difference_type ReverseIterator<Type>::operator-(const ReverseIterator<Type> &iter) const
    {
        return iter.Iterator<Type>::operator-(*this);
    }

    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator++()
    {
        this->Iterator<Type>::operator--();
        return *this;
    }

    template<typename Type>
    ReverseIterator<Type> ReverseIterator<Type>::operator++(int)
    {
        ReverseIterator<Type> iter(*this);
        ++(*this);
        return iter;
    }

    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator--()
    {
        this->Iterator<Type>::operator++();
        return *this;
    }

    template<typename Type>
    ReverseIterator<Type> ReverseIterator<Type>::operator--(int)
    {
        ReverseIterator<Type> iter(*this);
        --(*this);
        return iter;
    }

    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator+=(const int num)
    {
        this->Iterator<Type>::operator-=(num);
        return *this;
    }
    
    template<typename Type>
    ReverseIterator<Type>& ReverseIterator<Type>::operator-=(const int num)
    {
        this->Iterator<Type>::operator+=(num);
        return *this;
    }

    template<typename Type>
    ReverseIterator<Type> ReverseIterator<Type>::operator+(const int num) const
    {
        ReverseIterator<Type> it(*this);
        it+=num;
        return it;
    }
    
    template<typename Type>
    ReverseIterator<Type> ReverseIterator<Type>::operator-(const int num) const
    {
        ReverseIterator<Type> it(*this);
        it-=num;
        return it;
    }

}
#endif// ITERATOR_HPP