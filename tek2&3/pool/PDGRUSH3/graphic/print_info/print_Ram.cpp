/*
** EPITECH PROJECT, 2022
** print ram
** File description:
** print_Ram
*/

#include "../../modules/ram.hpp"
#include "print_Ram.hpp"

P_Ram::P_Ram(sf::RenderWindow &window) : _window(window), _TotalRam(new sf::Text()), _RamUsed(new sf::Text()), _title(new sf::Text())
{
    _font.loadFromFile("graphic/ressources/font.ttf");
    _texture.loadFromFile("graphic/ressources/square.png", sf::IntRect(0, 0, 0, 0));
    _sprite.setTexture(_texture, true);
    _sprite.setScale(sf::Vector2f(0.8, 0.55));
    _sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 3.2, 0));
    _TotalRam->setFont(_font);
    _TotalRam->setCharacterSize(20);
    _TotalRam->setPosition(sf::Vector2f(735, 70));
    _TotalRam->setFillColor(sf::Color::Black);
    _RamUsed->setFont(_font);
    _RamUsed->setCharacterSize(20);
    _RamUsed->setPosition(sf::Vector2f(735, 100));
    _RamUsed->setFillColor(sf::Color::Black);
    _title->setFont(_font);
    _title->setCharacterSize(30);
    _title->setPosition(sf::Vector2f(865, 20));
    _title->setFillColor(sf::Color::Black);
    _title->setString("RAM");
}

P_Ram::~P_Ram()
{
    delete _TotalRam;
    delete _RamUsed;
}

void P_Ram::updateValues(IMonitorModule *module)
{
    Ram *ram = (Ram *)module;
    _totalRam = ram->GetRamTotal();
    _ramUsed = ram->GetUsedRam();
    _TotalRam->setString("Total memory :  " + std::to_string(_totalRam) + " Go");
    _RamUsed->setString("Memory used :  " + std::to_string(_ramUsed) + " Go");
}

void P_Ram::draw()
{
    _window.draw(_sprite);
    _window.draw(*_TotalRam);
    _window.draw(*_RamUsed);
    _window.draw(*_title);
}