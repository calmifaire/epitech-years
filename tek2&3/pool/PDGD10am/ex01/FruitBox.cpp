/*
** EPITECH PROJECT, 2022
** FruitBox
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int s)
{
    this->size = s;
    this->currentnb = 0;
    this->headlist = NULL;
}

FruitBox::~FruitBox()
{}

int FruitBox::nbFruits() const
{
    return currentnb;
}

int FruitBox::getSize() const
{
    return size;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (!f)
        return false;
    if (currentnb < size)
    {
        FruitNode* node = new FruitNode();
        FruitNode* tmp;
        FruitNode* prev = 0;
        tmp = headlist;
        while (tmp)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        tmp = node;
        if (prev)
            prev->next = tmp;
        tmp->fnode = f;
        tmp->next = NULL;
        if (!headlist)
            headlist = tmp;
        currentnb++;
        return true;
    }
    return false;
}

Fruit* FruitBox::pickFruit()
{
    if (currentnb != 0) {
        FruitNode* del = headlist;
        Fruit* fruit = del->fnode;
        headlist = headlist->next;
        delete del;
        currentnb--;
        return fruit;
    }
    return NULL;
}

FruitNode* FruitBox::head() const
{
    return headlist;
}
