/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** IOperand
*/

#pragma once
#include <iostream>
#include <string>

typedef enum eOperandType {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
    null,
} eOperandType;

class IOperand {
    public:
        virtual std::string toString() const = 0; //string that represents the instance
        virtual eOperandType getType () const = 0; // returns the type of instance
        virtual int getPrecision() const = 0;
        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;
        virtual ~IOperand() {};

    protected:
    private:
};
