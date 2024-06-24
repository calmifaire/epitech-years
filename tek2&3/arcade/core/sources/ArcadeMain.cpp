/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

int main(int ac, char **av)
{
    Arcade core;

    try {
        ArgumentChecker::CheckNumber(ac);
        core.setDlGraphical(ArgumentChecker::CheckAndOpenLibrary(av[1]));
        core.initClassFromDl(true);
        core.initActualGraphGraphical(std::string(av[1]));
        core.launchGame();
    }
    catch (ArcadeError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
}