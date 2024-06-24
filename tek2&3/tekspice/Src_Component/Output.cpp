/*
** EPITECH PROJECT, 2022
** output
** File description:
** output code
*/

#include "../Component/Output.hpp"

char Output::getValueW()
{
    if (*p[0] == -1)
        return 'U';
    if (*p[0] == 1)
        return '1';
    return '0';
}

std::size_t Output::toWrite()
{
    return 1;
}

void Output::linkedout(std::size_t t, nts::Tristate *i)
{
    if (t != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    p[t - 1] = i;
}

nts::Tristate * Output::linked(std::size_t t)
{
}

void Output::setValue(std::string h)
{
    std::cout << "shouldn't be able to receive a value\n";
    throw std::exception();
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Tristate *i = other.linked(otherPin);
    if (pin != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    p[pin -1] = i;
}

size_t Output::getLenght()
{
    return i;
}

Output::Output()
{
    i = 1;
    p[0] = {NULL};
}

nts::Tristate Output::compute(std::size_t s)
{
    return *p[s - 1];
}
