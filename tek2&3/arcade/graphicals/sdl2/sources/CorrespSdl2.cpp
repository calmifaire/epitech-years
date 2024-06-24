/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** CorrespNcurses
*/

#include "ArcadeSdl2.hpp"

const std::vector<std::tuple<uint8_t, uint8_t, uint8_t>> colorToSdl2Color = {
    {0,0,0},
    {255,0,0},
    {0,255,128},
    {255,255,0},
    {0,0,255},
    {255,0,255},
    {0,255,255},
    {255,255,255},
};

const std::unordered_map<IDisplayModule::Button, SDL_Scancode> keystoSdl2keys = {
    std::make_pair(IDisplayModule::Button::Up, SDL_SCANCODE_W),
    std::make_pair(IDisplayModule::Button::Left, SDL_SCANCODE_A),
    std::make_pair(IDisplayModule::Button::Down, SDL_SCANCODE_S),
    std::make_pair(IDisplayModule::Button::Right, SDL_SCANCODE_D),

    std::make_pair(IDisplayModule::Button::X, SDL_SCANCODE_O),
    std::make_pair(IDisplayModule::Button::Y, SDL_SCANCODE_K),
    std::make_pair(IDisplayModule::Button::B, SDL_SCANCODE_L),
    std::make_pair(IDisplayModule::Button::A, SDL_SCANCODE_SEMICOLON),

    std::make_pair(IDisplayModule::Button::L, SDL_SCANCODE_Q),
    std::make_pair(IDisplayModule::Button::R, SDL_SCANCODE_P),

    std::make_pair(IDisplayModule::Button::Start, SDL_SCANCODE_C),
    std::make_pair(IDisplayModule::Button::Select, SDL_SCANCODE_M),

    std::make_pair(IDisplayModule::Button::F1, SDL_SCANCODE_F1),
    std::make_pair(IDisplayModule::Button::F2, SDL_SCANCODE_F2),
    std::make_pair(IDisplayModule::Button::F3, SDL_SCANCODE_F3),
    std::make_pair(IDisplayModule::Button::F4, SDL_SCANCODE_F4),
    std::make_pair(IDisplayModule::Button::F5, SDL_SCANCODE_F5),
    std::make_pair(IDisplayModule::Button::F6, SDL_SCANCODE_F6),
    std::make_pair(IDisplayModule::Button::F7, SDL_SCANCODE_F7),
};