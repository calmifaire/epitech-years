/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** ram
*/
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include "ram.hpp"

Ram::Ram()
{
}

Ram::~Ram()
{}

void Ram::refresh()
{
    struct sysinfo memInfo;

    sysinfo(&memInfo);
    _totalram = (float)memInfo.totalram / (float)1000000000;
    _ramused = ((float)memInfo.totalram - (float)memInfo.freeram) / (float)1000000000;
}

float Ram::GetRamTotal() const
{
    return _totalram;
}

float Ram::GetUsedRam() const
{
    return _ramused;
}