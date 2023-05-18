#ifndef CONCEPT_H
#define CONCEPT_H

namespace my_math
{
    template <typename Type>
    concept Container = requires(Type t)
    {
        typename Type::value_type;
        typename Type::size_type;
        typename Type::iterator;
        typename Type::const_iterator;

        {t.size() } noexcept -> std::same_as<typename Type::size_type>;
        {t.begin() } noexcept -> std::same_as<typename Type::iterator>;
        {t.end() } noexcept -> std::same_as<typename Type::iterator>;
    };

    template <typename Type, typename Type1>
    concept MyConvertableToContainers = std::convertible_to<typename Type::value_type, Type1>;

    template <typename Type, typename Type1>
    concept ContainerInit = Container<Type> && MyConvertableToContainers<Type, Type1>;

    template <typename Type>
    concept Math = requires(Type t)
    {
        {t+t} -> std::same_as<Type>;
        {t-t} -> std::same_as<Type>;
        {t=t} -> std::same_as<Type&>;
        {t+=t} -> std::same_as<Type&>;
        {t-=t} -> std::same_as<Type&>;
        {t*t} -> std::same_as<Type>;
        {t*=t} -> std::same_as<Type&>;
        {t/t} -> std::same_as<Type>;
        {t/=t} -> std::same_as<Type&>;
        {t==t} -> std::same_as<bool>;
    };
    
    template <typename Type, typename Type1>
    concept MyConvertableToFrom = std::convertible_to<Type, Type1> || std::convertible_to<Type1, Type>;

    template <typename Type, typename Type1>
    //from Type1 To Type
    concept MyConvertableTo = std::convertible_to<Type1, Type>;

    template <typename Type, typename Type1>
    concept IsHasSum = requires(Type t, Type1 k)
    {
        t+k;
    };

    template <typename Type, typename Type1>
    concept IsHasMul = requires(Type t, Type1 k)
    {
        t*k;
    };

    template <typename Type, typename Type1>
    concept IsHasSub = requires(Type t, Type1 k)
    {
        t-k;
    };

    template <typename Type, typename Type1>
    concept IsHasDiv = requires(Type t, Type1 k)
    {
        t/k;
    };

    template <typename Type, typename Type1>
    concept SumOneType = MyConvertableTo<Type, Type1> && IsHasSum<Type, Type1>;
    template <typename Type, typename Type1>
    concept SumTwoType = MyConvertableToFrom<Type, Type1> && IsHasSum<Type, Type1>;

    template <typename Type, typename Type1>
    concept SubOneType = MyConvertableTo<Type, Type1> && IsHasSub<Type, Type1>;
    template <typename Type, typename Type1>
    concept SubTwoType = MyConvertableToFrom<Type, Type1> && IsHasSub<Type, Type1>;

    template <typename Type, typename Type1>
    concept MulOneType = MyConvertableTo<Type, Type1> && IsHasMul<Type, Type1>;
    template <typename Type, typename Type1>
    concept MulTwoType = MyConvertableToFrom<Type, Type1> && IsHasMul<Type, Type1>;

    template <typename Type, typename Type1>
    concept DivOneType = MyConvertableTo<Type, Type1> && IsHasDiv<Type, Type1>;
    template <typename Type, typename Type1>
    concept DivTwoType = MyConvertableToFrom<Type, Type1> && IsHasDiv<Type, Type1>;

    template <typename Type, typename Type1>
    concept SumMulTwoType = MulTwoType<Type, Type1> && SumTwoType<Type, Type1>;

    template <typename Type, typename Type1>
    concept SubMulTwoType = MulTwoType<Type, Type1> && SubTwoType<Type, Type1>;

    template <typename Type, typename Type1>
    concept SubMulOneType = MulOneType<Type, Type1> && SubOneType<Type, Type1>;

    template<typename Type, typename IterType>
    concept InputIterator = std::input_iterator<IterType> && MyConvertableTo<Type, typename IterType::value_type>;

    //
    /*template <typename I>
    concept IteratorConcept = requires()
    {
        typename I::value_type;
        typename I::difference_type;
        typename I::pointer;
        typename I::reference;
    };

    template <typename T, typename U>
    concept DerivedFrom = std::is_base_of<U, T>::value;

    template<typename T>
    concept EqualityComparable = requires(T a, T b)
    {
        { a == b } -> std::same_as<bool>;
        { a != b } -> std::same_as<bool>;
    };

    template <typename I>
    concept InputIteratorConcept = IteratorConcept<I> &&
    requires { typename I::iterator_category; }&&
    EqualityComparable<I>&&
    DerivedFrom<typename I::iterator_category, std::input_iterator_tag>;

    template<typename Type, typename IterType>
    concept InputIterator = InputIteratorConcept<IterType> && MyConvertableTo<Type, typename IterType::value_type>;*/
};

#endif