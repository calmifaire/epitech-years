/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeSfml
*/


#ifndef ARCADESFML_HPP_
#define ARCADESFML_HPP_

#define UNUSED(x) (void)(x)

#include "ICore.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <deque>

class ArcadeSfml : public IDisplayModule {
    public:
        ArcadeSfml();
        ~ArcadeSfml();
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

    protected:
        std::uint32_t _pixelsPerCell;
        sf::RenderWindow _win;
        sf::View _view;
        bool _isTextInputOn;
        bool _isClosing;
        std::string _textInput;
        std::deque<sf::Event> _evtQueue;
        std::map<sf::Keyboard::Key, bool> _keyPressedMap;
    private:
};

extern const std::map<IDisplayModule::Color, sf::Color> colorToSfmlColor;
extern const std::map<IDisplayModule::Button, sf::Keyboard::Key> keyToSfmlKey;

#endif /* !ARCADESFML_HPP_ */
