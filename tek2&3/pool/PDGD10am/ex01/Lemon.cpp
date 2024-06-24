/*
** EPITECH PROJECT, 2022
** Lemon
** File description:
** Lemon
*/

#include <string>
#include <iostream>
#include "Lemon.hpp"

Lemon::Lemon() : Fruit ("lemmon", 3)
{
    this->Name = "lemon";
    this->_vitamins = 3;
}

Lemon::Lemon(std::string name, int vitamins) : Fruit (name, vitamins)
{
    this->Name = name;
    this->_vitamins = vitamins;
}

Lemon::~Lemon()
{
}
