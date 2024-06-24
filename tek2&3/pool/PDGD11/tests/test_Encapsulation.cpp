/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "../ex00/Toy.hpp"
#include  <criterion/criterion.h>

Test(utils , is_str_length_equal_to_len_v1)
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "../alien.txt");
    toto.setName("TOTO!");
    cr_assert_eq(toto.getType(), Toy::BASIC_TOY);
    cr_assert_eq(ET.getType(), Toy::ALIEN);
    cr_assert_eq(toto.getName(), "TOTO!");
    cr_assert_eq(ET.getName(), "green");
    cr_assert_eq(toto.getAscii(), "");
}
