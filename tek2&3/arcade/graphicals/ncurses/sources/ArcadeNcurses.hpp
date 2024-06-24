/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#ifndef ARCADENCURSES_HPP_
#define ARCADENCURSES_HPP_

#define UNUSED(x) (void)(x)

#include "ICore.hpp"
#include <iostream>
#include <curses.h>
#include <map>

class ArcadeNcurses : public IDisplayModule {
    public:
        ArcadeNcurses();
        ~ArcadeNcurses();
        void setPixelsPerCell(std::uint32_t pixelsPerCell);
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

        WINDOW *getWindow();
        void setWindow(WINDOW *win);
        void initAllColorPair();
        int findPair(IDisplayModule::Color foreground, IDisplayModule::Color background);

    protected:
        std::uint32_t _pixelsPerCell;
        WINDOW *_win;
        int _input;
        bool _isTextInputOn;
        std::string _textInput;
    private:
};

extern const std::map<IDisplayModule::Button, int> keyToCursesKey;


#endif /* !ARCADENCURSES_HPP_ */
