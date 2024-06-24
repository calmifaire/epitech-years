/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureSfml
*/

#include "RawTextureSfml.hpp"

RawTextureSfml::RawTextureSfml(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, u_int32_t pixelsPerCell)
{
    if (pngFilename.back() == 'f' || pngFilename.back() == 'F' ) {
        _isASCII = true;
        _ascii.create(pixelsPerCell, pixelsPerCell);
        sf::Font font;
        font.loadFromFile(pngFilename);
        sf::Text text(character, font, pixelsPerCell);
        text.setFillColor(colorToSfmlColor.at(characterColor));
        text.setOutlineColor(colorToSfmlColor.at(characterColor));
        _ascii.clear(colorToSfmlColor.at(backgroundColor));
        _ascii.draw(text);
        _ascii.display();
        return;
    }
    _isASCII = false;
    _texture.loadFromFile(pngFilename);
}

RawTextureSfml::~RawTextureSfml()
{
}

const sf::Texture &RawTextureSfml::getTexture()
{
    if (_isASCII)
        return (_ascii.getTexture());
    return (_texture);
}