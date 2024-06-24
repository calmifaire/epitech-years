/*
** EPITECH PROJECT, 2022
** droidmemory
** File description:
** memo
*/

#include <string>
#include <iostream>
#include "DroidMemory.hpp"

std::ostream& operator<<(std::ostream& os, const DroidMemory& dt)
{
    os << "DroidMemory '" << dt.getFingerprint() << "', " << dt.getExp();
    return os;
}

DroidMemory::DroidMemory()
{
    Exp = 0;
}

void DroidMemory::setFingerprint(size_t s)
{
    Fingerprint = s;
}

void DroidMemory::setExp(size_t s)
{
    Exp = s;
}

size_t DroidMemory::getFingerprint() const
{
    return Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return Exp;
}

void DroidMemory::operator<<(DroidMemory const d)
{
    Exp = Exp + d.Exp;
    Fingerprint = Fingerprint ^ d.Fingerprint;
}

void DroidMemory::operator>>(DroidMemory &d)
{
    d.Exp = d.Exp + Exp;
    d.Fingerprint = d.Fingerprint ^ Fingerprint;
}

void DroidMemory::operator+=(DroidMemory const d)
{
    Exp = Exp + d.Exp;
    Fingerprint = Fingerprint ^ d.Fingerprint;
}

void DroidMemory::operator+=(size_t d)
{
    Exp = Exp + d;
    Fingerprint = Fingerprint ^ d;
}
