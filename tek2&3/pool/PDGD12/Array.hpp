/*
** EPITECH PROJECT, 2022
** Array
** File description:
** Array
*/

#include <ostream>
#include <iostream>
#include <string>
#include <exception>
#include <functional>

template<typename T, size_t s>
class Array : public std::exception
{
private:
    size_t n;
    T* array;
    std::string message;
public:
    Array() {
        this->n = s;
        this->array = new T[n];
        this->message = "Out of range";
    };
    char const *what() const throw(){
        return this->message.c_str();
    };
    T& operator[](unsigned int index) const {
        if (index >= n) {
            throw std::exception();
        }
        return array[index];
    }
    T getArray(size_t i) const{
        return array[i];
    }
    std::size_t size() const {
        return n;
    }
    void forEach(const std::function<void(const T&)> &task) const {
        for (size_t i = 0; i < size(); i++)
            task(array[i]);
    }
    template <typename U>
    Array<U, s> convert(const std::function <U(const T&) > &converter) const
        {
            Array<U, s> dup;
            for (size_t i = 0; i < size(); i++)
                dup[i] = converter(array[i]);
            return dup;
        }
};

template<typename T, size_t size>
std::ostream& operator<<(std::ostream& os, const Array<T,size> &dt)
{
    
    os << "[";
    for (size_t i = 0; i != size; i++) {
        os << dt.getArray(i);
        if (i != dt.size() - 1)
            os << ", ";
        }
    os << "]";
    return os;
}
