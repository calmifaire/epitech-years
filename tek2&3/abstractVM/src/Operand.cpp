/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-abstractVM-kevin.zilliox
** File description:
** Operand
*/

#include "Include.hpp"
#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType type, const std::string &value)
{
    this->_type = type;
    this->_value = value;
}

template<typename T>
std::string Operand<T>::toString() const
{
    return this->_value;
}

template<typename T>
IOperand* Operand<T>::operator+(const IOperand &rhs) const
{
    IOperand *operand;
    Factory factory;

    double nbrLeft = static_cast<double>(stod(this->_value));
    double nbrRight = static_cast<double>(stod(rhs.toString()));
    double result = nbrLeft + nbrRight;
    if (result > std::numeric_limits<T>::max()) {
        std::cerr << "Result overflow !" << std::endl;
        return (NULL);
    }
    if (result < std::numeric_limits<T>::lowest()) {
        std::cerr << "Result underflow !" << std::endl;
        return (NULL);
    }
    std::string resultString = std::to_string(result);
    if (resultString.find('.') != std::string::npos) {
        resultString = resultString.substr(0, resultString.find_last_not_of('0') + 1);
        if (resultString.find('.') == resultString.size() - 1)
            resultString = resultString.substr(0, resultString.size() - 1);
    }
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0) {
        resultString = resultString.substr(0, resultString.find(".", 0));
        operand = factory.createOperand(this->getType(), resultString);
    } else if (this->getPrecision() < rhs.getPrecision())
        operand = factory.createOperand(rhs.getType(), resultString);
    else
        operand = factory.createOperand(this->getType(), resultString);
    return (operand);
}

template<typename T>
IOperand* Operand<T>::operator-(const IOperand &rhs) const
{
    IOperand *operand;
    Factory factory;

    double nbrLeft = static_cast<double>(stod(this->_value));
    double nbrRight = static_cast<double>(stod(rhs.toString()));
    double result = nbrLeft - nbrRight;
    if (result > std::numeric_limits<T>::max()) {
        std::cerr << "Result overflow !" << std::endl;
        return (NULL);
    }
    if (result < std::numeric_limits<T>::lowest()) {
        std::cerr << "Result underflow !" << std::endl;
        return (NULL);
    }
    std::string resultString = std::to_string(result);
    if (resultString.find('.') != std::string::npos) {
        resultString = resultString.substr(0, resultString.find_last_not_of('0') + 1);
        if (resultString.find('.') == resultString.size() - 1)
            resultString = resultString.substr(0, resultString.size() - 1);
    }
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0) {
        resultString = resultString.substr(0, resultString.find(".", 0));
        operand = factory.createOperand(this->getType(), resultString);
    } else if (this->getPrecision() < rhs.getPrecision())
        operand = factory.createOperand(rhs.getType(), resultString);
    else
        operand = factory.createOperand(this->getType(), resultString);
    return (operand);
}

template<typename T>
IOperand* Operand<T>::operator*(const IOperand &rhs) const
{
    IOperand *operand;
    Factory factory;

    double nbrLeft = static_cast<double>(stod(this->_value));
    double nbrRight = static_cast<double>(stod(rhs.toString()));
    double result = nbrLeft * nbrRight;
    if (result > std::numeric_limits<T>::max()) {
        std::cerr << "Result overflow !" << std::endl;
        return (NULL);
    }
    if (result < std::numeric_limits<T>::lowest()) {
        std::cerr << "Result underflow !" << std::endl;
        return (NULL);
    }
    std::string resultString = std::to_string(result);
    if (resultString.find('.') != std::string::npos) {
        resultString = resultString.substr(0, resultString.find_last_not_of('0') + 1);
        if (resultString.find('.') == resultString.size() - 1)
            resultString = resultString.substr(0, resultString.size() - 1);
    }
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0) {
        resultString = resultString.substr(0, resultString.find(".", 0));
        operand = factory.createOperand(this->getType(), resultString);
    } else if (this->getPrecision() < rhs.getPrecision())
        operand = factory.createOperand(rhs.getType(), resultString);
    else
        operand = factory.createOperand(this->getType(), resultString);
    return (operand);
}

template<typename T>
IOperand* Operand<T>::operator/(const IOperand &rhs) const
{
    if (atof(rhs.toString().c_str()) == 0) {
        std::cerr << "Division by zero !" << std::endl;
        return (NULL);
    }

    IOperand *operand;
    Factory factory;

    double nbrLeft = static_cast<double>(stod(this->_value));
    double nbrRight = static_cast<double>(stod(rhs.toString()));
    double result = nbrLeft / nbrRight;
    if (result > std::numeric_limits<T>::max()) {
        std::cerr << "Result overflow !" << std::endl;
        return (NULL);
    }
    if (result < std::numeric_limits<T>::lowest()) {
        std::cerr << "Result underflow !" << std::endl;
        return (NULL);
    }
    std::string resultString = std::to_string(result);
    if (resultString.find('.') != std::string::npos) {
        resultString = resultString.substr(0, resultString.find_last_not_of('0') + 1);
        if (resultString.find('.') == resultString.size() - 1)
            resultString = resultString.substr(0, resultString.size() - 1);
    }
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0) {
        resultString = resultString.substr(0, resultString.find(".", 0));
        operand = factory.createOperand(this->getType(), resultString);
    } else if (this->getPrecision() < rhs.getPrecision())
        operand = factory.createOperand(rhs.getType(), resultString);
    else
        operand = factory.createOperand(this->getType(), resultString);
    return (operand);
}

template<typename T>
IOperand* Operand<T>::operator%(const IOperand &rhs) const
{
    if (atof(rhs.toString().c_str()) == 0) {
        std::cerr << "Modulo by zero !" << std::endl;
        return (NULL);
    }
    if (_type == eOperandType::FLOAT || rhs.getType() == eOperandType::FLOAT) {
        std::cerr << "Modulo with float impossible !" << std::endl;
        return (NULL);
    }
    if (_type == eOperandType::DOUBLE || rhs.getType() == eOperandType::DOUBLE) {
        std::cerr << "Modulo with double impossible !" << std::endl;
        return (NULL);
    }

    IOperand *operand;
    Factory factory;

    long nbrLeft = static_cast<int>(stod(this->_value));
    long nbrRight = static_cast<int>(stod(rhs.toString()));
    long result = nbrLeft % nbrRight;
    if (result > std::numeric_limits<T>::max()) {
        std::cerr << "Result overflow !" << std::endl;
        return (NULL);
    }
    if (result < std::numeric_limits<T>::lowest()) {
        std::cerr << "Result underflow !" << std::endl;
        return (NULL);
    }
    std::string resultString = std::to_string(result);
    if (resultString.find('.') != std::string::npos) {
        resultString = resultString.substr(0, resultString.find_last_not_of('0') + 1);
        if (resultString.find('.') == resultString.size() - 1)
            resultString = resultString.substr(0, resultString.size() - 1);
    }
    if (this->getPrecision() == 0 && rhs.getPrecision() == 0) {
        resultString = resultString.substr(0, resultString.find(".", 0));
        operand = factory.createOperand(this->getType(), resultString);
    } else if (this->getPrecision() < rhs.getPrecision())
        operand = factory.createOperand(rhs.getType(), resultString);
    else
        operand = factory.createOperand(this->getType(), resultString);
    return (operand);
}
