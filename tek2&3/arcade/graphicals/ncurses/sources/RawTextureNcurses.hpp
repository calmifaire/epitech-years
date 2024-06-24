/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** RawTextureNcurses
*/

#ifndef RAWTEXTURENCURSES_HPP_
#define RAWTEXTURENCURSES_HPP_

#include "ArcadeNcurses.hpp"

class RawTextureNcurses : public IDisplayModule::RawTexture {
    public:
        RawTextureNcurses(char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height);
        RawTextureNcurses(RawTextureNcurses&&) = default;
        ~RawTextureNcurses();
        char getCharacter(void);
        int getColor(void);
        std::size_t getWidth(void);
        std::size_t getHeight(void);
    protected:
        char _character;
        int _color;
        std::size_t _width;
        std::size_t _height;
    private:
};

#endif /* !RAWTEXTURENCURSES_HPP_ */
