/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Int32
*/

#pragma once
#include "../Operand.hpp"

class Int32 : public Operand<int32_t> {
    public:
        Int32(const std::string &value) : Operand(INT32, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<int32_t>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<int32_t>::lowest())
                throw Exception("Underflow !");
        };
        ~Int32() = default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<int32_t>::getType() const
{
    return (INT32);
}

template<>
int Operand<int32_t>::getPrecision() const
{
    return (0);
}
