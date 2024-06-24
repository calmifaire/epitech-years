/*
** EPITECH PROJECT, 2022
** Fruit
** File description:
** Fruit
*/

#include <string>
#include <iostream>
#include "Fruit.hpp"

const std::string Fruit::getName() const
{
    return Name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}

Fruit::Fruit(std::string name, int vitamins)
{
	this->Name = name;
    this->_vitamins = vitamins;
}

Fruit::~Fruit()
{}
