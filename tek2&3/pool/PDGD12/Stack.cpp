/*
** EPITECH PROJECT, 2022
** Stack
** File description:
** Stack
*/

#include "Stack.hpp"

char const *Stack::Error::what() const throw()
{
    return parent.message.c_str();
}

Stack::Stack()
{}

Stack::~Stack()
{
    while (!this->s.empty())
        this->s.pop();
}

void Stack::push(double value)
{
    this->s.push(value);
}

double Stack::pop()
{
    if (this->s.empty()){
        this->message = "Empty stack";
        throw std::exception();
    }
    double a = this->s.top();
    this->s.pop();
    return a;
}

double Stack::top() const
{
    if (this->s.empty()){
        throw std::exception();
    }
    return this->s.top();
}

void Stack::add()
{
    if (this->s.size() < 2){
        this->message = "Not enough operands";
        throw std::exception();
    }
    double a = this->s.top();
    this->s.pop();
    double b = this->s.top();
    this->s.pop();
    a = a + b;
    this->s.push(a);
}

void Stack::sub()
{
    if (this->s.size() < 2){
        this->message = "Not enough operands";
        throw std::exception();
    }
    double a = this->s.top();
    this->s.pop();
    double b = this->s.top();
    this->s.pop();
    a = a - b;
    this->s.push(a);
}

void Stack::mul()
{
    if (this->s.size() < 2){
        this->message = "Not enough operands";
        throw std::exception();
    }
    double a = this->s.top();
    this->s.pop();
    double b = this->s.top();
    this->s.pop();
    a = a * b;
    this->s.push(a);
}

void Stack::div()
{
    if (this->s.size() < 2) {
        this->message = "Not enough operands";
        throw std::exception();
    }
    double a = this->s.top();
    this->s.pop();
    double b = this->s.top();
    this->s.pop();
    if (b == 0)
        throw std::exception();
    a = a / b;
    this->s.push(a);
}
