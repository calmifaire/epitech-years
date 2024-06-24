/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** main
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "graphic/Graphic.hpp"

int main(int ac, char **av)
{
    Core *core = new Core();

    if (ac != 2) {
        std::cout << "./MyGKrellm [-g] to display in graphical mode.\nOR\n./MyGKrellm [-n] to display in text mode." << std::endl;
        return (84);
    }
    else if ((std::string)av[1] == "-g") {
        Init_SFML(core);
    }
    else if ((std::string)av[1] == "-n");
        //Ncurses *ncruse = new Ncurses(core);
    else {
        std::cout << "./MyGKrellm [-g] to display in graphical mode.\nOR\n./MyGKrellm [-n] to display in text mode." << std::endl;
        return (-1);
    }
    return(0);
}