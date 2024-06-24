/*
** EPITECH PROJECT, 2022
** knight
** File description:
** knight
*/

#include <string>
#include <iostream>
#include "Peasant.hpp"

class Knight : virtual public Peasant
{
public:
    int special();
    void rest();
    int attack();
    explicit Knight(const std::string &name, int power);
    ~Knight();
};
