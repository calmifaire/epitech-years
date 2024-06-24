/*
** EPITECH PROJECT, 2022
** main
** File description:
** test
*/

#include "IComponent.hpp"
#include <string>
#include <fstream>
#include <streambuf>
#include <regex>
#include <vector>
#include <cstdio>
#include <utility>
#include <bits/stdc++.h>
#include <filesystem>
#include "Parser.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "argument error" << std::endl;
        return 84;
    }
    try{
    Parser p(av[1]);
    }
    catch (const std::exception& e){
		return 84;
	}
    return (0);
}
