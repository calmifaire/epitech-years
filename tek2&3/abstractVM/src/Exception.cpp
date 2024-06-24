/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Exception
*/

#include "Include.hpp"

Exception::Exception(const char *text) throw()
{
    _message = text;
}

Exception::Exception(std::string text) throw()
{
    _message = text;
}

const char *Exception::what() const throw()
{
    return (_message.c_str());
}
