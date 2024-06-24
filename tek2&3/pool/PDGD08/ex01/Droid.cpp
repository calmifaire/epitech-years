/*
** EPITECH PROJECT, 2022
** Droid
** File description:
** droid
*/

#include <string>
#include <iostream>
#include "Droid.hpp"

std::ostream& operator<<(std::ostream& os, const Droid& dt)
{
    os << "Droid '" << dt.getId() << "', " << dt.getStatus() << ", " << dt.getEnergy();
    return os;
}

Droid::~Droid() {
    delete this->Status;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

void Droid::setStatus(std::string *s) {
    delete Status;
    Status = s;
}

void Droid::setId(std::string s) {
    Id = s;
}

void Droid::setEnergy(size_t s) {
    if (s > 100)
        Energy = Energy;
    else
        Energy = s;
}

std::string Droid::getStatus() const {
    std::string strNew = *Status;
    return strNew;
}

std::string Droid::getId() const {
    return Id;
}

size_t Droid::getEnergy() const {
    return Energy;
}

size_t Droid::getAttack() {
    return Attack;
}

size_t Droid::getToughness() {
    return Toughness;
}

void Droid::operator<<(size_t &d)
{
    for (; Energy != 100 && d != 0; Energy++, d--);
}

Droid& Droid::operator=(const Droid& d)
{
    this->Id = d.Id;
    return *this;
}

size_t Droid::operator!=(const Droid& d)
{
    if (this->Status != d.Status)
        return (1);
    return (0);
}

size_t Droid::operator==(const Droid& d)
{
    if (this->Status != d.Status)
        return (0);
    return (1);
}

Droid::Droid(const Droid& d)
{
    
    this->Id = d.Id;
    this->Energy = d.Energy;
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::Droid() {
    this->Id = "";
    this->Energy = 50;
    std::cout << "Droid \"" << Id << " Activated" << std::endl;
}

Droid::Droid(std::string x) {
    this->Id = x;
    this->Energy = 50;
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}
