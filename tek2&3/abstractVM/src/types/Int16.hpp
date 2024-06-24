/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Int16
*/

#pragma once
#include "../Operand.hpp"

class Int16 : public Operand<int16_t> {
    public:
        Int16(const std::string &value) : Operand(INT16, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<int16_t>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<int16_t>::lowest())
                throw Exception("Underflow !");
        };
        ~Int16() = default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<int16_t>::getType() const
{
    return (INT16);
}

template<>
int Operand<int16_t>::getPrecision() const
{
    return (0);
}
