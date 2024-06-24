/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureSfml
*/

#ifndef RAWTEXTURESFML_HPP_
#define RAWTEXTURESFML_HPP_

#include "ArcadeSfml.hpp"

class RawTextureSfml : public IDisplayModule::RawTexture {
    public:
        RawTextureSfml(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, u_int32_t pixelsPerCell);
        RawTextureSfml(RawTextureSfml&&) = default;
        ~RawTextureSfml();
        const sf::Texture &getTexture();

    protected:
        sf::Texture _texture;
        sf::RenderTexture _ascii;
        bool _isASCII;
    private:
};

#endif /* !RAWTEXTURESFML_HPP_ */
