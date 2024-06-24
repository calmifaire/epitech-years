/*
** EPITECH PROJECT, 2022
** True
** File description:
** True code
*/

#include "../Component/True.hpp"

char True::getValueW()
{
    if (p[0] == -1)
        return 'U';
    if (p[0] == 1)
        return '1';
    return '0';
}

std::size_t True::toWrite()
{
    return 0;
}

nts::Tristate * True::linked(std::size_t s)
{
    if (s != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    return &p[s - 1];
}

void True::linkedout(std::size_t t, nts::Tristate *i)
{
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
    if (pin != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    other.linkedout(otherpin, &p[pin - 1]);
}


void True::setValue(std::string v)
{
	std::cout << "It a True, can be only True then\n";
}

size_t True::getLenght()
{
    return i;
}

void True::simulate(std::size_t tick)
{}

True::True()
{
    i = 1;
    p[0] = {nts::TRUE};
}

nts::Tristate True::compute(std::size_t s)
{
    return p[s - 1];
}
