/*
** EPITECH PROJECT, 2022
** LittleHand
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit* t;
    FruitBox tm(unsorted.nbFruits());

    while (t = unsorted.pickFruit())
        tm.putFruit(t);
    while ((t = tm.pickFruit()))
    {
        if (dynamic_cast<Banana*>(t) && t->getVitamins() == 5 && bananas.nbFruits() < bananas.getSize())
            bananas.putFruit(t);
        else if (t->getVitamins() == 0 && lemons.nbFruits() < lemons.getSize())
            lemons.putFruit(t);
        else if (dynamic_cast<Lemon*>(t) && t->getVitamins() == 3 && lemons.nbFruits() < lemons.getSize())
            lemons.putFruit(t);
        else if (dynamic_cast<Lime*>(t) && t->getVitamins() == 2 && limes.nbFruits() < limes.getSize())
            limes.putFruit(t);
        else
            unsorted.putFruit(t);
    }
}
