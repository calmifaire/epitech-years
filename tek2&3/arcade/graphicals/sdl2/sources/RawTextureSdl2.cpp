/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureSdl2
*/

#include "RawTextureSdl2.hpp"

RawTextureSdl2::RawTextureSdl2(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, u_int32_t pixelsPerCell, SDL_Renderer *renderer)
{
    if (pngFilename.back() == 'f' || pngFilename.back() == 'F' ) {
        _isASCII = true;
        TTF_Font *font = TTF_OpenFont(pngFilename.c_str(), pixelsPerCell);
        std::string str = "";
        str.push_back(character);
        SDL_Color charaColor = {
            std::get<0>(colorToSdl2Color[(int)characterColor]),
            std::get<1>(colorToSdl2Color[(int)characterColor]),
            std::get<2>(colorToSdl2Color[(int)characterColor]),
            255,
        };
        SDL_Color bgColor = {
            std::get<0>(colorToSdl2Color[(int)backgroundColor]),
            std::get<1>(colorToSdl2Color[(int)backgroundColor]),
            std::get<2>(colorToSdl2Color[(int)backgroundColor]),
            255,
        };
        SDL_Surface *surface = TTF_RenderGlyph_Shaded(font, character, charaColor, bgColor);
        _ascii = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        return;
    }
    _isASCII = false;
    _texture = IMG_LoadTexture(renderer, pngFilename.c_str());
}

RawTextureSdl2::~RawTextureSdl2()
{
}

SDL_Texture *RawTextureSdl2::getTexture()
{
    if (_isASCII)
        return (_ascii);
    return (_texture);
}