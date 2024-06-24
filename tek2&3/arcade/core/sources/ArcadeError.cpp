/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeError
*/

#include "ArcadeError.hpp"

ArcadeError::ArcadeError(std::string const &type, std::string const &message)
{
    _message = "arcade: Caught an error of type '";
    _message.append(type);
    _message.append("': '");
    _message.append(message);
    _message.append("'");
}

ArcadeError::~ArcadeError()
{
}

const char *ArcadeError::what() const noexcept
{
    return (_message.data());
}