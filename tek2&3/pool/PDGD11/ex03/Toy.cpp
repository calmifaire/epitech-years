/*
** EPITECH PROJECT, 2022
** Toy
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

std::string Toy::getAscii() const
{
    return picture.data;
}

void Toy::setName(std::string n)
{
    name = n;
}

void Toy::setAscii(std::string file)
{
    picture.getPictureFromFile(file);
}

Toy::Toy() :
    picture("")
{
    this->name = "toy";
    this->type = BASIC_TOY;
}

Toy::Toy(Toy::ToyType t, std::string n, std::string file) :
    picture(file)
{
    this->name = n;
    this->type = t;
}

Toy::Toy(const Toy& n) :
    picture(n.picture)
{
    this->name = n.name;
    this->type = n.type;
}

Toy& Toy::operator=(const Toy& n)
{
    this->name = n.name;
    this->type = n.type;
    this->picture = n.picture;
    return *this;
}

void Toy::speak(std::string statement)
{
    std::cout << getName() << " \"" << statement << "\"" << std::endl;
}

Toy::~Toy()
{}
