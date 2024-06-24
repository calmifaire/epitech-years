/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** nibbler
*/

#ifndef ARCADENIBBLER_HPP_
#define ARCADENIBBLER_HPP_

#include <iostream>
#include <deque>
#include <map>
#include <sstream>
#include "IGameModule.hpp"

typedef struct textureNibbler_s {
    ICore::Texture *snake_front_up;
    ICore::Texture *snake_front_down;
    ICore::Texture *snake_front_left;
    ICore::Texture *snake_front_right;

    ICore::Texture *snake_body_vertical;
    ICore::Texture *snake_body_horizontal;
    ICore::Texture *snake_body_corner_upright;
    ICore::Texture *snake_body_corner_upleft;
    ICore::Texture *snake_body_corner_downleft;
    ICore::Texture *snake_body_corner_downright;

    ICore::Texture *snake_back_up;
    ICore::Texture *snake_back_down;
    ICore::Texture *snake_back_left;
    ICore::Texture *snake_back_right;

    ICore::Texture *wall_verticalleft;
    ICore::Texture *wall_horizontaldown;
    ICore::Texture *wall_verticalright;
    ICore::Texture *wall_horizontaltop;
    ICore::Texture *wall_corner_upright;
    ICore::Texture *wall_corner_downright;
    ICore::Texture *wall_corner_upleft;
    ICore::Texture *wall_corner_downleft;

    ICore::Texture *background_1;
    ICore::Texture *background_2;

    ICore::Texture *fruit;
    ICore::Texture *blank;

    ICore::Texture *number[10];
    ICore::Texture *letter[27];
    std::unique_ptr<std::map<char, ICore::Texture*>> symbol;
} textureNibbler;

enum direct {
        UP,
        DOWN,
        LEFT,
        RIGHT
};

typedef struct snakeCell_s {
    int _x;
    int _y;
    direct direction;
    ICore::Texture *_texture;
} snakeCell;

typedef struct snakeFruit_s {
    int _x;
    int _y;
    ICore::Texture *_texture;
} snakeFruit;

class arcadeNibbler : public IGameModule {
    enum PHASE {
        TUTORIEL,
        GAME,
        OVER
    };
    public:
        arcadeNibbler();
        ~arcadeNibbler();
        void init(ICore *coreHandle);
        void update();
        void update_tutorial();
        void update_game();
        void update_over();
        void draw();
        void draw_tutorial();
        void draw_game();
        void draw_over();
        void get_input();
        void checkPressedButton();
        void move_snake();
        void eat_snake();
        void put_corner();
        bool hitbox_check(int x, int y);
        bool is_hitting_snake(int x, int y);
        bool is_hitting_wall(int x, int y);
        void print_ground();
        void print_string(std::string str, IDisplayModule::Vector2u pos);
        void print_wall();
        void print_element();
        int least_common_multiple(int a, int b);
        void put_fruit();
    protected:
        ICore *_core;
        std::unique_ptr<textureNibbler>_texture;
        int _tick = 0;
        uint32_t _width;
        uint32_t _height;
        std::deque<snakeCell> _snake;
        std::deque<snakeFruit> _fruit;
        PHASE _phase = PHASE::TUTORIEL;
        int _score = 0;
        int _end = 0;
        direct _actualDir = direct::RIGHT;
    private:
};

#endif /* !ARCADENIBBLER_HPP_ */
