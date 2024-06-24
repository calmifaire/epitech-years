/*
** EPITECH PROJECT, 2022
** Buzz
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string n, std::string file) : Toy(BUZZ, n, file)
{
    this->name = n;
    this->type = BUZZ;
}

Buzz::Buzz(std::string n) : Toy(BUZZ, n, "buzz.txt")
{
    this->name = n;
    this->type = BUZZ;
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
}
