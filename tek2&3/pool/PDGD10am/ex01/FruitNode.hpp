/*
** EPITECH PROJECT, 2022
** fruitnode
** File description:
** fruitnode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

struct FruitNode {
    Fruit* fnode;
    FruitNode *next;
};

#endif /* FRUITNODE_HPP_ */
