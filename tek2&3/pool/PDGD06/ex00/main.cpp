/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    for (int i = 1; i != ac; i++) {
        std::ifstream f(av[i]);
        if (f.is_open())
            std::cout << f.rdbuf();
        else
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
    }
    return (0);
}
