/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** InitSfml
*/

#include "InitSfml.hpp"
#include <SFML/Graphics.hpp>

/**
 * It creates a window with the given width, height and name
 *
 * @param widthWindow The width of the window
 * @param heightWindow The height of the window
 * @param nameWindow The name of the window
 */
InitSfml::InitSfml(int widthWindow, int heightWindow, const std::string& nameWindow)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(widthWindow, heightWindow), nameWindow, sf::Style::Titlebar | sf::Style::Close);
    _window->setFramerateLimit(60);
    _heightWindow = heightWindow;
    _widthWindow = widthWindow;
}

/**
 * It returns a reference to the event object
 *
 * @return The event.
 */
sf::Event& InitSfml::getEvent()
{
    return _event;
}

/**
 * This function returns a pointer to the window.
 *
 * @return A pointer to a shared pointer to a RenderWindow object.
 */
std::shared_ptr<sf::RenderWindow> InitSfml::getWindow()
{
    return _window;
}

/**
 * It takes an id and a path to a texture, loads the texture from the path, and
 * then adds it to the texture list
 *
 * @param idTexture The name of the texture.
 * @param namePath The path to the texture file.
 */
void InitSfml::setTexture(std::string idTexture, std::string namePath)
{
    sf::Texture texture;

    texture.loadFromFile(namePath);
    _textureList.emplace(idTexture, std::make_shared<sf::Texture>(texture));
}

/**
 * If the texture exists, return it, else return nullptr
 *
 * @param idTexture The id of the texture you want to get.
 *
 * @return A pointer to a texture.
 */
std::shared_ptr<sf::Texture> InitSfml::getTexture(std::string idTexture) const
{
    if (_textureList.find(idTexture) == _textureList.end())
        return nullptr;
    return _textureList.at(idTexture);
}

/**
 * This function returns a map of all the textures that have been loaded into the
 * game
 *
 * @return A map of string and shared_ptr of sf::Texture
 */
std::map<std::string, std::shared_ptr<sf::Texture>> InitSfml::getAllTexture()
{
    return _textureList;
}

/**
 * It loads a font from a file
 *
 * @param namePath The path to the font file.
 */
void InitSfml::setFont(std::string idFont, std::string namePath)
{
    sf::Font font;
    font.loadFromFile(namePath);
    _fontList.emplace(idFont, std::make_shared<sf::Font>(font));
}

std::shared_ptr<sf::Font> InitSfml::getFont(std::string idFont) const
{
    return _fontList.at(idFont);
}

std::map<std::string, std::shared_ptr<sf::Font>> InitSfml::getAllFont()
{
    return _fontList;
}

/**
 * Get the width of the window.
 *
 * @return The width of the window.
 */
int InitSfml::getWidthWindow()
{
    return _widthWindow;
}

/**
 * Get the height of the window.
 *
 * @return The height of the window.
 */
int InitSfml::getHeightWindow()
{
    return _heightWindow;
}

/**
 * It clears the window.
 */
void InitSfml::clear()
{
    _window->clear();
}

/**
 * It displays the window
 */
void InitSfml::display()
{
    _window->display();
}
