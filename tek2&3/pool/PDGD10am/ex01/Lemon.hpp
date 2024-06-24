/*
** EPITECH PROJECT, 2022
** lemon
** File description:
** lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include <string>
#include <iostream>
#include "Fruit.hpp"

class Lemon : public Fruit
{
public:
    Lemon();
    Lemon(std::string name, int vitamins);
    virtual ~Lemon();
};

#endif
