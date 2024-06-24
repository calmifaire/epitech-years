/*
** EPITECH PROJECT, 2022
** component
** File description:
** component
*/

#include "../IComponent.hpp"

#ifndef INPUT_HPP
#define INPUT_HPP

class Input : public nts::IComponent
{
public:
    Input();
    virtual ~Input() {};
    virtual void simulate(std::size_t tick);
    virtual nts::Tristate compute(std::size_t pin);
    virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    virtual size_t getLenght();
    virtual void setValue(std::string);
    virtual nts::Tristate *linked(std::size_t);
    virtual void linkedout(std::size_t t, nts::Tristate *i);
    virtual std::size_t toWrite();
    virtual char getValueW();
private:
    nts::Tristate g;
    size_t i;
    nts::Tristate p[1];
};

#endif
