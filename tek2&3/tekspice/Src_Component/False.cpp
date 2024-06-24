/*
** EPITECH PROJECT, 2022
** False
** File description:
** False code
*/

#include "../Component/False.hpp"

char False::getValueW()
{
    if (p[0] == -1)
        return 'U';
    if (p[0] == 1)
        return '1';
    return '0';
}

std::size_t False::toWrite()
{
    return 0;
}

nts::Tristate * False::linked(std::size_t s)
{
    if (s != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    return &p[s - 1];
}

void False::linkedout(std::size_t t, nts::Tristate *i)
{
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
    if (pin != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    other.linkedout(otherpin, &p[pin - 1]);
}


void False::setValue(std::string v)
{
	std::cout << "It a False, can be only False then\n";
}

size_t False::getLenght()
{
    return i;
}

void False::simulate(std::size_t tick)
{}

False::False()
{
    i = 1;
    p[0] = {nts::FALSE};
}

nts::Tristate False::compute(std::size_t s)
{
    return p[s - 1];
}
