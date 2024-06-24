/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "../ex01/Banana.hpp"
#include "../ex01/FruitBox.hpp"
#include "../ex01/Lime.hpp"
#include "../ex01/FruitNode.hpp"
#include "../ex01/LittleHand.hpp"
#include  <criterion/criterion.h>

Test(utils , is_str_length_equal_to_len_v1)
{
    Lemon l;
    Banana b;
    Lime i;
    Fruit& f = l;
    Fruit& t = b;
    Fruit& k = i;
    FruitBox un(3);
    FruitBox banana(3);
    FruitBox lemon(3);
    FruitBox lime(3);
    LittleHand little;
    un.putFruit(&f);
    un.putFruit(&t);
    un.putFruit(&k);
    little.sortFruitBox(un, lemon, banana, lime);
    cr_assert(un.nbFruits() == 0);
    cr_assert(banana.nbFruits() == 1);
    cr_assert(lemon.nbFruits() == 1);
    cr_assert(lime.nbFruits() == 1);
}
