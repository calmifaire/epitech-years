/*
** EPITECH PROJECT, 2022
** test1
** File description:
** criterion
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/Include.hpp"
#include "../src/Factory.hpp"

static int read_file(char *file)
{
    int i = 1;
    std::ifstream infile(file);
    Parser parser;
    Factory factory;
    std::string input;

   while (std::getline(infile, input)){
        input = parser.trim(input);
        if (input.size() != 0 && input.at(0) != ';')
            parser.Push_input(input);
    }
    if ((i = parser.check_file()) != 0) {
        if (i == 1)
            throw Exception("wrong command or error syntax");
        if (i == 2)
            throw Exception("no exit");
        if (i == 3)
            throw Exception("nothing to use");
        if (i == 4)
            throw Exception("only int8 for store and load");
    }
    else
        i = factory.loop(parser.get_parse());
    return (i);
}

Test( test_fail , unkown_command )
{
    int i = 1;

    try
    {
        cr_redirect_stderr();
        read_file("test_fail.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stderr_eq_str("wrong command or error syntax\n");
    cr_assert_neq(i, 0);
}

Test( test_parsing , test_succefull)
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test_parsing.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("-555555.555555555555555\n41\n41\nE\n\0");
    cr_assert_eq(i, 0);
}

Test( test , success)
{
   int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("3\n\0");
    cr_assert_eq(i, 0);
}

Test( test1 , test_give_subject)
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test1.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("42\n42.42\n3341.25\n\0");
    cr_assert_eq(i, 0);
}

Test( test2 , success)
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test2.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("a\n)\n65\n41\n89.66\n14\n-16\n97\n\0");
    cr_assert_eq(i, 0);
}

Test( test3 , success)
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test3.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("34\n\0");
    cr_assert_eq(i, 0);
}

Test( test4 , fail_exit )
{
    int i = 1;

    try
    {
        cr_redirect_stderr();
        read_file("test4.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stderr_eq_str("wrong command or error syntax\n");
    cr_assert_neq(i, 0);
}

Test( test5 , test_succefull2n )
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test5.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("25\n0\n\0");
    cr_assert_eq(i, 0);
}

Test( test6 , failassert )
{
    int i = 1;

    try
    {
        cr_redirect_stderr();
        read_file("test6.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stderr_eq_str("Assert instruction with different value\n\0");
    cr_assert_neq(i, 0);
}

Test( test7 , test_dup_clear )
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test7.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("42\n42\n10\n\n\0");
    cr_assert_eq(i, 0);
}

Test( test8, failassert )
{
    int i = 1;

    try
    {
        cr_redirect_stderr();
        read_file("test8.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stderr_eq_str("Underflow !\n\0");
    cr_assert_neq(i, 0);
}

Test( test9 , test_dup_clear )
{
    int i = 1;

    try
    {
        cr_redirect_stdout();
        i = read_file("test9.avm");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cr_assert_stdout_eq_str("-89.795023\n\0");
    cr_assert_eq(i, 0);
}