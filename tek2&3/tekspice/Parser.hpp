/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parser
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Circuit.hpp"
#include "IComponent.hpp"
#include <string>
#include <fstream>
#include <streambuf>
#include <regex>
#include <vector>
#include <cstdio>
#include <utility>
#include <bits/stdc++.h>
#include <iostream>
#include <filesystem>

class Parser
{
public:
    Parser(std::string f);
    ~Parser() {};
private:
    std::string file;
};

#endif
