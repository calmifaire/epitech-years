/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Int8
*/

#pragma once
#include "../Operand.hpp"

class Int8 : public Operand<int8_t> {
    public:
        Int8(const std::string &value) : Operand(INT8, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<int8_t>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<int8_t>::lowest())
                throw Exception("Underflow !");
        };
        ~Int8() = default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<int8_t>::getType() const
{
    return (INT8);
}

template<>
int Operand<int8_t>::getPrecision() const
{
    return (0);
}
