/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** CorrespNcurses
*/

#include "ArcadeSfml.hpp"

const std::map<IDisplayModule::Color, sf::Color> colorToSfmlColor = {
    std::make_pair(IDisplayModule::Color::black, sf::Color::Black),
    std::make_pair(IDisplayModule::Color::red, sf::Color::Red),
    std::make_pair(IDisplayModule::Color::green, sf::Color::Green),
    std::make_pair(IDisplayModule::Color::yellow, sf::Color::Yellow),
    std::make_pair(IDisplayModule::Color::blue, sf::Color::Blue),
    std::make_pair(IDisplayModule::Color::magenta, sf::Color::Magenta),
    std::make_pair(IDisplayModule::Color::cyan, sf::Color::Cyan),
    std::make_pair(IDisplayModule::Color::white, sf::Color::White),
};

const std::map<IDisplayModule::Button, sf::Keyboard::Key> keyToSfmlKey = {
    std::make_pair(IDisplayModule::Button::Up, sf::Keyboard::Z),
    std::make_pair(IDisplayModule::Button::Left, sf::Keyboard::Q),
    std::make_pair(IDisplayModule::Button::Down, sf::Keyboard::S),
    std::make_pair(IDisplayModule::Button::Right, sf::Keyboard::D),

    std::make_pair(IDisplayModule::Button::X, sf::Keyboard::O),
    std::make_pair(IDisplayModule::Button::Y, sf::Keyboard::K),
    std::make_pair(IDisplayModule::Button::B, sf::Keyboard::L),
    std::make_pair(IDisplayModule::Button::A, sf::Keyboard::M),

    std::make_pair(IDisplayModule::Button::L, sf::Keyboard::A),
    std::make_pair(IDisplayModule::Button::R, sf::Keyboard::P),

    std::make_pair(IDisplayModule::Button::Start, sf::Keyboard::C),
    std::make_pair(IDisplayModule::Button::Select, sf::Keyboard::Comma),

    std::make_pair(IDisplayModule::Button::F1, sf::Keyboard::F1),
    std::make_pair(IDisplayModule::Button::F2, sf::Keyboard::F2),
    std::make_pair(IDisplayModule::Button::F3, sf::Keyboard::F3),
    std::make_pair(IDisplayModule::Button::F4, sf::Keyboard::F4),
    std::make_pair(IDisplayModule::Button::F5, sf::Keyboard::F5),
    std::make_pair(IDisplayModule::Button::F6, sf::Keyboard::F6),
    std::make_pair(IDisplayModule::Button::F7, sf::Keyboard::F7)
};