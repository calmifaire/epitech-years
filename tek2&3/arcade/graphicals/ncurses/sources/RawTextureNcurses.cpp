/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureNcurses
*/

#include "RawTextureNcurses.hpp"

RawTextureNcurses::RawTextureNcurses(char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height)
{
    _character = character;
    _color = (8 * (int)backgroundColor) + (int)characterColor + 1;
    _width = width;
    _height = height;
}

RawTextureNcurses::~RawTextureNcurses()
{
}

char RawTextureNcurses::getCharacter(void)
{
    return (_character);
}

int RawTextureNcurses::getColor(void)
{
    return (_color);
}

std::size_t RawTextureNcurses::getWidth(void)
{
    return (_width);
}

std::size_t RawTextureNcurses::getHeight(void)
{
    return (_height);
}
