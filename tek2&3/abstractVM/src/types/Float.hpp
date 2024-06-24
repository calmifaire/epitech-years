/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Float
*/

#pragma once
#include "../Operand.hpp"

class Float : public Operand<float> {
    public:
        Float(const std::string &value) : Operand(FLOAT, value) {
            double nbr = static_cast<double>(stod(value));
            if (nbr > std::numeric_limits<float>::max())
                throw Exception("Overflow !");
            if (nbr < std::numeric_limits<float>::lowest())
                throw Exception("Underflow !");
        };
        ~Float() = default;
        bool _check_limit = false;
};

template<>
eOperandType Operand<float>::getType() const
{
    return (FLOAT);
}

template<>
int Operand<float>::getPrecision() const
{
    return (7);
}
