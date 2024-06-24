/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Factory
*/

#pragma once
#include <map>
#include <string>
#include <stack>
#include "IOperand.hpp"

class Factory {
    public:
        Factory();
        ~Factory() = default;

        int loop(std::vector<std::pair<std::string,std::pair<eOperandType, std::string>>> parse);

        static IOperand* createOperand(eOperandType type, const std::string& value);

        void push(IOperand *value);
        void pop(IOperand *value);
        void clear(IOperand *value);
        void dup(IOperand *value);
        void swap(IOperand *value);
        void dump(IOperand *value);
        void asert(IOperand *value);
        void add(IOperand *value);
        void sub(IOperand *value);
        void mul(IOperand *value);
        void div(IOperand *value);
        void mod(IOperand *value);
        void load(IOperand *value);
        void store(IOperand *value);
        void print(IOperand *value);
        void exit(IOperand *value);

        std::map<std::string, void (Factory::*)(IOperand *)> _instruction;
        bool _exit = false;

    protected:
    private:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);

        std::vector<IOperand *> _vector;
        std::stack<IOperand *> _stack;
        std::map<int, IOperand *> _registers;
};
