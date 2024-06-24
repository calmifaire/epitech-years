/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Factory
*/

#include "Include.hpp"
#include "Factory.hpp"
#include "types/Int8.hpp"
#include "types/Int16.hpp"
#include "types/Int32.hpp"
#include "types/Float.hpp"
#include "types/Double.hpp"
#include "types/BigDecimal.hpp"

Factory::Factory()
{
    this->_instruction["push"] = &Factory::push;
    this->_instruction["pop"] = &Factory::pop;
    this->_instruction["clear"] = &Factory::clear;
    this->_instruction["dup"] = &Factory::dup;
    this->_instruction["swap"] = &Factory::swap;
    this->_instruction["dump"] = &Factory::dump;
    this->_instruction["assert"] = &Factory::asert;
    this->_instruction["add"] = &Factory::add;
    this->_instruction["sub"] = &Factory::sub;
    this->_instruction["mul"] = &Factory::mul;
    this->_instruction["div"] = &Factory::div;
    this->_instruction["mod"] = &Factory::mod;
    this->_instruction["load"] = &Factory::load;
    this->_instruction["store"] = &Factory::store;
    this->_instruction["print"] = &Factory::print;
    this->_instruction["exit"] = &Factory::exit;
}

int Factory::loop(std::vector<std::pair<std::string,std::pair<eOperandType, std::string>>> parse)
{
    try
    {
        for (long unsigned int i = 0; i < parse.size() && _exit == false; i++) {
            for (std::map<std::string, void (Factory::*)(IOperand *)>::const_iterator it = _instruction.begin(); it != _instruction.end(); it++) {
                if (parse[i].first == it->first)
                    (this->*(it->second))(createOperand(parse[i].second.first, parse[i].second.second));
            }
        }
        if (_exit == true)
            return (0);
        else if (_exit == false)
            return (84);
    }
    catch(const std::exception& e)
    {
        for (IOperand *i : _vector)
            delete i;
        for (std::map<int, IOperand *>::const_iterator it = _registers.begin(); it != _registers.end(); it++) {
            if (it->second != NULL)
                delete it->second;
        }
        std::cerr << e.what() << std::endl;
    }
    return (84);
}

void Factory::push(IOperand *value)
{
    this->_vector.push_back(value);
}

void Factory::pop(IOperand *value)
{
    IOperand *dele;

    (void)value;
    if (!(this->_vector.empty())) {
        dele = _vector.back();
        this->_vector.pop_back();
        delete dele;
    } else {
        delete value;
        throw Exception("Pop instruction on empty stack");
    }
}

void Factory::clear(IOperand *value)
{
    (void)value;
    this->_vector = std::vector<IOperand *>();
}

void Factory::dup(IOperand *value)
{
    (void)value;
    this->_vector.push_back(createOperand(_vector.back()->getType(), _vector.back()->toString()));
}

void Factory::swap(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;

    if (this->_vector.size() >= 2) {
        first = _vector.back();
        this->_vector.pop_back();
        second = _vector.back();
        this->_vector.pop_back();
        this->push(first);
        this->push(second);
    } else
        throw Exception("Swap on stack with less than two values");
}

void Factory::dump(IOperand *value)
{
    (void)value;
    std::vector<IOperand *> secondVector(this->_vector);

    while (!secondVector.empty()) {
        std::cout << secondVector.back()->toString() << std::endl;
        secondVector.pop_back();
    }
}

void Factory::asert(IOperand *value)
{
    if (!(this->_vector.empty())) {
        const IOperand* topVector = this->_vector.back();

        if (topVector->toString() != value->toString())
            throw Exception("Assert instruction with different value");
        if (topVector->getType() != value->getType())
            throw Exception("Assert instruction with different type");
    } else {
        delete value;
        throw Exception("The stack is empty");
    }
    delete value;
}

void Factory::add(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;
    IOperand *result;

    if (this->_vector.size() >= 2) {
        first = this->_vector.back();
        this->_vector.pop_back();
        second = this->_vector.back();
        this->_vector.pop_back();
        if (first->getType() < second->getType())
            result = *second + *first;
        else
            result = *first + *second;
        delete first;
        delete second;
        if (result == NULL)
            throw Exception("Error in add");
        this->push(result);
    } else
        throw Exception("Not enough operands in the stack");
}

