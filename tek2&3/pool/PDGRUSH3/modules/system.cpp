/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** system
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include "system.hpp"

System::System()
{
	struct utsname sysinfo;

    if (uname(&sysinfo) == -1) {
        perror("uname");
        exit (1);
    }
    _os = sysinfo.sysname;
    _os = _os + " ";
    _os = _os + sysinfo.machine;
    _kernel = sysinfo.release;
}

System::~System()
{
}

void System::refresh()
{}

std::string System::getOs() const
{
    return _os;
}

std::string System::getDistrib() const
{
    return _kernel;
}

