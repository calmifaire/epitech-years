/*
** EPITECH PROJECT, 2022
** print user
** File description:
** print_User
*/

#include "../../modules/name.hpp"
#include "print_User.hpp"

P_user::P_user(sf::RenderWindow &window) : _window(window), _title(new sf::Text()), _TUsername(new sf::Text()),
    _THostename(new sf::Text())
{
    _font.loadFromFile("graphic/ressources/font.ttf");
    _texture.loadFromFile("graphic/ressources/square.png", sf::IntRect(0, 0, 0, 0));
    _sprite.setTexture(_texture, true);
    _sprite.setPosition(sf::Vector2f(0, 0));
    _sprite.setScale(sf::Vector2f(0.8, 0.55));
    _title->setFont(_font);
    _title->setString("User");
    _title->setCharacterSize(30);
    _title->setPosition(sf::Vector2f(125, 20));
    _title->setFillColor(sf::Color::Black);
    _TUsername->setFont(_font);
    _TUsername->setCharacterSize(20);
    _TUsername->setPosition(sf::Vector2f(50, 70));
    _TUsername->setFillColor(sf::Color::Black);
    _THostename->setFont(_font);
    _THostename->setCharacterSize(20);
    _THostename->setPosition(sf::Vector2f(50, 100));
    _THostename->setFillColor(sf::Color::Black);
}

void P_user::updateValues(IMonitorModule *module)
{
    User *user = (User *)module;

    _username = user->getuser();
    _hostname = user->gethost();
    _TUsername->setString("username :  " + _username);
    _THostename->setString("hostname :  " + _hostname);
}

void P_user::draw()
{
    _window.draw(_sprite);
    _window.draw(*_title);
    _window.draw(*_TUsername);
    _window.draw(*_THostename);
}