/*
** EPITECH PROJECT, 2022
** Knight
** File description:
** Knight
*/

#include <string>
#include <iostream>
#include "Knight.hpp"

int Knight::attack()
{
    if (Hp == 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return (0);
    }
    if (Power < 10) {
        std::cout << Name << " is out of power." << std::endl;
        return (0);
    }
    Power = Power - 10;
    std::cout << Name << " strikes with his sword." << std::endl;
    return (20);
}

int Knight::special()
{
    if (Hp == 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return (0);
    }
    if (Power < 30) {
        std::cout << Name << " is out of power." << std::endl;
        return (0);
    }
    Power = Power - 30;
    std::cout << Name << " impales his enemy." << std::endl;
    return (50);
}

void Knight::rest()
{
    if (Hp == 0)
        std::cout << Name << " is out of combat." << std::endl;
    else {
        if (Power + 50 > 100)
            Power = 100;
        else
            Power = Power + 50;
        std::cout << Name << " eats." << std::endl;
    }
}

Knight::Knight(const std::string &name, int power) : Peasant (name, power)
{
    std::cout << Name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << Name << " takes off his armor." << std::endl;
}
