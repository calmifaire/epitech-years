/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** blocksys
*/

#include "print_Os.hpp"

P_sys::P_sys(sf::RenderWindow &window) : _window(window), _title(new sf::Text()), _printOs(new sf::Text()),
    _printDistrib(new sf::Text())
{
    _font.loadFromFile("graphic/ressources/font.ttf");
    _texture.loadFromFile("graphic/ressources/square.png", sf::IntRect(0, 0, 0, 0));
    _sprite.setTexture(_texture, true);
    _sprite.setPosition(sf::Vector2f(0, sf::VideoMode::getDesktopMode().height / 3.2));
    _sprite.setScale(sf::Vector2f(0.8, 0.55));
    _title->setFont(_font);
    _title->setCharacterSize(30);
    _title->setPosition(sf::Vector2f(110, 425));
    _title->setFillColor(sf::Color::Black);
    _title->setString("System info");
    _printOs->setFont(_font);
    _printOs->setCharacterSize(20);
    _printOs->setPosition(sf::Vector2f(50, 475));
    _printOs->setFillColor(sf::Color::Black);
    _printDistrib->setFont(_font);
    _printDistrib->setCharacterSize(20);
    _printDistrib->setPosition(sf::Vector2f(50, 505));
    _printDistrib->setFillColor(sf::Color::Black);
}

P_sys::~P_sys()
{
    delete _printDistrib;
    delete _printOs;
}

void P_sys::updateValues(IMonitorModule *module)
{
    System *sys = (System *)module;
    _os = sys->getOs();
    _distrib = sys->getDistrib();
    _printOs->setString("system os :  " + _os);
    _printDistrib->setString("distribution :  " + _distrib);
}

void P_sys::draw()
{
    _window.draw(_sprite);
    _window.draw(*_title);
    _window.draw(*_printOs);
    _window.draw(*_printDistrib);
}