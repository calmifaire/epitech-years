/*
** EPITECH PROJECT, 2021
** Sick
** File description:
** Exercice 03
*/

#include <string>
#include <iostream>
#include "SickKoala.hpp"

void SickKoala::overDrive(std::string x)
{
    while (x.find("Kreog!") != std::string::npos)
        x.replace(x.find("Kreog!"), 6, "1337!");
    std::cout << "Mr." << name << ": " << x << std::endl;
}

bool SickKoala::takeDrug(std::string x)
{
    if (x.compare("Mars") == 0) {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (x.compare("Kinder") == 0) {
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
        return true;
    } else {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::poke(void) {
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

SickKoala::~SickKoala() {
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

SickKoala::SickKoala(std::string x) {
    if (x.length() == 0)
        abort();
    name = x;
}

int main() {
    // Create Car objects and call the constructor with different values
    SickKoala Obj1("G");
    SickKoala Obj2("F");

    // Print value
    Obj1.overDrive("Kreog! How's it going?");
    Obj2.takeDrug("Mars");
    Obj2.takeDrug("");
    return 0;
}
