/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeSdl2
*/

#ifndef ARCADESDL2_HPP_
#define ARCADESDL2_HPP_

#define UNUSED(x) (void)(x)

#include "ICore.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <vector>
#include <map>

class ArcadeSdl2 : public IDisplayModule {
    public:
        ArcadeSdl2();
        ~ArcadeSdl2();
        void setPixelsPerCell(std::uint32_t PixelsPerCell);
        std::uint32_t getPixelsPerCell(void);
        std::unique_ptr<IDisplayModule::RawTexture> loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height);
        void openWindow(IDisplayModule::Vector2u pixelsWantedWindowSize);
        bool isButtonPressed(IDisplayModule::Button button);
        IDisplayModule::MouseButtonReleaseEvent getMouseButtonReleaseEvent();
        bool isClosing();
        void startTextInput();
        std::string getTextInput();
        void endTextInput();
        void clearScreen(IDisplayModule::Color color);
        void renderSprite(IDisplayModule::Sprite sprite);
        void display();
        void update();

    protected:
        std::uint32_t _pixelsPerCell;
        SDL_Window *_win;
        SDL_Renderer *_renderer;
        bool _isTextInputOn;
        bool _isClosing;
        std::string _textInput;
        IDisplayModule::MouseButtonReleaseEvent _mouseEvent;
        std::map<SDL_Scancode, bool> _keyPressedMap;
    private:
};

extern const std::vector<std::tuple<uint8_t, uint8_t, uint8_t>> colorToSdl2Color;
extern const std::unordered_map<IDisplayModule::Button, SDL_Scancode> keystoSdl2keys;

#endif /* !ARCADESDL2_HPP_ */
