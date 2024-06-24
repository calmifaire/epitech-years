/*
** EPITECH PROJECT, 2022
** core.cpp
** File description:
** core
*/

#include "core.hpp"

Core::Core()
{
    addModule(new User());
    addModule(new Ram());
    addModule(new TimeInfo());
    addModule(new System());
}

void Core::addModule(IMonitorModule *module)
{
    _modules.push_back(module);
}

void Core::refresh()
{
    std::list<IMonitorModule *>::const_iterator iterator;

    for (iterator = _modules.begin(); iterator != _modules.end(); iterator++) {
        (*iterator)->refresh();
    }
}