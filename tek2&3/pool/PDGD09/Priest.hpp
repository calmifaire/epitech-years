/*
** EPITECH PROJECT, 2022
** priest
** File description:
** priest
*/

#include <string>
#include <iostream>
#include "Enchanter.hpp"

class Priest : public Enchanter
{
public:
    explicit Priest(const std::string &name, int power);
    void rest();
    ~Priest();
};
