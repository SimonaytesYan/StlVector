#pragma once

template<bool Value, class T1> 
struct EnableIf
{ };

template<class T1> 
struct EnableIf<true, T1>
{
    using type = T1;
};

//====================================================

template<class T1, class T2>
struct IsSame
{
    static const bool value = false;
};

template<class T>
struct IsSame<T, T>
{
    static const bool value = true;
};

#define CREATE_PREDICATE(predicate, name)                                               \
    template<class T>                                                                   \
    struct name                                                                         \
    {                                                                                   \
    private:                                                                            \
        static void cmp(...);                                                           \
                                                                                        \
        template<typename U>                                                            \
        static typename EnableIf<predicate, int>::type cmp(const U&);                   \
                                                                                        \
    public:                                                                             \
        static constexpr bool value = IsSame<int,                                       \
                                             decltype(cmp(std::declval<T>()))>::value;  \
    };
