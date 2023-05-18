#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <ctime>

namespace my_math
{
    template<typename Type>
    Iterator<Type>::Iterator(Vector<Type>& vector) : Iterator(vector.begin()){};

    template<typename Type>
    Iterator<Type>::Iterator(const Iterator<Type>& iter) : BaseIterator(iter.size, iter.index), ptr(iter.ptr){}

    template<typename Type>
    Iterator<Type>::Iterator(Iterator<Type>&& other) : Iterator<Type>::Iterator(other)
    {
        other.ptr.reset();
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator=(Iterator<Type>&& iter)
    {
        this->operator=(iter);
        iter.ptr.reset();
        return *this;
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
    {
        check_available_object(__LINE__);
        size = iter.size;
        index = iter.index;
        ptr = iter.ptr;
        
        return *this;
    }

    template<typename Type>
    Iterator<Type>::difference_type Iterator<Type>::operator-(const Iterator<Type> &iter) const
    {
        return index - iter.index;
    }

    template<typename Type>
    Iterator<Type>::reference Iterator<Type>::operator*()
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return get_ref();
    }

    template<typename Type>
    Iterator<Type>::reference Iterator<Type>::operator*() const
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return get_ref();
    }

    template<typename Type>
    Iterator<Type>::pointer Iterator<Type>::operator->()
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return get_ptr();
    }

    template<typename Type>
    Iterator<Type>::pointer Iterator<Type>::operator->() const
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return get_ptr();
    }

    template<typename Type>
    Iterator<Type>::reference Iterator<Type>::operator[](int index)
    {
        return *(operator+(index));
    }

    template<typename Type>
    Iterator<Type>::reference Iterator<Type>::operator[](int index) const
    {
        return *(operator+(index));
    }

    template<typename Type>
    bool Iterator<Type>::operator==(const Iterator<Type>& other) const
    {
        return this->index == other.index;
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator++()
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        ++index;

        return *this;
    }

    template<typename Type>
    Iterator<Type> Iterator<Type>::operator++(int)
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);
        
        Iterator<Type> it(*this);
        ++(*this);
        return it;
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator+=(const int num)
    {
        check_available_object(__LINE__);

        if(index + num > size)
        {
            time_t cur_time = time(NULL);
            throw ErrorIteratorChangeIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index+num);
        }
        index +=  num; 

        return *this;
    }

    template<typename Type>
    Iterator<Type> Iterator<Type>::operator+(const int num) const
    {
        check_available_object(__LINE__);
        
        Iterator<Type> it(*this);
        it+=num;
        return it;
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator-=(const int num)
    {
        check_available_object(__LINE__);

        if(index - num < -1)
        {
            time_t cur_time = time(NULL);
            throw ErrorIteratorChangeIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index-num);
        }   
        index -= num;
        return *this;
    }

    template<typename Type>
    Iterator<Type> Iterator<Type>::operator-(const int num) const
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        Iterator<Type> it(*this);
        it -= num;
        return it;
    }

    template<typename Type>
    Iterator<Type>& Iterator<Type>::operator--()
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        index-=1;
        return *this;
    }

    template<typename Type>
    Iterator<Type> Iterator<Type>::operator--(int)
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        Iterator<Type> it(*this);
        --it;
        return it;
    }


    template<typename Type>
    Iterator<Type>::operator bool() const noexcept
    {
        return size and index < size;
    }

    template<typename Type>
    Iterator<Type>::reference Iterator<Type>::get_ref() const
    {
        std::shared_ptr<Type[]> temp_ptr(ptr);
        return temp_ptr[index];
    }

    template<typename Type>
    Iterator<Type>::pointer Iterator<Type>::get_ptr() const
    {
        std::shared_ptr<Type[]> temp_ptr(ptr);
        return temp_ptr.get() + index;
    }

    template<typename Type>
    void Iterator<Type>::check_correct_index_change(int line) const
    {
        time_t cur_time = time(NULL);
        if (index >= size or index < 0)
        {
            throw ErrorIteratorChangeIndex(typeid(*this).name(), line, ctime(&cur_time), index);
        }
    }

    template<typename Type>
    void Iterator<Type>::check_correct_index_apply(int line) const
    {
        time_t cur_time = time(NULL);
        if (index >= size or index < 0)
        {
            throw ErrorIteratorApplyIndex(typeid(*this).name(), line, ctime(&cur_time), index);
        }
    }


    template<typename Type>
    void Iterator<Type>::check_available_object(int line) const
    {
        time_t cur_time = time(NULL);
        if(ptr.expired())
        {
            throw ErrorDeleted(typeid(*this).name(), ctime(&cur_time), line);
        }
    }
}
#endif// ITERATOR_HPP