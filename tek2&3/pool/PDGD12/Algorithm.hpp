/*
** EPITECH PROJECT, 2022
** Algorithm
** File description:
** Algorithm
*/

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(const T a, const T b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T>
T max(const T a, const T b)
{
    if (a < b)
        return b;
    return a;
}

template<typename T>
T clamp(const T c,const T a, const T b)
{
    if (c < a)
        return a;
    if (b < c)
        return b;
    return c;
}
