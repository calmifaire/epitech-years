/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#ifndef ARCADEPACMAN_HPP_
#define ARCADEPACMAN_HPP_

#include <iostream>
#include <vector>
#include <stdlib.h> 
#include "ICore.hpp"
#include "IGameModule.hpp"

class Pacman : public IGameModule
{
public:
    Pacman();
    ~Pacman();
    void init(ICore *coreHandle);
    void update();
    void draw();
    void draw_wall();
    void draw_wall2();
    void draw_wall3();
    void draw_wall4();
    void draw_pacgum();
    void draw_corner();
    void fill_vector();
    void fill_vector_normal();
    void random_wall();
    void random_wall2();
    void random_wall3();
    void random_wall4();
    void ghost_house();
    void reset();
    void win();
    void allghost();
    void updateghost1();
    void updateghost2();
    void updateghost3();
    void updateghost4();
    void ghost_go_home(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev);
    void ghost_move(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev);
    void ghost_move_random(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev);
    void ghost_move_random2(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev);
    void ghost_flee(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev);
    bool nowallghost(int i, uint32_t x, uint32_t y);
private:
    ICore *_core;
    ICore::Texture *_pacman;
    ICore::Texture *_wallh;
    ICore::Texture *_wallv;
    ICore::Texture *_cornerleft;
    ICore::Texture *_cornerleftd;
    ICore::Texture *_cornerright;
    ICore::Texture *_cornerrightd;
    ICore::Texture *_endleft;
    ICore::Texture *_endright;
    ICore::Texture *_enddown;
    ICore::Texture *_endup;
    ICore::Texture *_door;
    ICore::Texture *_Tup;
    ICore::Texture *_Tdown;
    ICore::Texture *_Tleft;
    ICore::Texture *_Tright;
    ICore::Texture *_superpacgum;
    ICore::Texture *_pacgum;
    ICore::Texture *_ghost1;
    ICore::Texture *_ghost2;
    ICore::Texture *_ghost3;
    ICore::Texture *_ghost4;
    ICore::Texture *_ghostflee;
    ICore::Texture *_ghosteat;
    std::vector<std::pair<uint32_t,uint32_t>> _superpos;
    std::vector<int> _supervalable;
    std::vector<std::pair<uint32_t,uint32_t>> _normalpos;
    std::vector<int> _normalvalable;
    std::vector<std::pair<uint32_t,uint32_t>> _wallpos;
    std::pair <uint32_t,uint32_t> _pacpos;
    std::pair <uint32_t,uint32_t> _ghost1pos;
    std::pair <uint32_t,uint32_t> _ghost2pos;
    std::pair <uint32_t,uint32_t> _ghost3pos;
    std::pair <uint32_t,uint32_t> _ghost4pos;
    int left;
    int score;
    int highscore;
    int modesuper;
    int wait;
    int dead1;
    int dead2;
    int dead3;
    int dead4;
    uint32_t vitesse;
    std::pair <int,uint32_t> _prev1;
    std::pair <int,uint32_t> _prev2;
    std::pair <int,uint32_t> _prev3;
    std::pair <int,uint32_t> _prev4;
    std::pair <int,uint32_t> _prevpacman;
    std::string _playerName;
};

#endif /* !ARCADEPACMAN_HPP_ */
