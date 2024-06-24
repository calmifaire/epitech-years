/*
** EPITECH PROJECT, 2022
** paladin
** File description:
** paladin
*/

#include <string>
#include <iostream>
#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest
{
public:
    explicit Paladin(const std::string &name, int power);
    using Knight::attack;
    using Priest::special;
    using Priest::rest;
    ~Paladin();
};
