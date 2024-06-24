/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureSdl2
*/

#ifndef RAWTEXTURESDL2_HPP_
#define RAWTEXTURESDL2_HPP_

#include "ArcadeSdl2.hpp"

class RawTextureSdl2 : public IDisplayModule::RawTexture {
    public:
        RawTextureSdl2(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, u_int32_t pixelsPerCell, SDL_Renderer *renderer);
        RawTextureSdl2(RawTextureSdl2&&) = default;
        ~RawTextureSdl2();
        SDL_Texture *getTexture();

    protected:
        SDL_Texture *_texture;
        SDL_Texture *_ascii;
        bool _isASCII;
    private:
};

#endif /* !RAWTEXTURESDL2_HPP_ */
