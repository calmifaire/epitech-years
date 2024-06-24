/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArgumentChecker
*/

#include "ArgumentChecker.hpp"

void ArgumentChecker::CheckNumber(int ac)
{
    if (ac != 2)
        throw ArcadeError("wrong argument", "wrong number of argument");
}

void *ArgumentChecker::CheckAndOpenLibrary(char *arg)
{
    void *lib = NULL;

    if (!(lib = dlopen(arg, RTLD_NOW)))
        throw ArcadeError("dlopen error", dlerror());
    if (!dlsym(lib, "gEpitechArcadeGetDisplayModuleHandle")) {
        dlclose(lib);
        throw ArcadeError("wrong library type", "the library provided as argument is not an appropriate graphical library");
    }
    return (lib);
}