void Factory::sub(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;
    IOperand *result;

    if (this->_vector.size() >= 2) {
        first = this->_vector.back();
        this->_vector.pop_back();
        second = this->_vector.back();
        this->_vector.pop_back();
        result = *second - *first;
        delete first;
        delete second;
        if (result == NULL)
            throw Exception("Error in sub");
        this->push(result);
    } else
        throw Exception("Not enough operands in the stack");
}

void Factory::mul(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;
    IOperand *result;

    if (this->_vector.size() >= 2) {
        first = this->_vector.back();
        this->_vector.pop_back();
        second = this->_vector.back();
        this->_vector.pop_back();
        if (first->getType() < second->getType())
            result = *second * *first;
        else
            result = *first * *second;
        delete first;
        delete second;
        if (result == NULL)
            throw Exception("Error in mul");
        this->push(result);
    } else
        throw Exception("Not enough operands in the stack");
}

void Factory::div(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;
    IOperand *result;

    if (this->_vector.size() >= 2) {
        first = this->_vector.back();
        this->_vector.pop_back();
        second = this->_vector.back();
        this->_vector.pop_back();
        result = *second / *first;
        delete first;
        delete second;
        if (result == NULL)
            throw Exception("Error in div");
        this->push(result);
    } else
        throw Exception("Not enough operands in the stack");
}

void Factory::mod(IOperand *value)
{
    (void)value;
    IOperand *first;
    IOperand *second;
    IOperand *result;

    if (this->_vector.size() >= 2) {
        first = this->_vector.back();
        this->_vector.pop_back();
        second = this->_vector.back();
        this->_vector.pop_back();
        result = *second % *first;
        delete first;
        delete second;
        if (result == NULL)
            throw Exception("Error in mod");
        this->push(result);
    } else
        throw Exception("Not enough operands in the stack");
}

void Factory::load(IOperand *value)
{
    int index = atoi(value->toString().c_str());

    delete value;
    if (index >= 0 && index <= 15) {
        if (this->_registers[index] != NULL)
            this->_vector.push_back(createOperand(this->_registers[index]->getType(), this->_registers[index]->toString()));
        else
            throw Exception("Load an register empty cell");
    } else
        throw Exception("Register must be between 0 and 15 !");

}

void Factory::store(IOperand *value)
{
    int index = atoi(value->toString().c_str());

    delete value;
    if (this->_vector.empty())
        throw Exception("Store instruction on empty stack");
    else if (index >= 0 && index <= 15) {
        this->_registers[index] = this->_vector.back();
        this->_vector.pop_back();
    } else
        throw Exception("Register must be between 0 and 15 !");
}

void Factory::print(IOperand *value)
{
    (void)value;
    if (this->_vector.empty())
        throw Exception("Print instruction on empty stack");
    if (this->_vector.back()->getType() != eOperandType::INT8)
        throw Exception("Print instruction on no 8-bit integer");
    std::cout << static_cast<char>(std::stoi(this->_vector.back()->toString())) << std::endl;
}

void Factory::exit(IOperand *value)
{
    (void)value;
    for (IOperand *i : _vector) {
        if (i == NULL)
            continue;
        delete i;
    }
    for (std::map<int, IOperand *>::const_iterator it = _registers.begin(); it != _registers.end(); it++) {
        if (it->second == NULL)
            continue;
        delete it->second;
    }
    _exit = true;
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
    IOperand *result;
    Factory factory;

    switch (type) {
    case INT8:
        result = factory.createInt8(value);
        break;
    case INT16:
        result = factory.createInt16(value);
        break;
    case INT32:
        result = factory.createInt32(value);
        break;
    case FLOAT:
        result = factory.createFloat(value);
        break;
    case DOUBLE:
        result = factory.createDouble(value);
        break;
    case BIGDECIMAL:
        result = factory.createBigDecimal(value);
        break;
    case null:
        result = NULL;
    default:
        break;
    }
    return (result);
}

IOperand* Factory::createInt8(const std::string& value)
{
    return (new Int8(value));
}

IOperand* Factory::createInt16(const std::string& value)
{
    return (new Int16(value));
}

IOperand* Factory::createInt32(const std::string& value)
{
    return (new Int32(value));
}

IOperand* Factory::createFloat(const std::string& value)
{
    return (new Float(value));
}

IOperand* Factory::createDouble(const std::string& value)
{
    return (new Double(value));
}

IOperand* Factory::createBigDecimal(const std::string& value)
{
    return (new BigDecimal(value));
}