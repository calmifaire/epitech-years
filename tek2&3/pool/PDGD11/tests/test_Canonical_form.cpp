/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "../ex01/Toy.hpp"
#include  <criterion/criterion.h>

Test(utils , is_str_length_equal_to_len_v1)
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "../alien.txt");
    toto.setName("TOTO!");
    Toy lol(toto);
    Toy copy;
    copy = ET;
    cr_assert_eq(lol.getName(), toto.getName());
    cr_assert_eq(copy.getType(), ET.getType());
    cr_assert_eq(lol.getName(),toto.getName());
    cr_assert_eq(copy.getName(), ET.getName());
    cr_assert_eq(lol.getAscii(), toto.getAscii());
    cr_assert_eq(copy.getAscii(), ET.getAscii());
}
