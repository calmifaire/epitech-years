/*
** EPITECH PROJECT, 2022
** Peasant
** File description:
** Peasant
*/

#include <string>
#include <iostream>
#include "Peasant.hpp"

const std::string& Peasant::getName() const
{
    return Name;
}

int Peasant::getPower() const
{
    return Power;
}

int Peasant::getHp() const
{
    return Hp;
}

int Peasant::attack()
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
    std::cout << Name << " tosses a stone." << std::endl;
    return (5);
}

int Peasant::special()
{
    if (Hp == 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return (0);
    }
    std::cout << Name << " doesn't know any special move." << std::endl;
    return (0);
}

void Peasant::rest()
{
    if (Hp == 0)
        std::cout << Name << " is out of combat." << std::endl;
    else {
        if (Power + 30 > 100)
            Power = 100;
        else
            Power = Power + 30;
        std::cout << Name << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    Hp = Hp - damage;
    if (Hp <= 0) {
        Hp = 0;
        std::cout << Name << " is out of combat." << std::endl;
    }
    else
        std::cout << Name << " takes " << damage << " damage." << std::endl;
}

Peasant::Peasant(const std::string &name, int power)
{
    this->Name = name;
    if (power > 100)
        this->Power = 100;
    else if (power < 0)
        this->Power = 0;
    else
        this->Power = power;
    this->Hp = 100;
    std::cout << Name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << Name << " is back to his crops." << std::endl;
}
