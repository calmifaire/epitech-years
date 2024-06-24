/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Texture
*/

#include "Texture.hpp"

ICore::Texture::Texture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height, std::unique_ptr<IDisplayModule::RawTexture> texture)
{
    _pngFilename = pngFilename;
    _character = character;
    _characterColor = characterColor;
    _backgroundColor = backgroundColor;
    _width = width;
    _height = height;
    _texture = std::move(texture);
}

ICore::Texture::~Texture()
{
}

void ICore::Texture::setTexture(std::unique_ptr<IDisplayModule::RawTexture> texture)
{
    _texture = std::move(texture);
}

IDisplayModule::RawTexture *ICore::Texture::getTexture(void)
{
    return (_texture.get());
}

void ICore::Texture::destroyRawTexture(void)
{
    _texture = nullptr;
}

const std::string &ICore::Texture::getPngFilename(void)
{
    return (_pngFilename);
}

char ICore::Texture::getCharacter(void)
{
    return (_character);
}

ICore::Color ICore::Texture::getCharacterColor(void)
{
    return (_characterColor);
}

ICore::Color ICore::Texture::getBackgroundColor(void)
{
    return (_backgroundColor);
}

std::size_t ICore::Texture::getWidth(void)
{
    return (_width);
}

std::size_t ICore::Texture::getHeight(void)
{
    return (_height);
}
