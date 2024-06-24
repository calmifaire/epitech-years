/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** CorrespNcurses
*/

#include "ArcadeNcurses.hpp"

const std::map<IDisplayModule::Button, int> keyToCursesKey = {
    std::make_pair(IDisplayModule::Button::Up, 'z'),
    std::make_pair(IDisplayModule::Button::Left, 'q'),
    std::make_pair(IDisplayModule::Button::Down, 's'),
    std::make_pair(IDisplayModule::Button::Right, 'd'),

    std::make_pair(IDisplayModule::Button::X, 'o'),
    std::make_pair(IDisplayModule::Button::Y, 'k'),
    std::make_pair(IDisplayModule::Button::B, 'l'),
    std::make_pair(IDisplayModule::Button::A, 'm'),

    std::make_pair(IDisplayModule::Button::L, 'a'),
    std::make_pair(IDisplayModule::Button::R, 'p'),

    std::make_pair(IDisplayModule::Button::Start, 'c'),
    std::make_pair(IDisplayModule::Button::Select, ','),

    std::make_pair(IDisplayModule::Button::F1, KEY_F(1)),
    std::make_pair(IDisplayModule::Button::F2, KEY_F(2)),
    std::make_pair(IDisplayModule::Button::F3, KEY_F(3)),
    std::make_pair(IDisplayModule::Button::F4, KEY_F(4)),
    std::make_pair(IDisplayModule::Button::F5, KEY_F(5)),
    std::make_pair(IDisplayModule::Button::F6, KEY_F(6)),
    std::make_pair(IDisplayModule::Button::F7, KEY_F(7))
};