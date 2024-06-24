/*
** EPITECH PROJECT, 2022
** fruitbox
** File description:
** fruitbox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
protected:
    int size;
    int currentnb;
    FruitNode* headlist;
public:
    FruitBox(int size);
    virtual ~FruitBox();
    int getSize() const;
    int nbFruits() const;
    bool putFruit(Fruit* f);
    Fruit* pickFruit();
    FruitNode* head() const;
};

#endif
