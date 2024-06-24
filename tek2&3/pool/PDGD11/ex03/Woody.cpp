/*
** EPITECH PROJECT, 2022
** Woody
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string n, std::string file) : Toy(BUZZ, n, file)
{
    this->name = n;
    this->type = WOODY;
}

Woody::Woody(std::string n) : Toy(BUZZ, n, "woody.txt")
{
    this->name = n;
    this->type = WOODY;
}

void Woody::speak(std::string statement)
{
    std::cout << "WOODY: " << getName() << " \"" << statement << "\"" << std::endl;
}
