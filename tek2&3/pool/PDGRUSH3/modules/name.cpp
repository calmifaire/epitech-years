/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** name
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits.h>
#include <unistd.h>
#include "name.hpp"

User::User()
{
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);

    _hostname = hostname;
    _username = username;
}

User::~User()
{

}

void User::refresh()
{}

std::string User::getuser() const
{
    return _username;
}

std::string User::gethost() const
{
    return _hostname;
}