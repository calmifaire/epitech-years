/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Double
*/

#pragma once
#include "../Operand.hpp"

class Double : public Operand<double> {
    public:
        Double(const std::string &value) : Operand(DOUBLE, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<double>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<double>::lowest())
                throw Exception("Underflow !");
        };
        ~Double() =default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<double>::getType() const
{
    return (DOUBLE);
}

template<>
int Operand<double>::getPrecision() const
{
    return (15);
}