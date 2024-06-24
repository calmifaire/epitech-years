/*
** EPITECH PROJECT, 2022
** enchanter
** File description:
** enchanter
*/

#include <string>
#include <iostream>
#include "Peasant.hpp"

class Enchanter : virtual public Peasant
{
public:
    void rest();
    explicit Enchanter(const std::string &name, int power);
    int attack();
    int special();
    ~Enchanter();
};
