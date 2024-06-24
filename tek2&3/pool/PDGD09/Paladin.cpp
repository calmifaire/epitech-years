/*
** EPITECH PROJECT, 2022
** Paladin
** File description:
** Paladin
*/

#include <string>
#include <iostream>
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) : Peasant(name,power), Knight(name, power), Priest(name, power)
{
    std::cout << Paladin::Knight::Name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << Paladin::Knight::Name << " is blessed." << std::endl;
}
