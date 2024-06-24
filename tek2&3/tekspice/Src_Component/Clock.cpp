/*
** EPITECH PROJECT, 2022
** Clock
** File description:
** Clock code
*/

#include "../Component/Clock.hpp"

char Clock::getValueW()
{
    if (p[0] == -1)
        return 'U';
    if (p[0] == 1)
        return '1';
    return '0';
}

std::size_t Clock::toWrite()
{
    return 0;
}

nts::Tristate * Clock::linked(std::size_t s)
{
    if (s != 1){
		std::cout << "invalid pin\n";
	    throw std::exception();
	}
    return &p[s - 1];
}

void Clock::linkedout(std::size_t t, nts::Tristate *i)
{
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
    if (pin != 1){
        std::cout << "invalid pin\n";
        throw std::exception();
    }
    other.linkedout(otherpin, &p[pin - 1]);
}

void Clock::setValue(std::string v)
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

size_t Clock::getLenght()
{
    return i;
}

void Clock::simulate(std::size_t tick)
{
    if (p[0] != g)
        p[0] = g;
    else if (p[0] != -1){
		if (p[0] == 1)
		    p[0] = nts::FALSE;
		else
		    p[0] = nts::TRUE;
	}
}

Clock::Clock()
{
    g = nts::UNDEFINED;
    i = 1;
    p[0] = {nts::UNDEFINED};
}

nts::Tristate Clock::compute(std::size_t s)
{
    return p[s - 1];
}
