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

bool Toy::setAscii(std::string file)
{
    if (picture.getPictureFromFile(file) == false)
    {
        error.setType(Error::PICTURE);
        return false;
    }
    return true;
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

void Toy::operator<<(const std::string f)
{
    this->picture.data = f;
}

std::ostream& operator<<(std::ostream& os, const Toy& dt)
{
    os << dt.getName() << std::endl << dt.getAscii() << std::endl;
    return os;
}

bool Toy::speak_es(std::string statement)
{
    (void)statement;
    error.setType(Error::SPEAK);
    return false;
}

Toy::Error::Error()
{
    this->type = UNKNOWN;
}

Toy::Error const & Toy::getLastError() const
{
    return this->error;
}

std::string Toy::Error::what() const
{
    if (type == PICTURE)
        return "bad new illustration";
    else if (type == SPEAK)
        return "wrong mode";
    else
        return "";
}

std::string Toy::Error::where() const
{
    if (type == PICTURE)
        return "setAscii";
    else if (type == SPEAK)
        return "speak_es";
    else
        return "";
}

void Toy::Error::setType(ErrorType t)
{
    type = t;
}
