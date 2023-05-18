#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

namespace my_math
{
    template<typename Type>
    ConstIterator<Type>::ConstIterator(const Vector<Type>& vector) : ConstIterator(vector.begin()){};
    
    template<typename Type>
    ConstIterator<Type>::ConstIterator(const ConstIterator<Type>& iter) : BaseIterator(iter.size, iter.index), ptr(iter.ptr){}

    template<typename Type>
    ConstIterator<Type>::ConstIterator(const Iterator<Type>& iter) : BaseIterator(iter.size, iter.index), ptr(iter.ptr){}

    template<typename Type>
    ConstIterator<Type>::ConstIterator(ConstIterator<Type>&& other) : ConstIterator(other)
    {
        other.ptr.reset();
    }

    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator=(const ConstIterator<Type>& iter)
    {
        check_available_object(__LINE__);

        size = iter.size;
        index = iter.index;
        ptr = iter.ptr;
        
        return *this;
    }

    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator=(ConstIterator<Type>&& iter)
    {
        this->operator=(iter);
        iter.ptr.reset();
        return *this;
    }

    template<typename Type>
    ConstIterator<Type>::const_reference ConstIterator<Type>::operator*() const
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return get_ref();
    }

    template<typename Type>
    ConstIterator<Type>::const_pointer ConstIterator<Type>::operator->() const
    {
        check_available_object(__LINE__);
        check_correct_index_apply(__LINE__);

        return this->get_ptr();
    }

    template<typename Type>
    ConstIterator<Type>::const_reference ConstIterator<Type>::operator[](int index) const
    {
        return *(operator+(index));
    }

    template<typename Type>
    bool ConstIterator<Type>::operator==(const ConstIterator<Type>& other) const
    {
        return this->index == other.index;
    }

    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator++()
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        ++index;

        return *this;
    }

    template<typename Type>
    ConstIterator<Type> ConstIterator<Type>::operator++(int)
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);
        
        ConstIterator<Type> it(*this);
        ++(*this);
        return it;
    }

    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator+=(const int num)
    {
        check_available_object(__LINE__);
        time_t cur_time = time(NULL);

        if(index + num > size)
        {
            throw ErrorIteratorChangeIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index+num);
        }
        index +=  num; 

        return *this;
    }

    template<typename Type>
    ConstIterator<Type> ConstIterator<Type>::operator+(const int num) const
    {
        check_available_object(__LINE__);
        
        ConstIterator<Type> it(*this);
        it+=num;
        return it;
    }

    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator-=(const int num)
    {
        time_t cur_time = time(NULL);
        if(index - num < -1)
        {
            throw ErrorIteratorChangeIndex(typeid(*this).name(), __LINE__, ctime(&cur_time), index-num);
        }   
        index -= num;
        return *this;
    }

    template<typename Type>
    ConstIterator<Type> ConstIterator<Type>::operator-(const int num) const
    {
        ConstIterator<Type> it(*this);
        it -= num;
        return it;
    }

    // Возможно стоит сначала уменьшить индекс, а потом проверить
    template<typename Type>
    ConstIterator<Type>& ConstIterator<Type>::operator--()
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        index-=1;
        return *this;
    }

    template<typename Type>
    ConstIterator<Type> ConstIterator<Type>::operator--(int)
    {
        check_available_object(__LINE__);
        check_correct_index_change(__LINE__);

        ConstIterator<Type> it(*this);
        --it;
        return it;
    }


    template<typename Type>
    ConstIterator<Type>::operator bool() const
    {
        return size and index < size;
    }

    template<typename Type>
    ConstIterator<Type>::reference ConstIterator<Type>::get_ref() const
    {
        std::shared_ptr<Type[]> temp_ptr(ptr);
        return temp_ptr[index];
    }

    template<typename Type>
    ConstIterator<Type>::pointer ConstIterator<Type>::get_ptr() const
    {
        std::shared_ptr<Type[]> temp_ptr(ptr);
        return temp_ptr.get() + index;
    }

    template<typename Type>
    void ConstIterator<Type>::check_correct_index_apply(int line) const
    {   
        time_t cur_time = time(NULL);
        if (index >= size or index < 0)
        {
            throw ErrorIteratorApplyIndex(typeid(*this).name(), line, ctime(&cur_time), index);
        }
    }

    template<typename Type>
    void ConstIterator<Type>::check_correct_index_change(int line) const
    {
        time_t cur_time = time(NULL);
        if (index >= size or index < 0)
        {
            throw ErrorIteratorApplyIndex(typeid(*this).name(), line, ctime(&cur_time), index);
        }
    }

    template<typename Type>
    void ConstIterator<Type>::check_available_object(int line) const
    {
        time_t cur_time = time(NULL);
        if(ptr.expired())
        {
            throw ErrorDeleted(typeid(*this).name(), ctime(&cur_time), line);
        }
    }

    template<typename Type>
    ConstIterator<Type>::difference_type ConstIterator<Type>::operator-(const ConstIterator<Type> &iter) const
    {
        return index - iter.index;
    }
} // namespace my_math

#endif