/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** BigDecimal
*/

#pragma once
#include "../Operand.hpp"

class BigDecimal : public Operand<long double> {
    public:
        BigDecimal(const std::string &value) : Operand(BIGDECIMAL, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<long double>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<long double>::lowest())
                throw Exception("Underflow !");
        };
        ~BigDecimal() = default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<long double>::getType() const
{
    return (BIGDECIMAL);
}

template<>
int Operand<long double>::getPrecision() const
{
    return (200);
}