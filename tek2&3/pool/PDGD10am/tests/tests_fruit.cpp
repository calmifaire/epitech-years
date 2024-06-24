/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "../ex00/Banana.hpp"
#include "../ex00/FruitBox.hpp"
#include "../ex00/Lemon.hpp"
#include "../ex00/FruitNode.hpp"
#include  <criterion/criterion.h>

Test(utils , is_str_length_equal_to_len_v1)
{
    Lemon l;
    Banana b;
    Fruit& f = l;
    Fruit& t = b;
    FruitBox box(3);
    box.putFruit(&f);
    cr_assert(f.getName() == l.getName());
    cr_assert(t.getName() == b.getName());
    cr_assert(box.nbFruits() == 1);
}
