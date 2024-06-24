/*
** EPITECH PROJECT, 2022
** Enchanter
** File description:
** Enchanter
*/

#include <string>
#include <iostream>
#include "Enchanter.hpp"

int Enchanter::attack()
{
    if (Hp == 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return (0);
    }
    std::cout << Name << " doesn't know how to fight." << std::endl;
    return (0);
}

int Enchanter::special()
{
    if (Hp == 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return (0);
    }
    if (Power < 50) {
        std::cout << Name << " is out of power." << std::endl;
        return (0);
    }
    Power = Power - 50;
    std::cout << Name << " casts a fireball." << std::endl;
    return (99);
}

void Enchanter::rest()
{
    if (Hp == 0)
        std::cout << Name << " is out of combat." << std::endl;
    else {
        if (Power + 100 > 100)
            Power = 100;
        else
            Power = Power + 100;
        std::cout << Name << " meditates." << std::endl;
    }
}

Enchanter::Enchanter(const std::string &name, int power) : Peasant (name, power)
{
    std::cout << Name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << Name << " closes his spellbook." << std::endl;
}
