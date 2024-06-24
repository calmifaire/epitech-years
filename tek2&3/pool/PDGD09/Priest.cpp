/*
** EPITECH PROJECT, 2022
** Priest
** File description:
** Priest
*/

#include <string>
#include <iostream>
#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name,power), Enchanter (name, power)
{
    std::cout << Name << " enters in the order." << std::endl;
}

void Priest::rest()
{
    if (Hp == 0)
        std::cout << Name << " is out of combat." << std::endl;
    else {
        if (Power + 100 > 100)
            Power = 100;
        else
            Power = Power + 100;
        if (Hp + 100 > 100)
            Hp = 100;
        else
            Hp = Power + 100;
        std::cout << Name << " prays." << std::endl;
    }
}

Priest::~Priest()
{
    std::cout << Name << " finds peace." << std::endl;
}
