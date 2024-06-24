/*
** EPITECH PROJECT, 2022
** banana
** File description:
** banana
*/

#include <string>
#include <iostream>
#include "Banana.hpp"

Banana::Banana() : Fruit ("banana", 5)
{
	this->Name = "banana";
    this->_vitamins = 5;
}

Banana::~Banana()
{
}
