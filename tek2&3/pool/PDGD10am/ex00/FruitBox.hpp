/*
** EPITECH PROJECT, 2022
** fruitbox
** File description:
** fruitbox
*/

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
protected:
    int size;
    int currentnb;
    FruitNode* headlist;
public:
    FruitBox(int size);
    ~FruitBox();
    int nbFruits();
    bool putFruit(Fruit* f);
    Fruit* pickFruit();
    FruitNode* head();
};
