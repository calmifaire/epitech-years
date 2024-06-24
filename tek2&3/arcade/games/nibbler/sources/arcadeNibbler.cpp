/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** nibbler
*/

#include "arcadeNibbler.hpp"

arcadeNibbler::arcadeNibbler()
{
}

arcadeNibbler::~arcadeNibbler()
{
    _core->addNewScore((uint32_t) _score);
}

void arcadeNibbler::init(ICore *corehandle) {
    srand(time(NULL));
    _core = corehandle;
    _texture = std::make_unique<textureNibbler>();
    _texture->symbol = std::make_unique<std::map<char, ICore::Texture *>>();
    _core->setPixelsPerCell(40);
    _core->setFramerate(30);
    _width = 1280;
    _height = 960;
    _core->openWindow({_width, _height});

    _texture->snake_front_up = _core->loadTexture("assets/head_up.png", 'A', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_front_left = _core->loadTexture("assets/head_left.png", '<', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_front_down = _core->loadTexture("assets/head_down.png", 'V', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_front_right = _core->loadTexture("assets/head_right.png", '>', ICore::Color::white, ICore::Color::blue, 40, 40);

    _texture->snake_body_vertical = _core->loadTexture("assets/body_vertical.png", '|', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_body_horizontal = _core->loadTexture("assets/body_horizontal.png", '-', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_body_corner_downleft = _core->loadTexture("assets/body_bottomleft.png", '/', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_body_corner_downright = _core->loadTexture("assets/body_bottomright.png", '\\', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_body_corner_upright = _core->loadTexture("assets/body_topright.png", '/', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_body_corner_upleft = _core->loadTexture("assets/body_topleft.png", '\\', ICore::Color::white, ICore::Color::blue, 40, 40);

    _texture->snake_back_down = _core->loadTexture("assets/tail_up.png", '\'', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_back_left = _core->loadTexture("assets/tail_left.png", '~', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_back_up = _core->loadTexture("assets/tail_down.png", ',', ICore::Color::white, ICore::Color::blue, 40, 40);
    _texture->snake_back_right = _core->loadTexture("assets/tail_right.png", '~', ICore::Color::white, ICore::Color::blue, 40, 40);

    _texture->wall_corner_downleft = _core->loadTexture("assets/walls_bottomleft.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_corner_downright = _core->loadTexture("assets/walls_bottomright.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_corner_upleft = _core->loadTexture("assets/walls_topleft.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_corner_upright = _core->loadTexture("assets/walls_topright.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_verticalleft = _core->loadTexture("assets/walls_verticalleft.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_horizontaldown = _core->loadTexture("assets/walls_horizontaldown.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_verticalright = _core->loadTexture("assets/walls_verticalright.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);
    _texture->wall_horizontaltop = _core->loadTexture("assets/walls_horizontaltop.png", '#', ICore::Color::white, ICore::Color::white, 40, 40);

    _texture->background_1 = _core->loadTexture("assets/grass_1.png", ' ', ICore::Color::green, ICore::Color::green, 40, 40);
    _texture->background_2 = _core->loadTexture("assets/grass_2.png", ' ', ICore::Color::yellow, ICore::Color::yellow, 40, 40);

    _texture->fruit = _core->loadTexture("assets/apple.png", 'O', ICore::Color::black, ICore::Color::red, 40, 40);

    _texture->blank = _core->loadTexture("assets/typo.ttf", ' ', ICore::Color::black, ICore::Color::black, 40, 40);

    for (int i = 0; i <= 9; i++)
        _texture->number[i] = _core->loadTexture("assets/typo.ttf", '0' + i, ICore::Color::white, ICore::Color::black, 40, 40);
    for (int i = 0; i < 27; i++)
        _texture->letter[i] = _core->loadTexture("assets/typo.ttf", 'A' + i, ICore::Color::white, ICore::Color::black, 40, 40);

    _texture->symbol->insert(std::make_pair(' ', (_core->loadTexture("assets/typo.ttf", ' ', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair(';', (_core->loadTexture("assets/typo.ttf", ';', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair(':', (_core->loadTexture("assets/typo.ttf", ':', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('?', (_core->loadTexture("assets/typo.ttf", '?', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('!', (_core->loadTexture("assets/typo.ttf", '!', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('.', (_core->loadTexture("assets/typo.ttf", '.', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('*', (_core->loadTexture("assets/typo.ttf", '*', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('\'', (_core->loadTexture("assets/typo.ttf", '\'', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('(', (_core->loadTexture("assets/typo.ttf", '(', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair(')', (_core->loadTexture("assets/typo.ttf", ')', ICore::Color::white, ICore::Color::black, 40, 40))));
    _texture->symbol->insert(std::make_pair('#', (_core->loadTexture("assets/typo.ttf", '#', ICore::Color::white, ICore::Color::black, 40, 40))));
}

int arcadeNibbler::least_common_multiple(int a, int b) {
    int count = 0;

    for (; count % a != 0 || count % b != 0; count++);
    return (count);
}

void arcadeNibbler::update() {
    switch (_phase) {
        case TUTORIEL:
            update_tutorial();
            break;
        case GAME:
            update_game();
            break;
        case OVER:
            update_over();
            break;
        }
    _tick++;
}

void arcadeNibbler::update_tutorial() {
    _score = 0;
    _end = 0;
    if (_snake.size() != 5) {
        _snake.push_front({(int)(_width / 4 + 160), (int)(_height / 2), direct::RIGHT, _texture->blank});
        _snake.push_front({(int)(_width / 4 + 120), (int)(_height / 2), direct::RIGHT, _texture->snake_front_right});
        _snake.push_front({(int)(_width / 4 + 80), (int)(_height / 2), direct::RIGHT, _texture->snake_body_horizontal});
        _snake.push_front({(int)(_width / 4 + 40), (int)(_height / 2), direct::RIGHT, _texture->snake_body_horizontal});
        _snake.push_front({(int)(_width / 4 + 0), (int)(_height / 2), direct::RIGHT ,_texture->snake_back_left});

        _fruit.push_back({(int)(_width / 2), (int)(_height / 2), _texture->fruit});
    }
    for (int i = 0; i <= 3; i++) {
        if (_core->isButtonPressed((ICore::Button)i)) {
            _phase = arcadeNibbler::PHASE::GAME;
            return;
        }
    }
}

void arcadeNibbler::update_game() {
    get_input();
    if (_tick % 10 != 0)
        return;
    if (!_end) {
        move_snake();
        put_corner();
        eat_snake();
        put_fruit();
    } else if (_end == 3)
        _phase = PHASE::OVER;
    else
        _end++;
}

void arcadeNibbler::eat_snake() {
    auto tail = _snake.at(0);

    if (_snake.at(_snake.size() - 2)._x == _fruit.at(0)._x && _snake.at(_snake.size() - 2)._y == _fruit.at(0)._y) {
        _fruit.pop_front();
        _score += 100;
        _snake.pop_front();
        _snake.push_front({tail._x, tail._y, tail.direction, tail._texture});
        _snake.push_front(tail);
    }
}

void arcadeNibbler::put_fruit() {
    int possible_x = 0;
    int possible_y = 0;

    if (_fruit.size() < 1) {
        while (1) {
            possible_x = (rand() % 32 + 4) * 40;
            possible_y = (rand() % 24 + 1) * 40;
            if (!(possible_y <= 160 || possible_y >= (int)_height - 40 || possible_x <= 0 || possible_x >= (int)_width - 40)) {
                _fruit.push_back({possible_x, possible_y, _texture->fruit});
                return;
            }
        }
    }
}

void arcadeNibbler::get_input() {
    if (_core->isButtonPressed(ICore::Button::Right))
        _actualDir = direct::RIGHT;
    if (_core->isButtonPressed(ICore::Button::Left))
        _actualDir = direct::LEFT;
    if (_core->isButtonPressed(ICore::Button::Up))
        _actualDir = direct::UP;
    if (_core->isButtonPressed(ICore::Button::Down))
        _actualDir = direct::DOWN;
}

void arcadeNibbler::move_snake() {
    long unsigned int nexto = 0;
    int right = _actualDir == direct::RIGHT && _snake.at(_snake.size() - 1).direction == direct::LEFT ? 1 : 0;
    int left = _actualDir == direct::LEFT && _snake.at(_snake.size() - 1).direction == direct::RIGHT ? 1 : 0;
    int up = _actualDir == direct::UP && _snake.at(_snake.size() - 1).direction == direct::DOWN ? 1 : 0;
    int down = _actualDir == direct::DOWN && _snake.at(_snake.size() - 1).direction == direct::UP ? 1 : 0;

    if (hitbox_check(_snake.at(_snake.size() - 1)._x, _snake.at(_snake.size() - 1)._y))
        return;
    for (long unsigned int it = 0; it < _snake.size() - 1; it++) {
        nexto = it + 1;
        _snake.at(it)._x = _snake.at(nexto)._x;
        _snake.at(it)._y = _snake.at(nexto)._y;
        _snake.at(it).direction = _snake.at(nexto).direction;
        switch (_snake.at(it).direction) {
        case direct::RIGHT:
            _snake.at(it)._texture = it == 0 ? _texture->snake_back_left : _texture->snake_body_horizontal;
            if (it == 0 && (_snake.at(nexto + 1).direction == direct::UP ||_snake.at(nexto + 1).direction == direct::DOWN)) {
                _snake.at(it).direction = _snake.at(nexto + 1).direction;
                _snake.at(it)._texture = _snake.at(nexto + 1).direction == direct::UP ? _texture->snake_back_up : _texture->snake_back_down;
            }
            break;
        case direct::LEFT:
            _snake.at(it)._texture = it == 0 ? _texture->snake_back_right : _texture->snake_body_horizontal;
            if (it == 0 && (_snake.at(nexto+ 1).direction == direct::UP ||_snake.at(nexto+1).direction == direct::DOWN)) {
                _snake.at(it).direction = _snake.at(nexto+1).direction;
                _snake.at(it)._texture = _snake.at(nexto+1).direction == direct::UP ? _texture->snake_back_up : _texture->snake_back_down;
            }
            break;
        case direct::UP:
            _snake.at(it)._texture = it == 0 ? _texture->snake_back_up : _texture->snake_body_vertical;
            if (it == 0 && (_snake.at(nexto+1).direction == direct::LEFT ||_snake.at(nexto+1).direction == direct::RIGHT)) {
                _snake.at(it).direction = _snake.at(nexto+1).direction;
                _snake.at(it)._texture = _snake.at(nexto+1).direction == direct::LEFT ? _texture->snake_back_right : _texture->snake_back_left;
            }
            break;
        case direct::DOWN:
            _snake.at(it)._texture = it == 0 ? _texture->snake_back_down : _texture->snake_body_vertical;
            if (it == 0 && (_snake.at(nexto+1).direction == direct::LEFT ||_snake.at(nexto+1).direction == direct::RIGHT)) {
                _snake.at(it).direction = _snake.at(nexto+1).direction;
                _snake.at(it)._texture = _snake.at(nexto+1).direction == direct::LEFT ? _texture->snake_back_right : _texture->snake_back_left;
            }
            break;
        }
        if (nexto == _snake.size() - 1) {
            if ((_actualDir == direct::RIGHT && _snake.at(nexto).direction != direct::LEFT) || right) {
                _snake.at(it)._x = _snake.at(nexto)._x;
                _snake.at(it)._y = _snake.at(nexto)._y;
                _snake.at(it)._texture = right ? _texture->snake_front_left : _texture->snake_front_right;
                _snake.at(nexto).direction = right ? _snake.at(nexto).direction : direct::RIGHT;
                _snake.at(nexto)._x += right ? -40 : 40;
                _snake.at(nexto)._texture = _texture->blank;
            } else if ((_actualDir == direct::LEFT && _snake.at(nexto).direction != direct::RIGHT) || left){
                _snake.at(it)._x = _snake.at(nexto)._x;
                _snake.at(it)._y = _snake.at(nexto)._y;
                _snake.at(it)._texture = left ? _texture->snake_front_right : _texture->snake_front_left;
                _snake.at(nexto).direction = left ? _snake.at(nexto).direction : direct::LEFT;
                _snake.at(nexto)._x -= left ? -40 : 40;
                _snake.at(nexto)._texture = _texture->blank;
            } else if ((_actualDir == direct::UP && _snake.at(nexto).direction != direct::DOWN) || up) {
                _snake.at(it)._x = _snake.at(nexto)._x;
                _snake.at(it)._y = _snake.at(nexto)._y;
                _snake.at(it)._texture = up ? _texture->snake_front_down : _texture->snake_front_up;
                _snake.at(nexto).direction = up ? _snake.at(nexto).direction : direct::UP;
                _snake.at(nexto)._y -= up ? -40 : 40;
                _snake.at(nexto)._texture = _texture->blank;
            } else if ((_actualDir == direct::DOWN && _snake.at(nexto).direction != direct::UP) || down) {
                _snake.at(it)._x = _snake.at(nexto)._x;
                _snake.at(it)._y = _snake.at(nexto)._y;
                _snake.at(it)._texture = down ? _texture->snake_front_up :_texture->snake_front_down;
                _snake.at(nexto).direction =  down ? _snake.at(nexto).direction : direct::DOWN;
                _snake.at(nexto)._y += down ? -40 : 40;
                _snake.at(nexto)._texture = _texture->blank;
            }
        }
    }
}

void arcadeNibbler::put_corner() {
    for (long unsigned int i = 1; i < _snake.size() - 1; i++) {
        if (i < _snake.size() - 2) {
            if ((_snake.at(i).direction == direct::UP && _snake.at(i + 1).direction == direct::LEFT)
            || (_snake.at(i).direction == direct::RIGHT && _snake.at(i + 1).direction == direct::DOWN))
                _snake.at(i)._texture = _texture->snake_body_corner_downleft;
            if ((_snake.at(i).direction == direct::UP && _snake.at(i + 1).direction == direct::RIGHT)
            || (_snake.at(i).direction == direct::LEFT && _snake.at(i + 1).direction == direct::DOWN))
                _snake.at(i)._texture = _texture->snake_body_corner_downright;
            if ((_snake.at(i).direction == direct::DOWN && _snake.at(i + 1).direction == direct::LEFT)
            || (_snake.at(i).direction == direct::RIGHT && _snake.at(i + 1).direction == direct::UP))
                _snake.at(i)._texture = _texture->snake_body_corner_upleft;
            if ((_snake.at(i).direction == direct::DOWN && _snake.at(i + 1).direction == direct::RIGHT)
            || (_snake.at(i).direction == direct::LEFT && _snake.at(i + 1).direction == direct::UP))
                _snake.at(i)._texture = _texture->snake_body_corner_upright;
            continue;
        }
        switch (_snake.at(i - 1).direction) {
        case direct::RIGHT:
            _snake.at(i)._texture = _snake.at(i).direction != direct::RIGHT ? _snake.at(i)._texture : _texture->snake_front_right;
            break;
        case direct::LEFT:
            _snake.at(i)._texture = _snake.at(i).direction != direct::LEFT ? _snake.at(i)._texture : _texture->snake_front_left;
            break;
        case direct::UP:
            _snake.at(i)._texture = _snake.at(i).direction != direct::UP ? _snake.at(i)._texture : _texture->snake_front_up;
            break;
        case direct::DOWN:
            _snake.at(i)._texture = _snake.at(i).direction != direct::DOWN ? _snake.at(i)._texture : _texture->snake_front_down;
            break;
        }
    }
}


bool arcadeNibbler::hitbox_check(int x, int y) {
    if (is_hitting_snake(x, y) || is_hitting_wall(x, y)) {
        _end++;
        return (true);
    }
    return (false);
}

bool arcadeNibbler::is_hitting_snake(int x, int y) {
    for (long unsigned int i = 1; i < _snake.size() - 1; i++) {
        if (_snake.at(i)._x == x && _snake.at(i)._y == y)
            return (true);
    }
    return (false);
}

bool arcadeNibbler::is_hitting_wall(int x, int y) {
    if (y <= 160 || y >= (int)_height - 40 || x <= 0 || x >= (int)_width - 40) {
        return (true);
    }
    return (false);
}

void arcadeNibbler::update_over() {
    if (_snake.size() != 0)
        _fruit.pop_back();
    while (_snake.size() > 0)
        _snake.pop_front();
    if (_core->isButtonPressed(ICore::Button::Start)) {
        _phase = arcadeNibbler::PHASE::TUTORIEL;
        return;
    }
}


void arcadeNibbler::draw_tutorial() {
    _core->clearScreen(ICore::Color::black);
    print_string("PLAYER1", {0, 0});
    print_string("  0", {(_width / 2)  - (6 * 40), 0});
    print_string("HIGHSCORE", {0, 80});
    print_string("  5000", {(_width / 2) - (6 * 40), 80});
    print_string("INSTRUCTIONS:", {(_width / 2) - ((14 / 2) * 40), 240});
    print_string("TRY TO SURVIVE AS", {(_width / 2) - ((18 / 2) * 40), 280});
    print_string("LONG AS POSSIBLE!", {(_width / 2) - ((18 / 2) * 40), 320});
    print_string("EAT FRUITS TO GET", {(_width / 2) - ((18 / 2) * 40), 400});
    print_string("BIGGER BUT DO NOT", {(_width / 2) - ((18 / 2) * 40), 440});
    print_string("GET BLOCKED !", {(_width / 2) - ((14 / 2) * 40), 480});
    print_string("USE ZQSD TO MOVE", {(_width / 2) - ((17 / 2) * 40), 560});
    print_string("PRESS ANY MOVEMENT", {(_width / 2) - ((19 / 2) * 40), 600});
    print_string("TO START :)", {(_width / 2) - ((12 / 2) * 40), 640});
}

void arcadeNibbler::draw_game() {
    std::stringstream tmp;
    std::string score;
    tmp << _score;
    tmp >> score;
    _core->clearScreen(ICore::Color::black);
    print_string("PLAYER1", {0, 0});
    print_string("  " + score, {(_width / 2) - (6 * 40), 0});
    print_string("HIGHSCORE", {0, 80});
    print_string("  " + (_score > 5000 ? score : "5000"), {(_width / 2) - ((6 * 40)), 80});
    print_ground();
    print_wall();
    if (!(_tick % 10 == 0 && _end))
        print_element();
}

void arcadeNibbler::print_ground() {
    int count = 0;

    for (uint32_t i = 160; i < _height; i += 40) {
        for (uint32_t j = 0; j < _width; j += 40) {
            if (count % 2)
                _core->renderSprite({{j, i}, _texture->background_1});
            else
                _core->renderSprite({{j, i}, _texture->background_2});
            count++;
        }
        count = i % 80 ? 0 : 1;
    }
}

void arcadeNibbler::print_wall() {
    for (u_int32_t i = 0; i < _width; i += 40) {
        _core->renderSprite({{(uint32_t)i, 160}, _texture->wall_horizontaltop});
        _core->renderSprite({{(uint32_t)i, _height - 40}, _texture->wall_horizontaldown});
    }
    for (u_int32_t i = 160; i < _height; i += 40) {
        _core->renderSprite({{0, (uint32_t)i}, _texture->wall_verticalleft});
        _core->renderSprite({{_width - 40, (uint32_t)i}, _texture->wall_verticalright});
    }
    _core->renderSprite({{0, 160}, _texture->wall_corner_upleft});
    _core->renderSprite({{_width - 40, 160}, _texture->wall_corner_upright});
    _core->renderSprite({{0, _height - 40}, _texture->wall_corner_downleft});
    _core->renderSprite({{_width - 40, _height - 40}, _texture->wall_corner_downright});
}

void arcadeNibbler::print_element() {
    for (auto &it : _snake) {
        if (it._texture != _texture->blank)
            _core->renderSprite({{(uint32_t)it._x, (uint32_t)it._y,}, it._texture});
    }
    for (auto &it : _fruit)
        _core->renderSprite({{(uint32_t)it._x, (uint32_t)it._y,}, it._texture});
}

void arcadeNibbler::draw_over() {
    _core->clearScreen(ICore::Color::black);
    std::stringstream tmp;
    std::string score;
    tmp << _score;
    tmp >> score;
    _core->clearScreen(ICore::Color::black);
    print_string("YOU LOSE !", {(_width / 2) - ((11 / 2) * 40), 240});
    print_string("PLAYER1 :", {(_width / 2) - ((14 / 2) * 40), 320});
    print_string("  " + score, {(_width / 2) + (3 * 40), 320});
    print_string("PRESS C", {(_width / 2) - ((8 / 2) * 40), 640});
    print_string("TO TRY AGAIN", {(_width / 2) - (13 / 2) * 40, 680});
}

std::unique_ptr<IGameModule> gEpitechArcadeGetGameModuleHandle(void) {
    return (std::make_unique<arcadeNibbler>());
}
void arcadeNibbler::draw() {
    switch (_phase) {
        case TUTORIEL:
            draw_tutorial();
            break;
        case GAME:
            draw_game();
            break;
        case OVER:
            draw_over();
            break;
        }
}

void arcadeNibbler::print_string(std::string str, IDisplayModule::Vector2u pos) {
    for (std::size_t i = 0; i < str.length(); i ++) {
        if (std::isdigit(str[i]) != 0)
            _core->renderSprite({{pos.x + 40, pos.y}, _texture->number[str[i] - '0']});
        else if (std::isalpha(str[i]) != 0)
            _core->renderSprite({{pos.x + 40, pos.y}, _texture->letter[str[i] - 'A']});
        else {
            auto it = _texture->symbol->find(str[i]);
            _core->renderSprite({{pos.x + 40, pos.y}, it->second});
        }
        pos.x += 40;
    }
}