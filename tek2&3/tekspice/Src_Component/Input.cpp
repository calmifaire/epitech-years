/*
** EPITECH PROJECT, 2022
** Input
** File description:
** Input code
*/

#include "../Component/Input.hpp"

char Input::getValueW()
{
    if (p[0] == -1)
        return 'U';
    if (p[0] == 1)
        return '1';
    return '0';
}

std::size_t Input::toWrite()
{
    return 0;
}

nts::Tristate * Input::linked(std::size_t s)
{
    if (s != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    return &p[s - 1];
}

void Input::linkedout(std::size_t t, nts::Tristate *i)
{
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
    if (pin != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    other.linkedout(otherpin, &p[pin - 1]);
}


void Input::setValue(std::string v)
{
    if (v.compare("U") != 0 && v.compare("1") != 0 
	&& v.compare("0") != 0)
        std::cout << v << " is not a value possible" << std::endl;
    if (v.compare("U") == 0)
        g = nts::UNDEFINED;
    if (v.compare("1") == 0)
        g = nts::TRUE;
    if (v.compare("0") == 0)
        g = nts::FALSE;
}

size_t Input::getLenght()
{
    return i;
}

void Input::simulate(std::size_t tick)
{
    if (p[0] != g)
        p[0] = g;
}

Input::Input()
{
    g = nts::UNDEFINED;
    i = 1;
    p[0] = {nts::UNDEFINED};
}

nts::Tristate Input::compute(std::size_t s)
{
    return p[s - 1];
}
