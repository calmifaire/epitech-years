/*
** EPITECH PROJECT, 2022
** print time
** File description:
** print_Time
*/

#include "print_Time.hpp"

P_Time::P_Time(sf::RenderWindow &window) : _window(window), _TimE(new sf::Text()), _title(new sf::Text())
{
    _font.loadFromFile("graphic/ressources/font.ttf");
    _texture.loadFromFile("graphic/ressources/square.png", sf::IntRect(0, 0, 0, 0));
     _sprite.setTexture(_texture, true);
     _sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 3.2, sf::VideoMode::getDesktopMode().height / 3.2));
     _sprite.setScale(sf::Vector2f(0.8, 0.55));
    _TimE->setFont(_font);
    _TimE->setCharacterSize(20);
    _TimE->setPosition(sf::Vector2f(735, 475));
    _TimE->setFillColor(sf::Color::Black);
    _title->setFont(_font);
    _title->setCharacterSize(30);
    _title->setPosition(sf::Vector2f(865, 425));
    _title->setFillColor(sf::Color::Black);
    _title->setString("Time");
}

void P_Time::updateValues(IMonitorModule *module)
{
    TimeInfo *time = (TimeInfo *)module;

    _time = time->getLocale();
    _TimE->setString("Time :  " + _time);
}

void P_Time::draw()
{
    _window.draw(_sprite);
    _window.draw(*_TimE);
    _window.draw(*_title);
}