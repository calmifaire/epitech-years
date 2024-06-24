/*
** EPITECH PROJECT, 2022
** 4069
** File description:
** 4069 code
*/

#include "../Component/4069.hpp"

char not_4069::getValueW()
{
    if (p[0] == -1)
        return 'U';
    if (p[0] == 1)
        return '1';
    return '0';
}

std::size_t not_4069::toWrite()
{
    return 2;
}

nts::Tristate * not_4069::linked(std::size_t s)
{
    if (s != 2 && s != 4 && s != 6 && s != 8 && s != 10 && s != 12){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    return &p[s - (s/2) - 1];
}

void not_4069::linkedout(std::size_t t, nts::Tristate *i)
{
    if (t != 1 && t != 3 && t != 5 && t != 9 && t != 11 && t != 13){
        std::cout << "invalid pin\n";
	throw std::exception();
    }
    int k = t - (t/2) - 0.5;
    if (t > 5)
        k--;
    q[k] = i;
}

void not_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin == 7 || pin > 13){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13){
        nts::Tristate *i = other.linked(otherPin);
        int k = pin - (pin/2) - 0.5;
        if (pin > 5)
            k--;
        q[k] = i;
    }
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12){
        other.linkedout(otherPin, &p[pin - (pin/2) - 1]);
    }
}

void not_4069::setValue(std::string v)
{
    std::cout << "shouldn't be able to receive a value\n";
    throw std::exception();
}

size_t not_4069::getLenght()
{
    return i;
}

void not_4069::simulate(std::size_t tick)
{
    for (size_t l = 0; l != 6; l++){
        if (q[l] != NULL){
            if (*q[l] == 1)
                p[l] = nts::Tristate::FALSE;
            else if (*q[l] == 0)
                p[l] = nts::Tristate::TRUE;
            else
                p[l] = nts::Tristate::UNDEFINED;
        }
    }
}

not_4069::not_4069()
{
    i = 6;
    p[0] = {nts::UNDEFINED};
    p[1] = {nts::UNDEFINED};
    p[2] = {nts::UNDEFINED};
    p[3] = {nts::UNDEFINED};
    p[4] = {nts::UNDEFINED};
    p[5] = {nts::UNDEFINED};
    q[0] = {NULL};
    q[1] = {NULL};
    q[2] = {NULL};
    q[3] = {NULL};
    q[4] = {NULL};
    q[5] = {NULL};
}

nts::Tristate not_4069::compute(std::size_t s)
{
    return p[s - 1];
}
