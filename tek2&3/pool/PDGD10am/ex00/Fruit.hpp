/*
** EPITECH PROJECT, 2022
** fruit
** File description:
** fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <iostream>

class Fruit {
protected:
    std::string Name;
    int _vitamins;
public:
    const std::string getName() const;
    int getVitamins() const;
    Fruit(std::string, int);
    ~Fruit();
};

#endif /* FRUIT_HPP_ */
