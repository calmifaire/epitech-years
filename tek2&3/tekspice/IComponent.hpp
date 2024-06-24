/*
** EPITECH PROJECT, 2022
** iComponent
** File description:
** Icomp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <cstring>
#include <iostream>
#include <memory>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual size_t getLenght() = 0;
        virtual void setValue(std::string) = 0;
        virtual nts::Tristate *linked(std::size_t) = 0;
        virtual void linkedout(std::size_t t, nts::Tristate *i) = 0;
        virtual std::size_t toWrite() = 0;
        virtual char getValueW() = 0;
    };
}

#endif
