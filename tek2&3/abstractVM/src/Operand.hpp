/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Operand
*/

#pragma once
#include "Factory.hpp"
#include <limits>

template<typename T>
class Operand : public IOperand {
    public:
        Operand(eOperandType type, const std::string &value);
        ~Operand() = default;

        virtual std::string toString() const;
        virtual eOperandType getType() const;
        virtual int getPrecision() const;

        IOperand* operator+(const IOperand &rhs) const;
        IOperand* operator-(const IOperand &rhs) const;
        IOperand* operator*(const IOperand &rhs) const;
        IOperand* operator/(const IOperand &rhs) const;
        IOperand* operator%(const IOperand &rhs) const;

    protected:
    private:
        eOperandType _type;
        std::string _value;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
template class Operand<long double>;