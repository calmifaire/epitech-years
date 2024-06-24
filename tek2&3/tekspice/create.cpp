/*
** EPITECH PROJECT, 2022
** create
** File description:
** create
*/

#include <string>
#include <fstream>
#include <streambuf>
#include <regex>
#include <vector>
#include <cstdio>
#include <utility>
#include <bits/stdc++.h>
#include "./Component/Input.hpp"
#include "./Component/Output.hpp"
#include "./Component/True.hpp"
#include "./Component/False.hpp"
#include "./Component/Clock.hpp"
#include "./Component/4069.hpp"

std::unique_ptr<nts::IComponent> create4069()
{
    std::unique_ptr<nts::IComponent> ret(new not_4069());
    return ret;
}

std::unique_ptr<nts::IComponent> createClock()
{
    std::unique_ptr<nts::IComponent> ret(new Clock());
    return ret;
}

std::unique_ptr<nts::IComponent> createFalse()
{
    std::unique_ptr<nts::IComponent> ret(new False());
    return ret;
}

std::unique_ptr<nts::IComponent> createInput()
{
    std::unique_ptr<nts::IComponent> ret(new Input());
    return ret;
}

std::unique_ptr<nts::IComponent> createTrue()
{
    std::unique_ptr<nts::IComponent> ret(new True());
    return ret;
}

std::unique_ptr<nts::IComponent> createOutput()
{
    std::unique_ptr<nts::IComponent> ret(new Output());
    return ret;
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    if (type == "input")
        return createInput();
    if (type == "output")
        return createOutput();
    if (type == "true")
        return createTrue();
    if (type == "false")
        return createFalse();
    if (type == "clock")
        return createClock();
    if (type == "4069")
        return create4069();
    std::cout << "unknow component\n";
    throw std::exception();
}
