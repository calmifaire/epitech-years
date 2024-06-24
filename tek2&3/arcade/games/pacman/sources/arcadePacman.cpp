/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#include "arcadePacman.hpp"

Pacman::Pacman()
{

}

Pacman::~Pacman()
{
    _core->addNewScore((uint32_t) highscore);
}

void Pacman::init(ICore *coreHandle)
{
    _core = coreHandle;
    _core->setPixelsPerCell(16);
    _core->setFramerate(30);
    _core->openWindow({800, 600});
    _pacpos.first = 400;
    _pacpos.second = 336;
    _ghost1pos.first = 16*25;
    _ghost1pos.second = 16*17;
    _ghost2pos.first = 16*25;
    _ghost2pos.second = 16*18;
    _ghost3pos.first = 16*24;
    _ghost3pos.second = 16*18;
    _ghost4pos.first = 16*26;
    _ghost4pos.second = 16*18;
    this->_pacman = coreHandle->loadTexture("./games/pacman/texture/pacman.png",'0',IDisplayModule::Color::yellow, IDisplayModule::Color::yellow, 8, 8);
    this->_wallv = coreHandle->loadTexture("./games/pacman/texture/wallverti.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_wallh = coreHandle->loadTexture("./games/pacman/texture/wallhori.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_cornerleft = coreHandle->loadTexture("./games/pacman/texture/wallleftcorner.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_cornerright = coreHandle->loadTexture("./games/pacman/texture/wallrightcorner.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_cornerleftd = coreHandle->loadTexture("./games/pacman/texture/cornerleftd.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_cornerrightd = coreHandle->loadTexture("./games/pacman/texture/rightdcorner.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_endleft = coreHandle->loadTexture("./games/pacman/texture/endleft.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_endright = coreHandle->loadTexture("./games/pacman/texture/endright.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_enddown = coreHandle->loadTexture("./games/pacman/texture/enddown.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_endup = coreHandle->loadTexture("./games/pacman/texture/endup.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_door = coreHandle->loadTexture("./games/pacman/texture/door.png",'Z',IDisplayModule::Color::red, IDisplayModule::Color::red, 16, 16);
    this->_Tup = coreHandle->loadTexture("./games/pacman/texture/Tup.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_Tdown = coreHandle->loadTexture("./games/pacman/texture/Tdown.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_Tleft = coreHandle->loadTexture("./games/pacman/texture/Tleft.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_Tright = coreHandle->loadTexture("./games/pacman/texture/Tright.png",'Z',IDisplayModule::Color::blue, IDisplayModule::Color::blue, 16, 16);
    this->_superpacgum = coreHandle->loadTexture("./games/pacman/texture/superpacgum.png",'0',IDisplayModule::Color::white, IDisplayModule::Color::black, 16, 16);
    this->_pacgum = coreHandle->loadTexture("./games/pacman/texture/pacgum.png",'o',IDisplayModule::Color::white, IDisplayModule::Color::black, 16, 16);
    this->_ghost1 = coreHandle->loadTexture("./games/pacman/texture/ghost1.png",'"',IDisplayModule::Color::white, IDisplayModule::Color::cyan, 8, 8);
    this->_ghost2 = coreHandle->loadTexture("./games/pacman/texture/ghost2.png",'"',IDisplayModule::Color::white, IDisplayModule::Color::yellow, 8, 8);
    this->_ghost3 = coreHandle->loadTexture("./games/pacman/texture/ghost3.png",'"',IDisplayModule::Color::white, IDisplayModule::Color::red, 8, 8);
    this->_ghost4 = coreHandle->loadTexture("./games/pacman/texture/ghost4.png",'"',IDisplayModule::Color::white, IDisplayModule::Color::magenta, 8, 8);
    this->_ghostflee = coreHandle->loadTexture("./games/pacman/texture/ghostflee.png",'"',IDisplayModule::Color::black, IDisplayModule::Color::blue, 8, 8);
    this->_ghosteat = coreHandle->loadTexture("./games/pacman/texture/onlyeye.png",'"',IDisplayModule::Color::white, IDisplayModule::Color::black, 8, 8);
    fill_vector();
    _superpos.push_back(std::make_pair(16*12,16*7));
    _superpos.push_back(std::make_pair(16*39,16*7));
    _superpos.push_back(std::make_pair(16*11,16*29));
    _superpos.push_back(std::make_pair(16*39,16*29));
    for (int i = 0; i != 4; i++)
        _supervalable.push_back(1);
    fill_vector_normal();
    vitesse = 4;
    score = 0;
    highscore = 0;
    wait = 300;
    modesuper = 0;
    dead1 = 0;
    dead2 = 0;
    dead3 = 0;
    dead4 = 0;
    _prev1.first = 0;
    _prev1.second = 16;
    _prev2.first = 0;
    _prev2.second = 16;
    _prev3.first = 0;
    _prev3.second = 16;
    _prev4.first = 0;
    _prev4.second = 16;
    _prevpacman.first = 0;
    _prevpacman.second = 16;
}

std::unique_ptr<IGameModule> gEpitechArcadeGetGameModuleHandle(void)
{
    return (std::make_unique<Pacman>());
}

bool Pacman::nowallghost(int i, uint32_t x, uint32_t y)
{
    for (auto it = _wallpos.begin(); it != _wallpos.end(); it++){
        if (i == 1 && y == it->second)
            if (x - 16 == it->first){
                return (false);
            }
        if (i == 2 && y == it->second)
            if (x + 16 == it->first){
                return (false);
            }
        if (i == 3 && x == it->first)
            if (y - 16 == it->second){
                return (false);
            }
        if (i == 4 && x == it->first)
            if (y + 16 == it->second){
                return (false);
            }
    }
    return (true);
}

void Pacman::win()
{
    for (auto it = _normalvalable.begin(); it != _normalvalable.end(); it++)
        *it = 1;
    for (auto it = _supervalable.begin(); it != _supervalable.end(); it++)
        *it = 1;
    _pacpos.first = 400;
    _pacpos.second = 336;
    _ghost1pos.first = 16*25;
    _ghost1pos.second = 16*17;
    _ghost2pos.first = 16*25;
    _ghost2pos.second = 16*18;
    _ghost3pos.first = 16*24;
    _ghost3pos.second = 16*18;
    _ghost4pos.first = 16*26;
    _ghost4pos.second = 16*18;
    if (vitesse != 16)
        vitesse = vitesse * 2;
    score = score + 1000;
    wait = 300 - 30;
    modesuper = 0;
    _prevpacman.first = 0;
    _prevpacman.second = 16;
    _prev1.first = 0;
    _prev1.second = 16;
    _prev2.first = 0;
    _prev2.second = 16;
    _prev3.first = 0;
    _prev3.second = 16;
    _prev4.first = 0;
    _prev4.second = 16;
}

void Pacman::reset()
{
    for (auto it = _normalvalable.begin(); it != _normalvalable.end(); it++)
        *it = 1;
    for (auto it = _supervalable.begin(); it != _supervalable.end(); it++)
        *it = 1;
    _pacpos.first = 400;
    _pacpos.second = 336;
    _ghost1pos.first = 16*25;
    _ghost1pos.second = 16*17;
    _ghost2pos.first = 16*25;
    _ghost2pos.second = 16*18;
    _ghost3pos.first = 16*24;
    _ghost3pos.second = 16*18;
    _ghost4pos.first = 16*26;
    _ghost4pos.second = 16*18;
    vitesse = 4;
    if (score > highscore)
        highscore = score;   
    score = 0;
    wait = 300;
    modesuper = 0;
    _prevpacman.first = 0;
    _prevpacman.second = 16;
    _prev1.first = 0;
    _prev1.second = 16;
    _prev2.first = 0;
    _prev2.second = 16;
    _prev3.first = 0;
    _prev3.second = 16;
    _prev4.first = 0;
    _prev4.second = 16;
}

void Pacman::ghost_move_random(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev)
{
    if (prev->first != 0 && nowallghost(prev->first, x, y) == true)
        prev->second = 0;
    else{
        while (nowallghost(prev->first, x, y) == false)
            prev->first = rand() % 4 + 1;
        prev->second = 0;
    }
}

void Pacman::ghost_move_random2(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev)
{
	int move = rand() % 4 + 1;
	while (nowallghost(move, x, y) == false)
        move = rand() % 4 + 1;
    if (move == 1 && prev->first == 2)
        ghost_move_random2(x,y,prev);
    else if (move == 2 && prev->first == 1)
        ghost_move_random2(x,y,prev);
    else if (move == 3 && prev->first == 4)
        ghost_move_random2(x,y,prev);
    else if (move == 4 && prev->first == 3)
        ghost_move_random2(x,y,prev);
    else
        prev->first = move;
    prev->second = 0;
}

void Pacman::ghost_move(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev)
{
    if (_pacpos.first < x && x - vitesse - _pacpos.first < x - _pacpos.first && nowallghost(1, x, y) == true){
        prev->first = 1;
        prev->second = 0;
    }
    else if (x < _pacpos.first && _pacpos.first - (x + vitesse) < _pacpos.first - x && nowallghost(2, x, y) == true){
        prev->first = 2;
        prev->second = 0;
    }
    else if (_pacpos.second < y && y - vitesse - _pacpos.second <=y - _pacpos.second && nowallghost(3, x, y) == true){
        prev->first = 3;
        prev->second = 0;
    }
    else if (y < _pacpos.second && _pacpos.second - (y + vitesse) < _pacpos.second - y && nowallghost(4, x, y) == true){
        prev->first = 4;
        prev->second = 0;
    }
    else if(nowallghost(prev->first, x, y) == true){
        prev->first = prev->first;
        prev->second = 0;
    }else{
        if(nowallghost(3, x, y) == true){
            prev->first = 3;
            prev->second = 0;
        }
        else if(nowallghost(1, x, y) == true){
            prev->first = 1;
            prev->second = 0;
        }
        else if(nowallghost(2, x, y) == true){
            prev->first = 2;
            prev->second = 0;
        }
        else if(nowallghost(4, x, y) == true){
            prev->first = 4;
            prev->second = 0;
        }
    }
}

void Pacman::ghost_flee(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev)
{
    if (_pacpos.first < x && x - vitesse - _pacpos.first >= x - _pacpos.first && nowallghost(1, x, y) == true){
        prev->first = 1;
        prev->second = 0;
    }
    else if (x < _pacpos.first && _pacpos.first - (x + vitesse) >= _pacpos.first - x && nowallghost(2, x, y) == true){
        prev->first = 2;
        prev->second = 0;
    }
    else if (_pacpos.second < y && y - vitesse - _pacpos.second >= y - _pacpos.second && nowallghost(3, x, y) == true){
        prev->first = 3;
        prev->second = 0;
    }
    else if (y < _pacpos.second && _pacpos.second - (y + vitesse) >= _pacpos.second - y && nowallghost(4, x, y) == true){
        prev->first = 4;
        prev->second = 0;
    }
    else if (_pacpos.first == x){
        if (nowallghost(1, x, y) == true)
            prev->first = 1;
        if (nowallghost(2, x, y) == true)
            prev->first = 2;
        prev->second = 0;
    }
    else if (_pacpos.second == y){
        if (nowallghost(3, x, y) == true)
            prev->first = 3;
        if (nowallghost(4, x, y) == true)
            prev->first = 4;
        prev->second = 0;
    }
    else if (x < _pacpos.first && _pacpos.first - (x + vitesse) >= _pacpos.first - x && nowallghost(2, x, y) == true){
        prev->first = 2;
        prev->second = 0;
    }
    else if (_pacpos.second < y && y - vitesse - _pacpos.second >= y - _pacpos.second && nowallghost(3, x, y) == true){
        prev->first = 3;
        prev->second = 0;
    }
    else if (y < _pacpos.second && _pacpos.second - (y + vitesse) >= _pacpos.second - y && nowallghost(4, x, y) == true){
        prev->first = 4;
        prev->second = 0;
    }
    else if(nowallghost(prev->first, x, y) == true){
        prev->first = prev->first;
        prev->second = 0;
    }
}

void Pacman::ghost_go_home(uint32_t x, uint32_t y, std::pair<int, uint32_t> *prev)
{
    if (x < 16*21 && y < 16*29 && nowallghost(4, x, y) == true){
        prev->first = 4;
        prev->second = 0;
    }
    else if (x <= 16*21 && y < 16*29 && nowallghost(4, x, y) == false){
        if (nowallghost(1, x, y) == true)
            prev->first = 1;
        else if (nowallghost(2, x, y) == true)
            prev->first = 2;
        prev->second = 0;
    }
    else if (x < 16*21 && y == 16*29 && nowallghost(2, x, y) == true){
        prev->first = 2;
        prev->second = 0;
    }
    else if (x == 16*21 && y > 16*14 && nowallghost(3, x, y) == true){
        prev->first = 3;
        prev->second = 0;
    }
    else if (x >= 16*18 && x <= 16*24 && y < 16*14){
        if (nowallghost(4, x, y) == true)
            prev->first = 4;
        else if (nowallghost(2, x, y) == true)
            prev->first = 2;
        prev->second = 0;
    }
	
    else if (x == 16*29 && y == 16*12){
        prev->first = 4;
        prev->second = 0;
    }
    else if (x > 16*29 && y > 16*7 && nowallghost(3, x, y) == true){
        prev->first = 3;
        prev->second = 0;
    }
    else if ((x > 16*32 && x < 16*38 && y == 16*21) || (x > 16*30 && x < 16*35 && y == 16*12)){
        prev->first = 2;
        prev->second = 0;
    }
    else if (x >= 16*29 && y > 16*7 && nowallghost(3, x, y) == false){
        if (nowallghost(1, x, y) == true)
            prev->first = 1;
        else if (nowallghost(2, x, y) == true)
            prev->first = 2;
        prev->second = 0;
    }
    else if (x > 16*25 && y == 16*7 && nowallghost(1, x, y) == true){
        prev->first = 1;
        prev->second = 0;
    }
    else if (x <= 16*29 && x >= 16*25 && y < 16*14){
        if (nowallghost(4, x, y) == true)
            prev->first = 4;
        else if (nowallghost(2, x, y) == true)
            prev->first = 2;
        prev->second = 0;
    }
    else if (x <= 16*29 && x >= 16*21 && y > 16*14){
        if (nowallghost(3, x, y) == true)
            prev->first = 3;
        else if (nowallghost(1, x, y) == true)
            prev->first = 1;
        prev->second = 0;
    }
}

void Pacman::updateghost4()
{
    if (_ghost4pos.first == 16*26 && _ghost4pos.second == 16*18){
        dead4 = 2;
    }
    if (modesuper == 0 && dead4 == 2){
        dead4 = 0;
    }
    if (wait <= 0){
        if (_prev4.second != 16)
        {
            if (_prev4.first == 1){
                if (modesuper == 0){
                    if (_ghost4pos.first + vitesse >= 16*10 && _ghost4pos.second < 16*19 && _ghost4pos.second > 16*17)
                        _ghost4pos.first = 16*40;
                    else
                        _ghost4pos.first = _ghost4pos.first - vitesse;
                    _prev4.second = _prev4.second + vitesse;
                }else if (dead4 == 1){
                    if (vitesse != 16){
                        _prev4.second = _prev4.second + vitesse*2;
                        _ghost4pos.first = _ghost4pos.first - vitesse*2;
                    }else{
                        _prev4.second = _prev4.second + vitesse;
                        _ghost4pos.first = _ghost4pos.first - vitesse;
                    }
                }else{
                    if (_ghost4pos.first + vitesse >= 16*10 && _ghost4pos.second < 16*19 && _ghost4pos.second > 16*17)
                        _ghost4pos.first = 16*40;
                    else
                        _ghost4pos.first = _ghost4pos.first - vitesse/2;
                    _prev4.second = _prev4.second + vitesse/2;
                }
            }
            if (_prev4.first == 2){
                if (modesuper == 0){
                    if (_ghost4pos.first + vitesse >= 16*40 && _ghost4pos.second < 16*19 && _ghost4pos.second > 16*17)
                        _ghost4pos.first = 16*10;
                    else
                        _ghost4pos.first = _ghost4pos.first + vitesse;
                    _prev4.second = _prev4.second + vitesse;
                }else if (dead4 == 1){
                    if (vitesse != 16){
                        _prev4.second = _prev4.second + vitesse*2;
                        _ghost4pos.first = _ghost4pos.first + vitesse*2;
                    }else{
                        _prev4.second = _prev4.second + vitesse;
                        _ghost4pos.first = _ghost4pos.first + vitesse;
                    }
                }else{
                    if (_ghost4pos.first + vitesse >= 16*40 && _ghost4pos.second < 16*19 && _ghost4pos.second > 16*17)
                        _ghost4pos.first = 16*10;
                    else
                        _ghost4pos.first = _ghost4pos.first + vitesse/2;
                    _prev4.second = _prev4.second + vitesse/2;
                }
            }
            if (_prev4.first == 3){
                if (modesuper == 0){
                    _prev4.second = _prev4.second + vitesse;
                    _ghost4pos.second = _ghost4pos.second - vitesse;
                }else if (dead4 == 1){
                    if (vitesse != 16){
                        _prev4.second = _prev4.second + vitesse*2;
                        _ghost4pos.second = _ghost4pos.second - vitesse*2;
                    }else{
                        _prev4.second = _prev4.second + vitesse;
                        _ghost4pos.second = _ghost4pos.second - vitesse;
                    }
                }else{
                    _prev4.second = _prev4.second + vitesse/2;
                    _ghost4pos.second = _ghost4pos.second - vitesse/2;
                }
            }
            if (_prev4.first == 4){
                if (modesuper == 0){
                    _prev4.second = _prev4.second + vitesse;
                    _ghost4pos.second = _ghost4pos.second + vitesse;
                }else if (dead4 == 1){
                    if (vitesse != 16){
                        _prev4.second = _prev4.second + vitesse*2;
                        _ghost4pos.second = _ghost4pos.second + vitesse*2;
                    }else{
                        _prev4.second = _prev4.second + vitesse;
                        _ghost4pos.second = _ghost4pos.second + vitesse;
                    }
                }else{
                    _prev4.second = _prev4.second + vitesse/2;
                    _ghost4pos.second = _ghost4pos.second + vitesse/2;
                }
            }
        }
        else if (modesuper == 0 && dead4 == 0){
            if (_ghost4pos.first > 16*22 && _ghost4pos.first < 16*28 && _ghost4pos.second > 16*14 && _ghost4pos.second < 16*20){
                _ghost4pos.second = _ghost4pos.second - vitesse;
                _prev4.second = vitesse;
                _prev4.first = 3;
            }else{
                ghost_move_random2(_ghost4pos.first, _ghost4pos.second, &_prev4);
            }
        }else if (modesuper != 0 && dead4 == 0){
            ghost_flee(_ghost4pos.first, _ghost4pos.second, &_prev4);
        }else if (dead4 == 1 && _prev4.second == 16){
            if ((_ghost4pos.first >= 16*21 && _ghost4pos.first <= 16*29 && _ghost4pos.second == 16*14) || (_ghost4pos.first == 16*26 && _ghost4pos.second <= 16*17 && _ghost4pos.second >= 16*14)){
                if (_ghost4pos.first > 16*26)
                    _prev4.first = 1;
                else if (_ghost4pos.first < 16*26)
                    _prev4.first = 2;
                else if (_ghost4pos.first == 16*26)
                    _prev4.first = 4;
                _prev4.second = 0;
            }
            else
                ghost_go_home(_ghost4pos.first, _ghost4pos.second, &_prev4);
        }
    }
}

void Pacman::updateghost3()
{
    if (_ghost3pos.first == 16*24 && _ghost3pos.second == 16*18){
        dead3 = 2;
    }
    if (modesuper == 0 && dead3 == 2){
        dead3 = 0;
    }
    if (wait <= 0){
        if (_prev3.second != 16)
        {
            if (_prev3.first == 1){
                if (modesuper == 0){
                    if (_ghost3pos.first + vitesse >= 16*10 && _ghost3pos.second < 16*19 && _ghost3pos.second > 16*17)
                        _ghost3pos.first = 16*40;
                    else
                        _ghost3pos.first = _ghost3pos.first - vitesse;
                    _prev3.second = _prev3.second + vitesse;
                }else if (dead3 == 1){
                    if (vitesse != 16){
                        _prev3.second = _prev3.second + vitesse*2;
                        _ghost3pos.first = _ghost3pos.first - vitesse*2;
                    }else{
                        _prev3.second = _prev3.second + vitesse;
                        _ghost3pos.first = _ghost3pos.first - vitesse;
                    }
                }else{
                    if (_ghost3pos.first + vitesse >= 16*10 && _ghost3pos.second < 16*19 && _ghost3pos.second > 16*17)
                        _ghost3pos.first = 16*40;
                    else
                        _ghost3pos.first = _ghost3pos.first - vitesse/2;
                    _prev3.second = _prev3.second + vitesse/2;
                }
            }
            if (_prev3.first == 2){
                if (modesuper == 0){
                    if (_ghost3pos.first + vitesse >= 16*40 && _ghost3pos.second < 16*19 && _ghost3pos.second > 16*17)
                        _ghost3pos.first = 16*10;
                    else
                        _ghost3pos.first = _ghost3pos.first + vitesse;
                    _prev3.second = _prev3.second + vitesse;
                }else if (dead3 == 1){
                    if (vitesse != 16){
                        _prev3.second = _prev3.second + vitesse*2;
                        _ghost3pos.first = _ghost3pos.first + vitesse*2;
                    }else{
                        _prev3.second = _prev3.second + vitesse;
                        _ghost3pos.first = _ghost3pos.first + vitesse;
                    }
                }else{
                    if (_ghost3pos.first + vitesse >= 16*40 && _ghost3pos.second < 16*19 && _ghost3pos.second > 16*17)
                        _ghost3pos.first = 16*10;
                    else
                        _ghost3pos.first = _ghost3pos.first + vitesse/2;
                    _prev3.second = _prev3.second + vitesse/2;
                }
            }
            if (_prev3.first == 3){
                if (modesuper == 0){
                    _prev3.second = _prev3.second + vitesse;
                    _ghost3pos.second = _ghost3pos.second - vitesse;
                }else if (dead3 == 1){
                    if (vitesse != 16){
                        _prev3.second = _prev3.second + vitesse*2;
                        _ghost3pos.second = _ghost3pos.second - vitesse*2;
                    }else{
                        _prev3.second = _prev3.second + vitesse;
                        _ghost3pos.second = _ghost3pos.second - vitesse;
                    }
                }else{
                    _prev3.second = _prev3.second + vitesse/2;
                    _ghost3pos.second = _ghost3pos.second - vitesse/2;
                }
            }
            if (_prev3.first == 4){
                if (modesuper == 0){
                    _prev3.second = _prev3.second + vitesse;
                    _ghost3pos.second = _ghost3pos.second + vitesse;
                }else if (dead3 == 1){
                    if (vitesse != 16){
                        _prev3.second = _prev3.second + vitesse*2;
                        _ghost3pos.second = _ghost3pos.second + vitesse*2;
                    }else{
                        _prev3.second = _prev3.second + vitesse;
                        _ghost3pos.second = _ghost3pos.second + vitesse;
                    }
                }else{
                    _prev3.second = _prev3.second + vitesse/2;
                    _ghost3pos.second = _ghost3pos.second + vitesse/2;
                }
            }
        }
        else if (modesuper == 0 && dead3 == 0){
            if (_ghost3pos.first > 16*22 && _ghost3pos.first < 16*28 && _ghost3pos.second > 16*14 && _ghost3pos.second < 16*20){
                _ghost3pos.second = _ghost3pos.second - vitesse;
                _prev3.second = vitesse;
                _prev3.first = 3;
            }else{
                ghost_move_random(_ghost3pos.first, _ghost3pos.second, &_prev3);
            }
        }else if (modesuper != 0 && dead3 == 0){
            ghost_flee(_ghost3pos.first, _ghost3pos.second, &_prev3);
        }else if (dead3 == 1 && _prev3.second == 16){
            if ((_ghost3pos.first >= 16*21 && _ghost3pos.first <= 16*29 && _ghost3pos.second == 16*14) || (_ghost3pos.first == 16*24 && _ghost3pos.second <= 16*17 && _ghost3pos.second >= 16*14)){
                if (_ghost3pos.first > 16*24)
                    _prev3.first = 1;
                else if (_ghost3pos.first < 16*24)
                    _prev3.first = 2;
                else if (_ghost3pos.first == 16*24)
                    _prev3.first = 4;
                _prev3.second = 0;
            }
            else
                ghost_go_home(_ghost3pos.first, _ghost3pos.second, &_prev3);
        }
    }
}

void Pacman::updateghost2()
{
    if (_ghost2pos.first == 16*25 && _ghost2pos.second == 16*18){
        dead2 = 2;
    }
    if (modesuper == 0 && dead2 == 2){
        dead2 = 0;
    }
    if (wait <= 0){
        if (_prev2.second != 16)
        {
            if (_prev2.first == 1){
                if (modesuper == 0){
                    if (_ghost2pos.first + vitesse >= 16*10 && _ghost2pos.second < 16*19 && _ghost2pos.second > 16*17)
                        _ghost2pos.first = 16*40;
                    else
                        _ghost2pos.first = _ghost2pos.first - vitesse;
                    _prev2.second = _prev2.second + vitesse;
                }else if (dead2 == 1){
                    if (vitesse != 16){
                        _prev2.second = _prev2.second + vitesse*2;
                        _ghost2pos.first = _ghost2pos.first - vitesse*2;
                    }else{
                        _prev2.second = _prev2.second + vitesse;
                        _ghost2pos.first = _ghost2pos.first - vitesse;
                    }
                }else{
                    if (_ghost2pos.first + vitesse >= 16*10 && _ghost2pos.second < 16*19 && _ghost2pos.second > 16*17)
                        _ghost2pos.first = 16*40;
                    else
                        _ghost2pos.first = _ghost2pos.first - vitesse/2;
                    _prev2.second = _prev2.second + vitesse/2;
                }
            }
            if (_prev2.first == 2){
                if (modesuper == 0){
                    if (_ghost2pos.first + vitesse >= 16*40 && _ghost2pos.second < 16*19 && _ghost2pos.second > 16*17)
                        _ghost2pos.first = 16*10;
                    else
                        _ghost2pos.first = _ghost2pos.first + vitesse;
                    _prev2.second = _prev2.second + vitesse;
                }else if (dead2 == 1){
                    if (vitesse != 16){
                        _prev2.second = _prev2.second + vitesse*2;
                        _ghost2pos.first = _ghost2pos.first + vitesse*2;
                    }else{
                        _prev2.second = _prev2.second + vitesse;
                        _ghost2pos.first = _ghost2pos.first + vitesse;
                    }
                }else{
                    if (_ghost2pos.first + vitesse >= 16*40 && _ghost2pos.second < 16*19 && _ghost2pos.second > 16*17)
                        _ghost2pos.first = 16*10;
                    else
                        _ghost2pos.first = _ghost2pos.first + vitesse/2;
                    _prev2.second = _prev2.second + vitesse/2;
                }
            }
            if (_prev2.first == 3){
                if (modesuper == 0){
                    _prev2.second = _prev2.second + vitesse;
                    _ghost2pos.second = _ghost2pos.second - vitesse;
                }else if (dead2 == 1){
                    if (vitesse != 16){
                        _prev2.second = _prev2.second + vitesse*2;
                        _ghost2pos.second = _ghost2pos.second - vitesse*2;
                    }else{
                        _prev2.second = _prev2.second + vitesse;
                        _ghost2pos.second = _ghost2pos.second - vitesse;
                    }
                }else{
                    _prev2.second = _prev2.second + vitesse/2;
                    _ghost2pos.second = _ghost2pos.second - vitesse/2;
                }
            }
            if (_prev2.first == 4){
                if (modesuper == 0){
                    _prev2.second = _prev2.second + vitesse;
                    _ghost2pos.second = _ghost2pos.second + vitesse;
                }else if (dead2 == 1){
                    if (vitesse != 16){
                        _prev2.second = _prev2.second + vitesse*2;
                        _ghost2pos.second = _ghost2pos.second + vitesse*2;
                    }else{
                        _prev2.second = _prev2.second + vitesse;
                        _ghost2pos.second = _ghost2pos.second + vitesse;
                    }
                }else{
                    _prev2.second = _prev2.second + vitesse/2;
                    _ghost2pos.second = _ghost2pos.second + vitesse/2;
                }
            }
        }
        else if (modesuper == 0 && dead2 == 0 && _prev2.second == 16){
            if (_ghost2pos.first > 16*22 && _ghost2pos.first < 16*28 && _ghost2pos.second > 16*14 && _ghost2pos.second < 16*20){
                _ghost2pos.second = _ghost2pos.second - vitesse;
                _prev2.second = vitesse;
                _prev2.first = 3;
            }else{
                ghost_move_random(_ghost2pos.first, _ghost2pos.second, &_prev2);
            }
        }else if (modesuper != 0 && dead2 == 0 && _prev2.second == 16){
            ghost_flee(_ghost2pos.first, _ghost2pos.second, &_prev2);
        }else if (dead2 == 1 && _prev2.second == 16){
            if ((_ghost2pos.first >= 16*21 && _ghost2pos.first <= 16*29 && _ghost2pos.second == 16*14) || (_ghost2pos.first == 16*25 && _ghost2pos.second <= 16*17 && _ghost2pos.second >= 16*14)){
                if (_ghost2pos.first > 16*25)
                    _prev2.first = 1;
                else if (_ghost2pos.first < 16*25)
                    _prev2.first = 2;
                else if (_ghost2pos.first == 16*25)
                    _prev2.first = 4;
                _prev2.second = 0;
            }
            else
                ghost_go_home(_ghost2pos.first, _ghost2pos.second, &_prev2);
        }
    }
}

void Pacman::updateghost1()
{
    if (_ghost1pos.first == 16*25 && _ghost1pos.second == 16*17){
        dead1 = 2;
    }
    if (modesuper == 0 && dead1 == 2){
        dead1 = 0;
    }
    if (wait <= 0){
        if (_prev1.second != 16)
        {
            if (_prev1.first == 1){
                if (modesuper == 0){
                    if (_ghost1pos.first + vitesse >= 16*10 && _ghost1pos.second < 16*19 && _ghost1pos.second > 16*17)
                        _ghost1pos.first = 16*40;
                    else
                        _ghost1pos.first = _ghost1pos.first - vitesse;
                    _prev1.second = _prev1.second + vitesse;
                }else if (dead1 == 1){
                    if (vitesse != 16){
                        _prev1.second = _prev1.second + vitesse*2;
                        _ghost1pos.first = _ghost1pos.first - vitesse*2;
                    }else{
                        _prev1.second = _prev1.second + vitesse;
                        _ghost1pos.first = _ghost1pos.first - vitesse;
                    }
                }else{
                    if (_ghost1pos.first + vitesse >= 16*10 && _ghost1pos.second < 16*19 && _ghost1pos.second > 16*17)
                        _ghost1pos.first = 16*40;
                    else
                        _ghost1pos.first = _ghost1pos.first - vitesse/2;
                    _prev1.second = _prev1.second + vitesse/2;
                }
            }
            if (_prev1.first == 2){
                if (modesuper == 0){
                    if (_ghost1pos.first + vitesse >= 16*40 && _ghost1pos.second < 16*19 && _ghost1pos.second > 16*17)
                        _ghost1pos.first = 16*10;
                    else
                        _ghost1pos.first = _ghost1pos.first + vitesse;
                    _prev1.second = _prev1.second + vitesse;
                }else if (dead1 == 1){
                    if (vitesse != 16){
                        _prev1.second = _prev1.second + vitesse*2;
                        _ghost1pos.first = _ghost1pos.first + vitesse*2;
                    }else{
                        _prev1.second = _prev1.second + vitesse;
                        _ghost1pos.first = _ghost1pos.first + vitesse;
                    }
                }else{
                    if (_ghost1pos.first + vitesse >= 16*40 && _ghost1pos.second < 16*19 && _ghost1pos.second > 16*17)
                        _ghost1pos.first = 16*10;
                    else
                        _ghost1pos.first = _ghost1pos.first + vitesse/2;
                    _prev1.second = _prev1.second + vitesse/2;
                }
            }
            if (_prev1.first == 3){
                if (modesuper == 0){
                    _prev1.second = _prev1.second + vitesse;
                    _ghost1pos.second = _ghost1pos.second - vitesse;
                }else if (dead1 == 1){
                    if (vitesse != 16){
                        _prev1.second = _prev1.second + vitesse*2;
                        _ghost1pos.second = _ghost1pos.second - vitesse*2;
                    }else{
                        _prev1.second = _prev1.second + vitesse;
                        _ghost1pos.second = _ghost1pos.second - vitesse;
                    }
                }else{
                    _prev1.second = _prev1.second + vitesse/2;
                    _ghost1pos.second = _ghost1pos.second - vitesse/2;
                }
            }
            if (_prev1.first == 4){
                if (modesuper == 0){
                    _prev1.second = _prev1.second + vitesse;
                    _ghost1pos.second = _ghost1pos.second + vitesse;
                }else if (dead1 == 1){
                    if (vitesse != 16){
                        _prev1.second = _prev1.second + vitesse*2;
                        _ghost1pos.second = _ghost1pos.second + vitesse*2;
                    }else{
                        _prev1.second = _prev1.second + vitesse;
                        _ghost1pos.second = _ghost1pos.second + vitesse;
                    }
                }else{
                    _prev1.second = _prev1.second + vitesse/2;
                    _ghost1pos.second = _ghost1pos.second + vitesse/2;
                }
            }
        }
        else if (modesuper == 0 && dead2 == 0 && _prev1.second == 16){
            if (_ghost1pos.first > 16*22 && _ghost1pos.first < 16*28 && _ghost1pos.second > 16*14 && _ghost1pos.second < 16*20){
                _ghost1pos.second = _ghost1pos.second - vitesse;
                _prev1.second = vitesse;
                _prev1.first = 3;
            }else{
                ghost_move(_ghost1pos.first, _ghost1pos.second, &_prev1);
            }
        }else if (modesuper != 0 && dead1 == 0 && _prev1.second == 16){
            ghost_flee(_ghost1pos.first, _ghost1pos.second, &_prev1);
        }else if (dead1 == 1 && _prev1.second == 16){
            if ((_ghost1pos.first >= 16*21 && _ghost1pos.first <= 16*29 && _ghost1pos.second == 16*14) || (_ghost1pos.first == 16*25 && _ghost1pos.second <= 16*17 && _ghost1pos.second >= 16*14)){
                if (_ghost1pos.first > 16*25)
                    _prev1.first = 1;
                else if (_ghost1pos.first < 16*25)
                    _prev1.first = 2;
                else if (_ghost1pos.first == 16*25)
                    _prev1.first = 4;
                _prev1.second = 0;
            }
            else
                ghost_go_home(_ghost1pos.first, _ghost1pos.second, &_prev1);
        }
    }
}

void Pacman::allghost()
{
    if (_pacpos.first ==  _ghost1pos.first && _pacpos.second == _ghost1pos.second){
        if (modesuper == 0 && dead1 == 0)
            reset();
        else
            dead1 = 1;
    }
    if (_pacpos.first == _ghost2pos.first && _pacpos.second == _ghost2pos.second){
        if (modesuper == 0 && dead2 == 0)
            reset();
        else
            dead2 = 1;
    }
    if (_pacpos.first == _ghost3pos.first && _pacpos.second == _ghost3pos.second){
        if (modesuper == 0 && dead3 == 0)
            reset();
        else
            dead3 = 1;
    }
    if (_pacpos.first == _ghost4pos.first && _pacpos.second == _ghost4pos.second){
        if (modesuper == 0 && dead4 == 0)
            reset();
        else
            dead4 = 1;
    }
    if (_ghost1pos.first < 16*9 || _ghost1pos.first > 16*41 || _ghost1pos.second < 16*6 ||  _ghost1pos.second > 16*30){
		_ghost1pos.first = 16*25;
        _ghost1pos.second = 16*17;
		_prev1.first = 0;
        _prev1.second = 16;
	}
	if (_ghost2pos.first < 16*9 || _ghost2pos.first > 16*41 || _ghost2pos.second < 16*6 ||  _ghost2pos.second > 16*30){
		_ghost2pos.first = 16*25;
        _ghost2pos.second = 16*18;
		_prev2.first = 0;
        _prev2.second = 16;
	}
	if (_ghost3pos.first < 16*9 || _ghost3pos.first > 16*41 || _ghost3pos.second < 16*6 ||  _ghost3pos.second > 16*30){
		_ghost3pos.first = 16*24;
        _ghost3pos.second = 16*18;
		_prev3.first = 0;
        _prev3.second = 16;
	}
	if (_ghost4pos.first < 16*9 || _ghost4pos.first > 16*41 || _ghost4pos.second < 16*6 ||  _ghost4pos.second > 16*30){
		_ghost4pos.first = 16*26;
        _ghost4pos.second = 16*18;
		_prev4.first = 0;
        _prev4.second = 16;
	}
    updateghost1();
    updateghost2();
    updateghost3();
    updateghost4();
    if (wait != - 0)
        wait--;
}

void Pacman::update()
{
    auto v = _supervalable.begin();
    auto nv = _normalvalable.begin();

    left = 0;
    for (auto it = _normalvalable.begin(); it != _normalvalable.end(); it++)
        left = left + *it;
    for (auto it = _supervalable.begin(); it != _supervalable.end(); it++)
        left = left + *it;
    if (left == 0)
        win();
    allghost();
    if (_prevpacman.second != 16 && _prevpacman.first != 0){
        if (_prevpacman.first == 1){
            _pacpos.first = _pacpos.first - vitesse;
            _prevpacman.second = _prevpacman.second + vitesse;
        }
        if (_prevpacman.first == 2){
            _pacpos.first = _pacpos.first + vitesse;
            _prevpacman.second = _prevpacman.second + vitesse;
        }
        if (_prevpacman.first == 3){
            _pacpos.second = _pacpos.second - vitesse;
            _prevpacman.second = _prevpacman.second + vitesse;
        }
        if (_prevpacman.first == 4){
            _pacpos.second = _pacpos.second + vitesse;
            _prevpacman.second = _prevpacman.second + vitesse;
        }
    }else{
        if (_core->isButtonPressed(ICore::Button::Left) == true && nowallghost(1,_pacpos.first,_pacpos.second) == true){
            if (_pacpos.first - vitesse <= 16*10 && _pacpos.second < 16*19 && _pacpos.second > 16*17)
                _pacpos.first = 16*40;
            else{
                _prevpacman.first = 1;
                _prevpacman.second = 0;
            }
        }else if (_core->isButtonPressed(ICore::Button::Right) == true && nowallghost(2,_pacpos.first,_pacpos.second) == true){
            if (_pacpos.first + vitesse >= 16*40 && _pacpos.second < 16*19 && _pacpos.second > 16*17)
                _pacpos.first = 16*10;
            else{
                _prevpacman.first = 2;
                _prevpacman.second = 0;
            }
        }else if (_core->isButtonPressed(ICore::Button::Up) == true && nowallghost(3,_pacpos.first,_pacpos.second) == true){
            _prevpacman.first = 3;
            _prevpacman.second = 0;
        }else if (_core->isButtonPressed(ICore::Button::Down) == true && nowallghost(4,_pacpos.first,_pacpos.second) == true){
            _prevpacman.first = 4;
            _prevpacman.second = 0;
        }else if (nowallghost(_prevpacman.first,_pacpos.first,_pacpos.second) == true){
            if (_prevpacman.first == 1 && _pacpos.first - vitesse <= 16*10 && _pacpos.second < 16*19 && _pacpos.second > 16*17)
                _pacpos.first = 16*40;
            if (_prevpacman.first == 2 && _pacpos.first + vitesse >= 16*40 && _pacpos.second < 16*19 && _pacpos.second > 16*17)
                _pacpos.first = 16*10;
            _prevpacman.second = 0;
        }
    }
    for (auto it = _superpos.begin(); it != _superpos.end(); it++, v++){
        if (_pacpos.first == it->first && _pacpos.second == it->second && *v == 1){
            *v = 0;
            modesuper = 300;
            score = score + 100;
        }
    }
    for (auto it = _normalpos.begin(); it != _normalpos.end(); it++, nv++){
        if (_pacpos.first == it->first && _pacpos.second == it->second && *nv == 1){
            *nv = 0;
            score = score + 100;
        }
    }
    if (modesuper != 0)
        modesuper--;
    return;
}

void Pacman::fill_vector_normal()
{
    for (int i = 13; i != 25; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*7));
        _normalvalable.push_back(1);
    }
    for (int i = 26; i != 39; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*7));
        _normalvalable.push_back(1);
    }
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*8));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*8));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*24,16*8));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*26,16*8));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*34,16*8));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*8));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*8));
    _normalvalable.push_back(1);
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*9));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*9));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*24,16*9));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*26,16*9));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*34,16*9));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*9));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*9));
    _normalvalable.push_back(1);
    for (int i = 12; i != 18; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*10));
        _normalvalable.push_back(1);
    }
    for (int i = 18; i != 25; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*10));
        _normalvalable.push_back(1);
    }
    for (int i = 26; i != 35; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*10));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*37,16*10));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*10));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*12,16*11));
    _normalvalable.push_back(1);
    for (int i = 14; i != 17; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*11));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*18,16*11));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*24,16*11));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*26,16*11));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*34,16*11));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*11));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*11));
    _normalvalable.push_back(1);
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*12));
        _normalvalable.push_back(1);
    }
    for (int i = 21; i != 30; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*12));
        _normalvalable.push_back(1);
    }
    for (int i = 31; i != 40; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*12));
        _normalvalable.push_back(1);
    }for (int i = 12; i != 15; i++)
     {
         _normalpos.push_back(std::make_pair(16*i,16*13));
         _normalvalable.push_back(1);
     }
    _normalpos.push_back(std::make_pair(16*16,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*18,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*31,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*13));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*13));
    _normalvalable.push_back(1);
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*14));
        _normalvalable.push_back(1);
    }
    for (int i = 21; i != 30; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*14));
        _normalvalable.push_back(1);
    }
    for (int i = 31; i != 38; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*14));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*39,16*14));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*12,16*15));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*14,16*15));
    _normalvalable.push_back(1);
    for (int i = 16; i != 19; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*15));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*15));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*15));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*34,16*15));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*15));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*15));
    _normalvalable.push_back(1);
    for (int i = 12; i != 18; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*16));
        _normalvalable.push_back(1);
    }
    for (int i = 18; i != 22; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*16));
        _normalvalable.push_back(1);
    }
    for (int i = 29; i != 40; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*16));
        _normalvalable.push_back(1);
    }
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*17));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*17));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*17));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*17));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*18));
    _normalvalable.push_back(1);
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*18));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*18));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*18));
    _normalvalable.push_back(1);
    for (int i = 37; i != 40; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*18));
        _normalvalable.push_back(1);
    }
    for (int i = 12; i != 20; i = i + 2)
    {
        _normalpos.push_back(std::make_pair(16*i,16*19));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*19));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*19));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*19));
    _normalvalable.push_back(1);
    for (int i = 11; i != 19; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*20));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*21,16*20));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*20));
    _normalvalable.push_back(1);
    for (int i = 37; i != 40; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*20));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*11,16*21));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*21));
    _normalvalable.push_back(1);
    for (int i = 21; i != 25; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*21));
        _normalvalable.push_back(1);
    }
    for (int i = 26; i != 30; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*21));
        _normalvalable.push_back(1);
    }
    for (int i = 33; i != 38; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*21));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*39,16*21));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*33,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*22));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*23));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*23));
    _normalvalable.push_back(1);
    for (int i = 21; i != 30; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*23));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*33,16*23));
    _normalvalable.push_back(1);
    for (int i = 37; i != 40; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*23));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*11,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*25,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*33,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*24));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*24));
    _normalvalable.push_back(1);
    for (int i = 11; i != 22; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*25));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*25,16*25));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*25));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*33,16*25));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*25));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*25));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*25,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*29,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*33,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*37,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*26));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*27));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*27));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*27));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*25,16*27));
    _normalvalable.push_back(1);
    for (int i = 29; i != 38; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*27));
        _normalvalable.push_back(1);
    }
    _normalpos.push_back(std::make_pair(16*39,16*27));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*11,16*28));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*16,16*28));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*21,16*28));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*25,16*28));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*32,16*28));
    _normalvalable.push_back(1);
    _normalpos.push_back(std::make_pair(16*39,16*28));
    _normalvalable.push_back(1);
    for (int i = 12; i != 22; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*29));
        _normalvalable.push_back(1);
    }
    for (int i = 25; i != 39; i++)
    {
        _normalpos.push_back(std::make_pair(16*i,16*29));
        _normalvalable.push_back(1);
    }
}

void Pacman::draw()
{
    ICore::Sprite sprite;
    ICore::Sprite super1;
    ICore::Sprite super2;
    ICore::Sprite super3;
    ICore::Sprite super4;
    ICore::Sprite ghost1;
    ICore::Sprite ghost2;
    ICore::Sprite ghost3;
    ICore::Sprite ghost4;
    auto vs = _supervalable.begin();

    sprite.pixelPosition = {_pacpos.first, _pacpos.second};
    sprite.texture = _pacman;
    ghost1.pixelPosition = {_ghost1pos.first, _ghost1pos.second};
    if (dead1 == 1)
        ghost1.texture = _ghosteat;
    else if (modesuper != 0 && dead1 != 2)
        ghost1.texture = _ghostflee;
    else
        ghost1.texture = _ghost1;
    ghost2.pixelPosition = {_ghost2pos.first, _ghost2pos.second};
    if (dead2 == 1)
        ghost2.texture = _ghosteat;
    else if (modesuper != 0 && dead2 != 2)
        ghost2.texture = _ghostflee;
    else
        ghost2.texture = _ghost2;
    ghost3.pixelPosition = {_ghost3pos.first, _ghost3pos.second};
    if (dead3 == 1)
        ghost3.texture = _ghosteat;
    else if (modesuper != 0 && dead3 != 2)
        ghost3.texture = _ghostflee;
    else
        ghost3.texture = _ghost3;
    ghost4.pixelPosition = {_ghost4pos.first, _ghost4pos.second};
    if (dead4 == 1)
        ghost4.texture = _ghosteat;
    else if (modesuper != 0 && dead4 != 2)
        ghost4.texture = _ghostflee;
    else
        ghost4.texture = _ghost4;
    super1.pixelPosition = {16*12, 16*7};
    super1.texture = _superpacgum;
    super2.pixelPosition = {16*39, 16*7};
    super2.texture = _superpacgum;
    super3.pixelPosition = {16*11, 16*29};
    super3.texture = _superpacgum;
    super4.pixelPosition = {16*39, 16*29};
    super4.texture = _superpacgum;
    _core->clearScreen(ICore::Color::black);
    draw_wall();
    draw_wall2();
    draw_wall3();
    draw_wall4();
    draw_corner();
    random_wall();
    random_wall2();
    random_wall3();
    random_wall4();
    ghost_house();
    draw_pacgum();
    if (*vs == 1)
        _core->renderSprite(super1);
    vs++;
    if (*vs == 1)
        _core->renderSprite(super2);
    vs++;
    if (*vs == 1)
        _core->renderSprite(super3);
    vs++;
    if (*vs == 1)
        _core->renderSprite(super4);
    vs++;
    _core->renderSprite(sprite);
    _core->renderSprite(ghost1);
    _core->renderSprite(ghost2);
    _core->renderSprite(ghost3);
    _core->renderSprite(ghost4);
    return;
}

void Pacman::draw_pacgum()
{
    auto it = _normalpos.begin();
    auto v = _normalvalable.begin();
	
    ICore::Sprite pac1;
    pac1.pixelPosition = {it->first,it->second};
    pac1.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac1);
    v++;
    it++;
    ICore::Sprite pac2;
    pac2.pixelPosition = {it->first,it->second};
    pac2.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac2);
    v++;
    it++;
    ICore::Sprite pac3;
    pac3.pixelPosition = {it->first,it->second};
    pac3.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac3);
    v++;
    it++;
    ICore::Sprite pac4;
    pac4.pixelPosition = {it->first,it->second};
    pac4.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac4);
    v++;
    it++;
    ICore::Sprite pac5;
    pac5.pixelPosition = {it->first,it->second};
    pac5.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac5);
    v++;
    it++;
    ICore::Sprite pac6;
    pac6.pixelPosition = {it->first,it->second};
    pac6.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac6);
    v++;
    it++;
    ICore::Sprite pac7;
    pac7.pixelPosition = {it->first,it->second};
    pac7.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac7);
    v++;
    it++;
    ICore::Sprite pac8;
    pac8.pixelPosition = {it->first,it->second};
    pac8.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac8);
    v++;
    it++;
    ICore::Sprite pac9;
    pac9.pixelPosition = {it->first,it->second};
    pac9.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac9);
    v++;
    it++;
    ICore::Sprite pac10;
    pac10.pixelPosition = {it->first,it->second};
    pac10.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac10);
    v++;
    it++;
    ICore::Sprite pac11;
    pac11.pixelPosition = {it->first,it->second};
    pac11.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac11);
    v++;
    it++;
    ICore::Sprite pac12;
    pac12.pixelPosition = {it->first,it->second};
    pac12.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac12);
    v++;
    it++;
    ICore::Sprite pac13;
    pac13.pixelPosition = {it->first,it->second};
    pac13.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac13);
    v++;
    it++;
    ICore::Sprite pac14;
    pac14.pixelPosition = {it->first,it->second};
    pac14.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac14);
    v++;
    it++;
    ICore::Sprite pac15;
    pac15.pixelPosition = {it->first,it->second};
    pac15.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac15);
    v++;
    it++;
    ICore::Sprite pac16;
    pac16.pixelPosition = {it->first,it->second};
    pac16.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac16);
    v++;
    it++;
    ICore::Sprite pac17;
    pac17.pixelPosition = {it->first,it->second};
    pac17.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac17);
    v++;
    it++;
    ICore::Sprite pac18;
    pac18.pixelPosition = {it->first,it->second};
    pac18.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac18);
    v++;
    it++;
    ICore::Sprite pac19;
    pac19.pixelPosition = {it->first,it->second};
    pac19.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac19);
    v++;
    it++;
    ICore::Sprite pac20;
    pac20.pixelPosition = {it->first,it->second};
    pac20.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac20);
    v++;
    it++;
    ICore::Sprite pac21;
    pac21.pixelPosition = {it->first,it->second};
    pac21.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac21);
    v++;
    it++;
    ICore::Sprite pac22;
    pac22.pixelPosition = {it->first,it->second};
    pac22.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac22);
    v++;
    it++;
    ICore::Sprite pac23;
    pac23.pixelPosition = {it->first,it->second};
    pac23.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac23);
    v++;
    it++;
    ICore::Sprite pac24;
    pac24.pixelPosition = {it->first,it->second};
    pac24.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac24);
    v++;
    it++;
    ICore::Sprite pac25;
    pac25.pixelPosition = {it->first,it->second};
    pac25.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac25);
    v++;
    it++;
    ICore::Sprite pac26;
    pac26.pixelPosition = {it->first,it->second};
    pac26.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac26);
    v++;
    it++;
    ICore::Sprite pac27;
    pac27.pixelPosition = {it->first,it->second};
    pac27.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac27);
    v++;
    it++;
    ICore::Sprite pac28;
    pac28.pixelPosition = {it->first,it->second};
    pac28.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac28);
    v++;
    it++;
    ICore::Sprite pac29;
    pac29.pixelPosition = {it->first,it->second};
    pac29.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac29);
    v++;
    it++;
    ICore::Sprite pac30;
    pac30.pixelPosition = {it->first,it->second};
    pac30.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac30);
    v++;
    it++;
    ICore::Sprite pac31;
    pac31.pixelPosition = {it->first,it->second};
    pac31.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac31);
    v++;
    it++;
    ICore::Sprite pac32;
    pac32.pixelPosition = {it->first,it->second};
    pac32.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac32);
    v++;
    it++;
    ICore::Sprite pac33;
    pac33.pixelPosition = {it->first,it->second};
    pac33.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac33);
    v++;
    it++;
    ICore::Sprite pac34;
    pac34.pixelPosition = {it->first,it->second};
    pac34.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac34);
    v++;
    it++;
    ICore::Sprite pac35;
    pac35.pixelPosition = {it->first,it->second};
    pac35.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac35);
    v++;
    it++;
    ICore::Sprite pac36;
    pac36.pixelPosition = {it->first,it->second};
    pac36.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac36);
    v++;
    it++;
    ICore::Sprite pac37;
    pac37.pixelPosition = {it->first,it->second};
    pac37.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac37);
    v++;
    it++;
    ICore::Sprite pac38;
    pac38.pixelPosition = {it->first,it->second};
    pac38.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac38);
    v++;
    it++;
    ICore::Sprite pac39;
    pac39.pixelPosition = {it->first,it->second};
    pac39.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac39);
    v++;
    it++;
    ICore::Sprite pac50;
    pac50.pixelPosition = {it->first,it->second};
    pac50.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac50);
    v++;
    it++;
    ICore::Sprite pac51;
    pac51.pixelPosition = {it->first,it->second};
    pac51.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac51);
    v++;
    it++;
    ICore::Sprite pac52;
    pac52.pixelPosition = {it->first,it->second};
    pac52.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac52);
    v++;
    it++;
    ICore::Sprite pac53;
    pac53.pixelPosition = {it->first,it->second};
    pac53.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac53);
    v++;
    it++;
    ICore::Sprite pac54;
    pac54.pixelPosition = {it->first,it->second};
    pac54.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac54);
    v++;
    it++;
    ICore::Sprite pac55;
    pac55.pixelPosition = {it->first,it->second};
    pac55.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac55);
    v++;
    it++;
    ICore::Sprite pac56;
    pac56.pixelPosition = {it->first,it->second};
    pac56.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac56);
    v++;
    it++;
    ICore::Sprite pac57;
    pac57.pixelPosition = {it->first,it->second};
    pac57.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac57);
    v++;
    it++;
    ICore::Sprite pac58;
    pac58.pixelPosition = {it->first,it->second};
    pac58.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac58);
    v++;
    it++;
    ICore::Sprite pac59;
    pac59.pixelPosition = {it->first,it->second};
    pac59.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac59);
    v++;
    it++;
    ICore::Sprite pac40;
    pac40.pixelPosition = {it->first,it->second};
    pac40.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac40);
    v++;
    it++;
    ICore::Sprite pac41;
    pac41.pixelPosition = {it->first,it->second};
    pac41.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac41);
    v++;
    it++;
    ICore::Sprite pac42;
    pac42.pixelPosition = {it->first,it->second};
    pac42.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac42);
    v++;
    it++;
    ICore::Sprite pac43;
    pac43.pixelPosition = {it->first,it->second};
    pac43.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac43);
    v++;
    it++;
    ICore::Sprite pac44;
    pac44.pixelPosition = {it->first,it->second};
    pac44.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac44);
    v++;
    it++;
    ICore::Sprite pac45;
    pac45.pixelPosition = {it->first,it->second};
    pac45.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac45);
    v++;
    it++;
    ICore::Sprite pac46;
    pac46.pixelPosition = {it->first,it->second};
    pac46.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac46);
    v++;
    it++;
    ICore::Sprite pac47;
    pac47.pixelPosition = {it->first,it->second};
    pac47.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac47);
    v++;
    it++;
    ICore::Sprite pac48;
    pac48.pixelPosition = {it->first,it->second};
    pac48.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac48);
    v++;
    it++;
    ICore::Sprite pac49;
    pac49.pixelPosition = {it->first,it->second};
    pac49.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac49);
    v++;
    it++;
    ICore::Sprite pac60;
    pac60.pixelPosition = {it->first,it->second};
    pac60.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac60);
    v++;
    it++;
    ICore::Sprite pac61;
    pac61.pixelPosition = {it->first,it->second};
    pac61.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac61);
    v++;
    it++;
    ICore::Sprite pac62;
    pac62.pixelPosition = {it->first,it->second};
    pac62.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac62);
    v++;
    it++;
    ICore::Sprite pac63;
    pac63.pixelPosition = {it->first,it->second};
    pac63.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac63);
    v++;
    it++;
    ICore::Sprite pac64;
    pac64.pixelPosition = {it->first,it->second};
    pac64.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac64);
    v++;
    it++;
    ICore::Sprite pac65;
    pac65.pixelPosition = {it->first,it->second};
    pac65.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac65);
    v++;
    it++;
    ICore::Sprite pac66;
    pac66.pixelPosition = {it->first,it->second};
    pac66.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac66);
    v++;
    it++;
    ICore::Sprite pac67;
    pac67.pixelPosition = {it->first,it->second};
    pac67.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac67);
    v++;
    it++;
    ICore::Sprite pac68;
    pac68.pixelPosition = {it->first,it->second};
    pac68.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac68);
    v++;
    it++;
    ICore::Sprite pac69;
    pac69.pixelPosition = {it->first,it->second};
    pac69.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac69);
    v++;
    it++;
    ICore::Sprite pac70;
    pac70.pixelPosition = {it->first,it->second};
    pac70.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac70);
    v++;
    it++;
    ICore::Sprite pac71;
    pac71.pixelPosition = {it->first,it->second};
    pac71.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac71);
    v++;
    it++;
    ICore::Sprite pac72;
    pac72.pixelPosition = {it->first,it->second};
    pac72.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac72);
    v++;
    it++;
    ICore::Sprite pac73;
    pac73.pixelPosition = {it->first,it->second};
    pac73.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac73);
    v++;
    it++;
    ICore::Sprite pac74;
    pac74.pixelPosition = {it->first,it->second};
    pac74.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac74);
    v++;
    it++;
    ICore::Sprite pac75;
    pac75.pixelPosition = {it->first,it->second};
    pac75.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac75);
    v++;
    it++;
    ICore::Sprite pac76;
    pac76.pixelPosition = {it->first,it->second};
    pac76.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac76);
    v++;
    it++;
    ICore::Sprite pac77;
    pac77.pixelPosition = {it->first,it->second};
    pac77.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac77);
    v++;
    it++;
    ICore::Sprite pac78;
    pac78.pixelPosition = {it->first,it->second};
    pac78.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac78);
    v++;
    it++;
    ICore::Sprite pac79;
    pac79.pixelPosition = {it->first,it->second};
    pac79.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac79);
    v++;
    it++;
    ICore::Sprite pac80;
    pac80.pixelPosition = {it->first,it->second};
    pac80.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac80);
    v++;
    it++;
    ICore::Sprite pac81;
    pac81.pixelPosition = {it->first,it->second};
    pac81.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac81);
    v++;
    it++;
    ICore::Sprite pac82;
    pac82.pixelPosition = {it->first,it->second};
    pac82.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac82);
    v++;
    it++;
    ICore::Sprite pac83;
    pac83.pixelPosition = {it->first,it->second};
    pac83.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac83);
    v++;
    it++;
    ICore::Sprite pac84;
    pac84.pixelPosition = {it->first,it->second};
    pac84.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac84);
    v++;
    it++;
    ICore::Sprite pac85;
    pac85.pixelPosition = {it->first,it->second};
    pac85.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac85);
    v++;
    it++;
    ICore::Sprite pac86;
    pac86.pixelPosition = {it->first,it->second};
    pac86.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac86);
    v++;
    it++;
    ICore::Sprite pac87;
    pac87.pixelPosition = {it->first,it->second};
    pac87.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac87);
    v++;
    it++;
    ICore::Sprite pac88;
    pac88.pixelPosition = {it->first,it->second};
    pac88.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac88);
    v++;
    it++;
    ICore::Sprite pac89;
    pac89.pixelPosition = {it->first,it->second};
    pac89.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac89);
    v++;
    it++;
    ICore::Sprite pac90;
    pac90.pixelPosition = {it->first,it->second};
    pac90.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac90);
    v++;
    it++;
    ICore::Sprite pac91;
    pac91.pixelPosition = {it->first,it->second};
    pac91.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac91);
    v++;
    it++;
    ICore::Sprite pac92;
    pac92.pixelPosition = {it->first,it->second};
    pac92.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac92);
    v++;
    it++;
    ICore::Sprite pac93;
    pac93.pixelPosition = {it->first,it->second};
    pac93.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac93);
    v++;
    it++;
    ICore::Sprite pac94;
    pac94.pixelPosition = {it->first,it->second};
    pac94.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac94);
    v++;
    it++;
    ICore::Sprite pac95;
    pac95.pixelPosition = {it->first,it->second};
    pac95.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac95);
    v++;
    it++;
    ICore::Sprite pac96;
    pac96.pixelPosition = {it->first,it->second};
    pac96.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac96);
    v++;
    it++;
    ICore::Sprite pac97;
    pac97.pixelPosition = {it->first,it->second};
    pac97.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac97);
    v++;
    it++;
    ICore::Sprite pac98;
    pac98.pixelPosition = {it->first,it->second};
    pac98.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac98);
    v++;
    it++;
    ICore::Sprite pac99;
    pac99.pixelPosition = {it->first,it->second};
    pac99.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac99);
    v++;
    it++;
    ICore::Sprite pac100;
    pac100.pixelPosition = {it->first,it->second};
    pac100.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac100);
    v++;
    it++;
    ICore::Sprite pac101;
    pac101.pixelPosition = {it->first,it->second};
    pac101.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac101);
    v++;
    it++;
    ICore::Sprite pac102;
    pac102.pixelPosition = {it->first,it->second};
    pac102.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac102);
    v++;
    it++;
    ICore::Sprite pac103;
    pac103.pixelPosition = {it->first,it->second};
    pac103.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac103);
    v++;
    it++;
    ICore::Sprite pac104;
    pac104.pixelPosition = {it->first,it->second};
    pac104.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac104);
    v++;
    it++;
    ICore::Sprite pac105;
    pac105.pixelPosition = {it->first,it->second};
    pac105.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac105);
    v++;
    it++;
    ICore::Sprite pac106;
    pac106.pixelPosition = {it->first,it->second};
    pac106.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac106);
    v++;
    it++;
    ICore::Sprite pac107;
    pac107.pixelPosition = {it->first,it->second};
    pac107.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac107);
    v++;
    it++;
    ICore::Sprite pac108;
    pac108.pixelPosition = {it->first,it->second};
    pac108.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac108);
    v++;
    it++;
    ICore::Sprite pac109;
    pac109.pixelPosition = {it->first,it->second};
    pac109.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac109);
    v++;
    it++;
    ICore::Sprite pac110;
    pac110.pixelPosition = {it->first,it->second};
    pac110.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac110);
    v++;
    it++;
    ICore::Sprite pac111;
    pac111.pixelPosition = {it->first,it->second};
    pac111.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac111);
    v++;
    it++;
    ICore::Sprite pac112;
    pac112.pixelPosition = {it->first,it->second};
    pac112.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac112);
    v++;
    it++;
    ICore::Sprite pac113;
    pac113.pixelPosition = {it->first,it->second};
    pac113.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac113);
    v++;
    it++;
    ICore::Sprite pac114;
    pac114.pixelPosition = {it->first,it->second};
    pac114.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac114);
    v++;
    it++;
    ICore::Sprite pac115;
    pac115.pixelPosition = {it->first,it->second};
    pac115.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac115);
    v++;
    it++;
    ICore::Sprite pac116;
    pac116.pixelPosition = {it->first,it->second};
    pac116.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac116);
    v++;
    it++;
    ICore::Sprite pac117;
    pac117.pixelPosition = {it->first,it->second};
    pac117.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac117);
    v++;
    it++;
    ICore::Sprite pac118;
    pac118.pixelPosition = {it->first,it->second};
    pac118.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac118);
    v++;
    it++;
    ICore::Sprite pac119;
    pac119.pixelPosition = {it->first,it->second};
    pac119.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac119);
    v++;
    it++;
    ICore::Sprite pac120;
    pac120.pixelPosition = {it->first,it->second};
    pac120.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac120);
    v++;
    it++;
    ICore::Sprite pac121;
    pac121.pixelPosition = {it->first,it->second};
    pac121.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac121);
    v++;
    it++;
    ICore::Sprite pac122;
    pac122.pixelPosition = {it->first,it->second};
    pac122.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac122);
    v++;
    it++;
    ICore::Sprite pac123;
    pac123.pixelPosition = {it->first,it->second};
    pac123.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac123);
    v++;
    it++;
    ICore::Sprite pac124;
    pac124.pixelPosition = {it->first,it->second};
    pac124.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac124);
    v++;
    it++;
    ICore::Sprite pac125;
    pac125.pixelPosition = {it->first,it->second};
    pac125.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac125);
    v++;
    it++;
    ICore::Sprite pac126;
    pac126.pixelPosition = {it->first,it->second};
    pac126.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac126);
    v++;
    it++;
    ICore::Sprite pac127;
    pac127.pixelPosition = {it->first,it->second};
    pac127.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac127);
    v++;
    it++;
    ICore::Sprite pac128;
    pac128.pixelPosition = {it->first,it->second};
    pac128.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac128);
    v++;
    it++;
    ICore::Sprite pac129;
    pac129.pixelPosition = {it->first,it->second};
    pac129.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac129);
    v++;
    it++;
    ICore::Sprite pac130;
    pac130.pixelPosition = {it->first,it->second};
    pac130.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac130);
    v++;
    it++;
    ICore::Sprite pac131;
    pac131.pixelPosition = {it->first,it->second};
    pac131.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac131);
    v++;
    it++;
    ICore::Sprite pac132;
    pac132.pixelPosition = {it->first,it->second};
    pac132.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac132);
    v++;
    it++;
    ICore::Sprite pac133;
    pac133.pixelPosition = {it->first,it->second};
    pac133.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac133);
    v++;
    it++;
    ICore::Sprite pac134;
    pac134.pixelPosition = {it->first,it->second};
    pac134.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac134);
    v++;
    it++;
    ICore::Sprite pac135;
    pac135.pixelPosition = {it->first,it->second};
    pac135.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac135);
    v++;
    it++;
    ICore::Sprite pac136;
    pac136.pixelPosition = {it->first,it->second};
    pac136.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac136);
    v++;
    it++;
    ICore::Sprite pac137;
    pac137.pixelPosition = {it->first,it->second};
    pac137.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac137);
    v++;
    it++;
    ICore::Sprite pac138;
    pac138.pixelPosition = {it->first,it->second};
    pac138.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac138);
    v++;
    it++;
    ICore::Sprite pac139;
    pac139.pixelPosition = {it->first,it->second};
    pac139.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac139);
    v++;
    it++;
    ICore::Sprite pac140;
    pac140.pixelPosition = {it->first,it->second};
    pac140.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac140);
    v++;
    it++;
    ICore::Sprite pac141;
    pac141.pixelPosition = {it->first,it->second};
    pac141.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac141);
    v++;
    it++;
    ICore::Sprite pac142;
    pac142.pixelPosition = {it->first,it->second};
    pac142.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac142);
    v++;
    it++;
    ICore::Sprite pac143;
    pac143.pixelPosition = {it->first,it->second};
    pac143.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac143);
    v++;
    it++;
    ICore::Sprite pac144;
    pac144.pixelPosition = {it->first,it->second};
    pac144.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac144);
    v++;
    it++;
    ICore::Sprite pac145;
    pac145.pixelPosition = {it->first,it->second};
    pac145.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac145);
    v++;
    it++;
    ICore::Sprite pac146;
    pac146.pixelPosition = {it->first,it->second};
    pac146.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac146);
    v++;
    it++;
    ICore::Sprite pac147;
    pac147.pixelPosition = {it->first,it->second};
    pac147.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac147);
    v++;
    it++;
    ICore::Sprite pac148;
    pac148.pixelPosition = {it->first,it->second};
    pac148.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac148);
    v++;
    it++;
    ICore::Sprite pac149;
    pac149.pixelPosition = {it->first,it->second};
    pac149.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac149);
    v++;
    it++;
    ICore::Sprite pac150;
    pac150.pixelPosition = {it->first,it->second};
    pac150.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac150);
    v++;
    it++;
    ICore::Sprite pac151;
    pac151.pixelPosition = {it->first,it->second};
    pac151.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac151);
    v++;
    it++;
    ICore::Sprite pac152;
    pac152.pixelPosition = {it->first,it->second};
    pac152.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac152);
    v++;
    it++;
    ICore::Sprite pac153;
    pac153.pixelPosition = {it->first,it->second};
    pac153.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac153);
    v++;
    it++;
    ICore::Sprite pac154;
    pac154.pixelPosition = {it->first,it->second};
    pac154.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac154);
    v++;
    it++;
    ICore::Sprite pac155;
    pac155.pixelPosition = {it->first,it->second};
    pac155.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac155);
    v++;
    it++;
    ICore::Sprite pac156;
    pac156.pixelPosition = {it->first,it->second};
    pac156.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac156);
    v++;
    it++;
    ICore::Sprite pac157;
    pac157.pixelPosition = {it->first,it->second};
    pac157.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac157);
    v++;
    it++;
    ICore::Sprite pac158;
    pac158.pixelPosition = {it->first,it->second};
    pac158.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac158);
    v++;
    it++;
    ICore::Sprite pac159;
    pac159.pixelPosition = {it->first,it->second};
    pac159.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac159);
    v++;
    it++;
    ICore::Sprite pac160;
    pac160.pixelPosition = {it->first,it->second};
    pac160.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac160);
    v++;
    it++;
    ICore::Sprite pac161;
    pac161.pixelPosition = {it->first,it->second};
    pac161.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac161);
    v++;
    it++;
    ICore::Sprite pac162;
    pac162.pixelPosition = {it->first,it->second};
    pac162.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac162);
    v++;
    it++;
    ICore::Sprite pac163;
    pac163.pixelPosition = {it->first,it->second};
    pac163.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac163);
    v++;
    it++;
    ICore::Sprite pac164;
    pac164.pixelPosition = {it->first,it->second};
    pac164.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac164);
    v++;
    it++;
    ICore::Sprite pac165;
    pac165.pixelPosition = {it->first,it->second};
    pac165.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac165);
    v++;
    it++;
    ICore::Sprite pac166;
    pac166.pixelPosition = {it->first,it->second};
    pac166.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac166);
    v++;
    it++;
    ICore::Sprite pac167;
    pac167.pixelPosition = {it->first,it->second};
    pac167.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac167);
    v++;
    it++;
    ICore::Sprite pac168;
    pac168.pixelPosition = {it->first,it->second};
    pac168.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac168);
    v++;
    it++;
    ICore::Sprite pac169;
    pac169.pixelPosition = {it->first,it->second};
    pac169.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac169);
    v++;
    it++;
    ICore::Sprite pac170;
    pac170.pixelPosition = {it->first,it->second};
    pac170.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac170);
    v++;
    it++;
    ICore::Sprite pac171;
    pac171.pixelPosition = {it->first,it->second};
    pac171.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac171);
    v++;
    it++;
    ICore::Sprite pac172;
    pac172.pixelPosition = {it->first,it->second};
    pac172.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac172);
    v++;
    it++;
    ICore::Sprite pac173;
    pac173.pixelPosition = {it->first,it->second};
    pac173.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac173);
    v++;
    it++;
    ICore::Sprite pac174;
    pac174.pixelPosition = {it->first,it->second};
    pac174.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac174);
    v++;
    it++;
    ICore::Sprite pac175;
    pac175.pixelPosition = {it->first,it->second};
    pac175.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac175);
    v++;
    it++;
    ICore::Sprite pac176;
    pac176.pixelPosition = {it->first,it->second};
    pac176.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac176);
    v++;
    it++;
    ICore::Sprite pac177;
    pac177.pixelPosition = {it->first,it->second};
    pac177.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac177);
    v++;
    it++;
    ICore::Sprite pac178;
    pac178.pixelPosition = {it->first,it->second};
    pac178.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac178);
    v++;
    it++;
    ICore::Sprite pac179;
    pac179.pixelPosition = {it->first,it->second};
    pac179.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac179);
    v++;
    it++;
    ICore::Sprite pac180;
    pac180.pixelPosition = {it->first,it->second};
    pac180.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac180);
    v++;
    it++;
    ICore::Sprite pac181;
    pac181.pixelPosition = {it->first,it->second};
    pac181.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac181);
    v++;
    it++;
    ICore::Sprite pac182;
    pac182.pixelPosition = {it->first,it->second};
    pac182.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac182);
    v++;
    it++;
    ICore::Sprite pac183;
    pac183.pixelPosition = {it->first,it->second};
    pac183.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac183);
    v++;
    it++;
    ICore::Sprite pac184;
    pac184.pixelPosition = {it->first,it->second};
    pac184.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac184);
    v++;
    it++;
    ICore::Sprite pac185;
    pac185.pixelPosition = {it->first,it->second};
    pac185.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac185);
    v++;
    it++;
    ICore::Sprite pac186;
    pac186.pixelPosition = {it->first,it->second};
    pac186.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac186);
    v++;
    it++;
    ICore::Sprite pac187;
    pac187.pixelPosition = {it->first,it->second};
    pac187.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac187);
    v++;
    it++;
    ICore::Sprite pac188;
    pac188.pixelPosition = {it->first,it->second};
    pac188.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac188);
    v++;
    it++;
    ICore::Sprite pac189;
    pac189.pixelPosition = {it->first,it->second};
    pac189.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac189);
    v++;
    it++;
    ICore::Sprite pac190;
    pac190.pixelPosition = {it->first,it->second};
    pac190.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac190);
    v++;
    it++;
    ICore::Sprite pac191;
    pac191.pixelPosition = {it->first,it->second};
    pac191.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac191);
    v++;
    it++;
    ICore::Sprite pac192;
    pac192.pixelPosition = {it->first,it->second};
    pac192.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac192);
    v++;
    it++;
    ICore::Sprite pac193;
    pac193.pixelPosition = {it->first,it->second};
    pac193.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac193);
    v++;
    it++;
    ICore::Sprite pac194;
    pac194.pixelPosition = {it->first,it->second};
    pac194.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac194);
    v++;
    it++;
    ICore::Sprite pac195;
    pac195.pixelPosition = {it->first,it->second};
    pac195.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac195);
    v++;
    it++;
    ICore::Sprite pac196;
    pac196.pixelPosition = {it->first,it->second};
    pac196.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac196);
    v++;
    it++;
    ICore::Sprite pac197;
    pac197.pixelPosition = {it->first,it->second};
    pac197.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac197);
    v++;
    it++;
    ICore::Sprite pac198;
    pac198.pixelPosition = {it->first,it->second};
    pac198.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac198);
    v++;
    it++;
    ICore::Sprite pac199;
    pac199.pixelPosition = {it->first,it->second};
    pac199.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac199);
    v++;
    it++;
    ICore::Sprite pac200;
    pac200.pixelPosition = {it->first,it->second};
    pac200.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac200);
    v++;
    it++;
    ICore::Sprite pac201;
    pac201.pixelPosition = {it->first,it->second};
    pac201.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac201);
    v++;
    it++;
    ICore::Sprite pac202;
    pac202.pixelPosition = {it->first,it->second};
    pac202.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac202);
    v++;
    it++;
    ICore::Sprite pac203;
    pac203.pixelPosition = {it->first,it->second};
    pac203.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac203);
    v++;
    it++;
    ICore::Sprite pac204;
    pac204.pixelPosition = {it->first,it->second};
    pac204.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac204);
    v++;
    it++;
    ICore::Sprite pac205;
    pac205.pixelPosition = {it->first,it->second};
    pac205.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac205);
    v++;
    it++;
    ICore::Sprite pac206;
    pac206.pixelPosition = {it->first,it->second};
    pac206.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac206);
    v++;
    it++;
    ICore::Sprite pac207;
    pac207.pixelPosition = {it->first,it->second};
    pac207.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac207);
    v++;
    it++;
    ICore::Sprite pac208;
    pac208.pixelPosition = {it->first,it->second};
    pac208.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac208);
    v++;
    it++;
    ICore::Sprite pac209;
    pac209.pixelPosition = {it->first,it->second};
    pac209.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac209);
    v++;
    it++;
    ICore::Sprite pac210;
    pac210.pixelPosition = {it->first,it->second};
    pac210.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac210);
    v++;
    it++;
    ICore::Sprite pac211;
    pac211.pixelPosition = {it->first,it->second};
    pac211.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac211);
    v++;
    it++;
    ICore::Sprite pac212;
    pac212.pixelPosition = {it->first,it->second};
    pac212.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac212);
    v++;
    it++;
    ICore::Sprite pac213;
    pac213.pixelPosition = {it->first,it->second};
    pac213.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac213);
    v++;
    it++;
    ICore::Sprite pac214;
    pac214.pixelPosition = {it->first,it->second};
    pac214.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac214);
    v++;
    it++;
    ICore::Sprite pac215;
    pac215.pixelPosition = {it->first,it->second};
    pac215.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac215);
    v++;
    it++;
    ICore::Sprite pac216;
    pac216.pixelPosition = {it->first,it->second};
    pac216.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac216);
    v++;
    it++;
    ICore::Sprite pac217;
    pac217.pixelPosition = {it->first,it->second};
    pac217.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac217);
    v++;
    it++;
    ICore::Sprite pac218;
    pac218.pixelPosition = {it->first,it->second};
    pac218.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac218);
    v++;
    it++;
    ICore::Sprite pac219;
    pac219.pixelPosition = {it->first,it->second};
    pac219.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac219);
    v++;
    it++;
    ICore::Sprite pac220;
    pac220.pixelPosition = {it->first,it->second};
    pac220.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac220);
    v++;
    it++;
    ICore::Sprite pac221;
    pac221.pixelPosition = {it->first,it->second};
    pac221.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac221);
    v++;
    it++;
    ICore::Sprite pac222;
    pac222.pixelPosition = {it->first,it->second};
    pac222.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac222);
    v++;
    it++;
    ICore::Sprite pac223;
    pac223.pixelPosition = {it->first,it->second};
    pac223.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac223);
    v++;
    it++;
    ICore::Sprite pac224;
    pac224.pixelPosition = {it->first,it->second};
    pac224.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac224);
    v++;
    it++;
    ICore::Sprite pac225;
    pac225.pixelPosition = {it->first,it->second};
    pac225.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac225);
    v++;
    it++;
    ICore::Sprite pac226;
    pac226.pixelPosition = {it->first,it->second};
    pac226.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac226);
    v++;
    it++;
    ICore::Sprite pac227;
    pac227.pixelPosition = {it->first,it->second};
    pac227.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac227);
    v++;
    it++;
    ICore::Sprite pac228;
    pac228.pixelPosition = {it->first,it->second};
    pac228.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac228);
    v++;
    it++;
    ICore::Sprite pac229;
    pac229.pixelPosition = {it->first,it->second};
    pac229.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac229);
    v++;
    it++;
    ICore::Sprite pac230;
    pac230.pixelPosition = {it->first,it->second};
    pac230.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac230);
    v++;
    it++;
    ICore::Sprite pac231;
    pac231.pixelPosition = {it->first,it->second};
    pac231.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac231);
    v++;
    it++;
    ICore::Sprite pac232;
    pac232.pixelPosition = {it->first,it->second};
    pac232.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac232);
    v++;
    it++;
    ICore::Sprite pac233;
    pac233.pixelPosition = {it->first,it->second};
    pac233.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac233);
    v++;
    it++;
    ICore::Sprite pac234;
    pac234.pixelPosition = {it->first,it->second};
    pac234.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac234);
    v++;
    it++;
    ICore::Sprite pac235;
    pac235.pixelPosition = {it->first,it->second};
    pac235.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac235);
    v++;
    it++;
    ICore::Sprite pac236;
    pac236.pixelPosition = {it->first,it->second};
    pac236.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac236);
    v++;
    it++;
    ICore::Sprite pac237;
    pac237.pixelPosition = {it->first,it->second};
    pac237.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac237);
    v++;
    it++;
    ICore::Sprite pac238;
    pac238.pixelPosition = {it->first,it->second};
    pac238.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac238);
    v++;
    it++;
    ICore::Sprite pac239;
    pac239.pixelPosition = {it->first,it->second};
    pac239.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac239);
    v++;
    it++;
    ICore::Sprite pac240;
    pac240.pixelPosition = {it->first,it->second};
    pac240.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac240);
    v++;
    it++;
    ICore::Sprite pac241;
    pac241.pixelPosition = {it->first,it->second};
    pac241.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac241);
    v++;
    it++;
    ICore::Sprite pac242;
    pac242.pixelPosition = {it->first,it->second};
    pac242.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac242);
    v++;
    it++;
    ICore::Sprite pac243;
    pac243.pixelPosition = {it->first,it->second};
    pac243.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac243);
    v++;
    it++;
    ICore::Sprite pac244;
    pac244.pixelPosition = {it->first,it->second};
    pac244.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac244);
    v++;
    it++;
    ICore::Sprite pac245;
    pac245.pixelPosition = {it->first,it->second};
    pac245.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac245);
    v++;
    it++;
    ICore::Sprite pac246;
    pac246.pixelPosition = {it->first,it->second};
    pac246.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac246);
    v++;
    it++;
    ICore::Sprite pac247;
    pac247.pixelPosition = {it->first,it->second};
    pac247.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac247);
    v++;
    it++;
    ICore::Sprite pac248;
    pac248.pixelPosition = {it->first,it->second};
    pac248.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac248);
    v++;
    it++;
    ICore::Sprite pac249;
    pac249.pixelPosition = {it->first,it->second};
    pac249.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac249);
    v++;
    it++;
    ICore::Sprite pac250;
    pac250.pixelPosition = {it->first,it->second};
    pac250.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac250);
    v++;
    it++;
    ICore::Sprite pac251;
    pac251.pixelPosition = {it->first,it->second};
    pac251.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac251);
    v++;
    it++;
    ICore::Sprite pac252;
    pac252.pixelPosition = {it->first,it->second};
    pac252.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac252);
    v++;
    it++;
    ICore::Sprite pac253;
    pac253.pixelPosition = {it->first,it->second};
    pac253.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac253);
    v++;
    it++;
    ICore::Sprite pac254;
    pac254.pixelPosition = {it->first,it->second};
    pac254.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac254);
    v++;
    it++;
    ICore::Sprite pac255;
    pac255.pixelPosition = {it->first,it->second};
    pac255.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac255);
    v++;
    it++;
    ICore::Sprite pac256;
    pac256.pixelPosition = {it->first,it->second};
    pac256.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac256);
    v++;
    it++;
    ICore::Sprite pac257;
    pac257.pixelPosition = {it->first,it->second};
    pac257.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac257);
    v++;
    it++;
    ICore::Sprite pac258;
    pac258.pixelPosition = {it->first,it->second};
    pac258.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac258);
    v++;
    it++;
    ICore::Sprite pac259;
    pac259.pixelPosition = {it->first,it->second};
    pac259.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac259);
    v++;
    it++;
    ICore::Sprite pac260;
    pac260.pixelPosition = {it->first,it->second};
    pac260.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac260);
    v++;
    it++;
    ICore::Sprite pac261;
    pac261.pixelPosition = {it->first,it->second};
    pac261.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac261);
    v++;
    it++;
    ICore::Sprite pac262;
    pac262.pixelPosition = {it->first,it->second};
    pac262.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac262);
    v++;
    it++;
    ICore::Sprite pac263;
    pac263.pixelPosition = {it->first,it->second};
    pac263.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac263);
    v++;
    it++;
    ICore::Sprite pac264;
    pac264.pixelPosition = {it->first,it->second};
    pac264.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac264);
    v++;
    it++;
    ICore::Sprite pac265;
    pac265.pixelPosition = {it->first,it->second};
    pac265.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac265);
    v++;
    it++;
    ICore::Sprite pac266;
    pac266.pixelPosition = {it->first,it->second};
    pac266.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac266);
    v++;
    it++;
    ICore::Sprite pac267;
    pac267.pixelPosition = {it->first,it->second};
    pac267.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac267);
    v++;
    it++;
    ICore::Sprite pac268;
    pac268.pixelPosition = {it->first,it->second};
    pac268.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac268);
    v++;
    it++;
    ICore::Sprite pac269;
    pac269.pixelPosition = {it->first,it->second};
    pac269.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac269);
    v++;
    it++;
    ICore::Sprite pac270;
    pac270.pixelPosition = {it->first,it->second};
    pac270.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac270);
    v++;
    it++;
    ICore::Sprite pac271;
    pac271.pixelPosition = {it->first,it->second};
    pac271.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac271);
    v++;
    it++;
    ICore::Sprite pac272;
    pac272.pixelPosition = {it->first,it->second};
    pac272.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac272);
    v++;
    it++;
    ICore::Sprite pac273;
    pac273.pixelPosition = {it->first,it->second};
    pac273.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac273);
    v++;
    it++;
    ICore::Sprite pac274;
    pac274.pixelPosition = {it->first,it->second};
    pac274.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac274);
    v++;
    it++;
    ICore::Sprite pac275;
    pac275.pixelPosition = {it->first,it->second};
    pac275.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac275);
    v++;
    it++;
    ICore::Sprite pac276;
    pac276.pixelPosition = {it->first,it->second};
    pac276.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac276);
    v++;
    it++;
    ICore::Sprite pac277;
    pac277.pixelPosition = {it->first,it->second};
    pac277.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac277);
    v++;
    it++;
    ICore::Sprite pac278;
    pac278.pixelPosition = {it->first,it->second};
    pac278.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac278);
    v++;
    it++;
    ICore::Sprite pac279;
    pac279.pixelPosition = {it->first,it->second};
    pac279.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac279);
    v++;
    it++;
    ICore::Sprite pac280;
    pac280.pixelPosition = {it->first,it->second};
    pac280.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac280);
    v++;
    it++;
    ICore::Sprite pac281;
    pac281.pixelPosition = {it->first,it->second};
    pac281.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac281);
    v++;
    it++;
    ICore::Sprite pac282;
    pac282.pixelPosition = {it->first,it->second};
    pac282.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac282);
    v++;
    it++;
    ICore::Sprite pac283;
    pac283.pixelPosition = {it->first,it->second};
    pac283.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac283);
    v++;
    it++;
    ICore::Sprite pac284;
    pac284.pixelPosition = {it->first,it->second};
    pac284.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac284);
    v++;
    it++;
    ICore::Sprite pac285;
    pac285.pixelPosition = {it->first,it->second};
    pac285.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac285);
    v++;
    it++;
    ICore::Sprite pac286;
    pac286.pixelPosition = {it->first,it->second};
    pac286.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac286);
    v++;
    it++;
    ICore::Sprite pac287;
    pac287.pixelPosition = {it->first,it->second};
    pac287.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac287);
    v++;
    it++;
    ICore::Sprite pac288;
    pac288.pixelPosition = {it->first,it->second};
    pac288.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac288);
    v++;
    it++;
    ICore::Sprite pac289;
    pac289.pixelPosition = {it->first,it->second};
    pac289.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac289);
    v++;
    it++;
    ICore::Sprite pac290;
    pac290.pixelPosition = {it->first,it->second};
    pac290.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac290);
    v++;
    it++;
    ICore::Sprite pac291;
    pac291.pixelPosition = {it->first,it->second};
    pac291.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac291);
    v++;
    it++;
    ICore::Sprite pac292;
    pac292.pixelPosition = {it->first,it->second};
    pac292.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac292);
    v++;
    it++;
    ICore::Sprite pac293;
    pac293.pixelPosition = {it->first,it->second};
    pac293.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac293);
    v++;
    it++;
    ICore::Sprite pac294;
    pac294.pixelPosition = {it->first,it->second};
    pac294.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac294);
    v++;
    it++;
    ICore::Sprite pac295;
    pac295.pixelPosition = {it->first,it->second};
    pac295.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac295);
    v++;
    it++;
    ICore::Sprite pac296;
    pac296.pixelPosition = {it->first,it->second};
    pac296.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac296);
    v++;
    it++;
    ICore::Sprite pac297;
    pac297.pixelPosition = {it->first,it->second};
    pac297.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac297);
    v++;
    it++;
    ICore::Sprite pac298;
    pac298.pixelPosition = {it->first,it->second};
    pac298.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac298);
    v++;
    it++;
    ICore::Sprite pac299;
    pac299.pixelPosition = {it->first,it->second};
    pac299.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac299);
    v++;
    it++;
    ICore::Sprite pac300;
    pac300.pixelPosition = {it->first,it->second};
    pac300.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac300);
    v++;
    it++;
    ICore::Sprite pac301;
    pac301.pixelPosition = {it->first,it->second};
    pac301.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac301);
    v++;
    it++;
    ICore::Sprite pac302;
    pac302.pixelPosition = {it->first,it->second};
    pac302.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac302);
    v++;
    it++;
    ICore::Sprite pac303;
    pac303.pixelPosition = {it->first,it->second};
    pac303.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac303);
    v++;
    it++;
    ICore::Sprite pac304;
    pac304.pixelPosition = {it->first,it->second};
    pac304.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac304);
    v++;
    it++;
    ICore::Sprite pac305;
    pac305.pixelPosition = {it->first,it->second};
    pac305.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac305);
    v++;
    it++;
    ICore::Sprite pac306;
    pac306.pixelPosition = {it->first,it->second};
    pac306.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac306);
    v++;
    it++;
    ICore::Sprite pac307;
    pac307.pixelPosition = {it->first,it->second};
    pac307.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac307);
    v++;
    it++;
    ICore::Sprite pac308;
    pac308.pixelPosition = {it->first,it->second};
    pac308.texture = _pacgum;
    if (*v == 1)
        _core->renderSprite(pac308);
}

void Pacman::random_wall4()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    
    wall0.pixelPosition = {16*33,16*28};
    wall0.texture = _endleft;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*34,16*13};
    wall1.texture = _wallh;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*34,16*17};
    wall2.texture = _wallh;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*34,16*20};
    wall3.texture = _wallh;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*34,16*28};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*34,16*22};
    wall5.texture = _cornerleft;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*34,16*23};
    wall6.texture = _wallv;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*34,16*24};
    wall7.texture = _wallv;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*34,16*25};
    wall8.texture = _wallv;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*34,16*26};
    wall9.texture = _cornerleftd;
    _core->renderSprite(wall9);
    
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    
    wall10.pixelPosition = {16*35,16*8};
    wall10.texture = _cornerleft;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*35,16*9};
    wall11.texture = _wallv;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*35,16*10};
    wall12.texture = _wallv;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*35,16*11};
    wall13.texture = _cornerleftd;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*35,16*13};
    wall14.texture = _wallh;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*35,16*15};
    wall15.texture = _endleft;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*35,16*17};
    wall16.texture = _wallh;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*35,16*20};
    wall17.texture = _wallh;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*35,16*22};
    wall18.texture = _wallh;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*35,16*26};
    wall19.texture = _wallh;
    _core->renderSprite(wall19);
    
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    ICore::Sprite wall26;
    ICore::Sprite wall27;
    ICore::Sprite wall28;
    ICore::Sprite wall29;
    
    wall20.pixelPosition = {16*35,16*28};
    wall20.texture = _wallh;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*36,16*8};
    wall21.texture = _cornerright;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*36,16*9};
    wall22.texture = _wallv;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*36,16*10};
    wall23.texture = _wallv;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*36,16*11};
    wall24.texture = _cornerrightd;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*36,16*13};
    wall25.texture = _endright;
    _core->renderSprite(wall25);
    wall26.pixelPosition = {16*36,16*15};
    wall26.texture = _endright;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*36,16*17};
    wall27.texture = _cornerright;
    _core->renderSprite(wall27);
    wall28.pixelPosition = {16*36,16*18};
    wall28.texture = _wallv;
    _core->renderSprite(wall28);
    wall29.pixelPosition = {16*36,16*19};
    wall29.texture = _wallv;
    _core->renderSprite(wall29);
    
    ICore::Sprite wall30;
    ICore::Sprite wall31;
    ICore::Sprite wall32;
    ICore::Sprite wall33;
    ICore::Sprite wall34;
    ICore::Sprite wall35;
    ICore::Sprite wall36;
    ICore::Sprite wall37;
    ICore::Sprite wall38;
    ICore::Sprite wall39;
    
    wall30.pixelPosition = {16*36,16*20};
    wall30.texture = _cornerrightd;
    _core->renderSprite(wall30);
    wall31.pixelPosition = {16*36,16*22};
    wall31.texture = _cornerright;
    _core->renderSprite(wall31);
    wall32.pixelPosition = {16*36,16*23};
    wall32.texture = _wallv;
    _core->renderSprite(wall32);
    wall33.pixelPosition = {16*36,16*24};
    wall33.texture = _wallv;
    _core->renderSprite(wall33);
    wall34.pixelPosition = {16*36,16*25};
    wall34.texture = _wallv;
    _core->renderSprite(wall34);
    wall35.pixelPosition = {16*36,16*26};
    wall35.texture = _cornerrightd;
    _core->renderSprite(wall35);
    wall36.pixelPosition = {16*36,16*28};
    wall36.texture = _wallh;
    _core->renderSprite(wall36);
    wall37.pixelPosition = {16*37,16*28};
    wall37.texture = _wallh;
    _core->renderSprite(wall37);
    wall38.pixelPosition = {16*38,16*8};
    wall38.texture = _endup;
    _core->renderSprite(wall38);
    wall39.pixelPosition = {16*38,16*9};
    wall39.texture = _wallv;
    _core->renderSprite(wall39);
    
    ICore::Sprite wall40;
    ICore::Sprite wall41;
    ICore::Sprite wall42;
    ICore::Sprite wall43;
    ICore::Sprite wall44;
    ICore::Sprite wall45;
    ICore::Sprite wall46;
    ICore::Sprite wall47;
    ICore::Sprite wall48;
    ICore::Sprite wall49;
    
    wall40.pixelPosition = {16*38,16*10};
    wall40.texture = _wallv;
    _core->renderSprite(wall40);
    wall41.pixelPosition = {16*38,16*11};
    wall41.texture = _enddown;
    _core->renderSprite(wall41);
    wall42.pixelPosition = {16*38,16*13};
    wall42.texture = _endup;
    _core->renderSprite(wall42);
    wall43.pixelPosition = {16*38,16*14};
    wall43.texture = _wallv;
    _core->renderSprite(wall43);
    wall44.pixelPosition = {16*38,16*15};
    wall44.texture = _enddown;
    _core->renderSprite(wall44);
    wall45.pixelPosition = {16*38,16*17};
    wall45.texture = _endleft;
    _core->renderSprite(wall45);
    wall46.pixelPosition = {16*38,16*19};
    wall46.texture = _endleft;
    _core->renderSprite(wall46);
    wall47.pixelPosition = {16*38,16*21};
    wall47.texture = _endup;
    _core->renderSprite(wall47);
    wall48.pixelPosition = {16*38,16*22};
    wall48.texture = _enddown;
    _core->renderSprite(wall48);
    wall49.pixelPosition = {16*38,16*24};
    wall49.texture = _endup;
    _core->renderSprite(wall49);
    
    ICore::Sprite wall50;
    ICore::Sprite wall51;
    ICore::Sprite wall52;
    ICore::Sprite wall53;
    ICore::Sprite wall54;
    ICore::Sprite wall55;
    
    wall50.pixelPosition = {16*38,16*25};
    wall50.texture = _wallv;
    _core->renderSprite(wall50);
    wall51.pixelPosition = {16*38,16*26};
    wall51.texture = _wallv;
    _core->renderSprite(wall51);
    wall52.pixelPosition = {16*38,16*27};
    wall52.texture = _wallv;
    _core->renderSprite(wall52);
    wall53.pixelPosition = {16*38,16*28};
    wall53.texture = _cornerrightd;
    _core->renderSprite(wall53);
    wall54.pixelPosition = {16*39,16*17};
    wall54.texture = _wallh;
    _core->renderSprite(wall54);
    wall55.pixelPosition = {16*39,16*19};
    wall55.texture = _wallh;
    _core->renderSprite(wall55);
}

void Pacman::random_wall3()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    
    wall0.pixelPosition = {16*17,16*24};
    wall0.texture = _cornerleftd;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*17,16*26};
    wall1.texture = _cornerleft;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*17,16*27};
    wall2.texture = _wallv;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*17,16*28};
    wall3.texture = _cornerleftd;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*18,16*21};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*18,16*24};
    wall5.texture = _wallh;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*18,16*26};
    wall6.texture = _wallh;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*18,16*28};
    wall7.texture = _wallh;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*19,16*8};
    wall8.texture = _cornerleft;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*19,16*9};
    wall9.texture = _cornerleftd;
    _core->renderSprite(wall9);
    
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    
    wall10.pixelPosition = {16*19,16*11};
    wall10.texture = _cornerleft;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*19,16*12};
    wall11.texture = _wallv;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*19,16*13};
    wall12.texture = _wallv;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*19,16*14};
    wall13.texture = _wallv;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*19,16*15};
    wall14.texture = _cornerleftd;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*19,16*17};
    wall15.texture = _cornerleft;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*19,16*18};
    wall16.texture = _wallv;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*19,16*19};
    wall17.texture = _wallv;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*19,16*20};
    wall18.texture = _wallv;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*19,16*21};
    wall19.texture = _Tdown;
    _core->renderSprite(wall19);
    
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    ICore::Sprite wall26;
    ICore::Sprite wall27;
    ICore::Sprite wall28;
    ICore::Sprite wall29;
    
    wall20.pixelPosition = {16*19,16*24};
    wall20.texture = _wallh;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*19,16*26};
    wall21.texture = _wallh;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*19,16*28};
    wall22.texture = _wallh;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*20,16*8};
    wall23.texture = _cornerright;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*20,16*9};
    wall24.texture = _cornerrightd;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*20,16*21};
    wall25.texture = _Tright;
    _core->renderSprite(wall25);
    wall26.pixelPosition = {16*20,16*22};
    wall26.texture = _wallv;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*20,16*23};
    wall27.texture = _wallv;
    _core->renderSprite(wall27);
    wall28.pixelPosition = {16*20,16*24};
    wall28.texture = _cornerrightd;
    _core->renderSprite(wall28);
    wall29.pixelPosition = {16*20,16*26};
    wall29.texture = _cornerright;
    _core->renderSprite(wall29);
    
    ICore::Sprite wall30;
    ICore::Sprite wall31;
    ICore::Sprite wall32;
    ICore::Sprite wall33;
    ICore::Sprite wall34;
    ICore::Sprite wall35;
    ICore::Sprite wall36;
    ICore::Sprite wall37;
    ICore::Sprite wall38;
    ICore::Sprite wall39;
    
    wall30.pixelPosition = {16*20,16*27};
    wall30.texture = _wallv;
    _core->renderSprite(wall30);
    wall31.pixelPosition = {16*20,16*28};
    wall31.texture = _cornerrightd;
    _core->renderSprite(wall31);
    wall32.pixelPosition = {16*22,16*8};
    wall32.texture = _cornerleft;
    _core->renderSprite(wall32);
    wall33.pixelPosition = {16*22,16*9};
    wall33.texture = _cornerleftd;
    _core->renderSprite(wall33);
    wall34.pixelPosition = {16*23,16*8};
    wall34.texture = _cornerright;
    _core->renderSprite(wall34);
    wall35.pixelPosition = {16*23,16*9};
    wall35.texture = _cornerrightd;
    _core->renderSprite(wall35);
    wall36.pixelPosition = {16*27,16*8};
    wall36.texture = _cornerleft;
    _core->renderSprite(wall36);
    wall37.pixelPosition = {16*27,16*9};
    wall37.texture = _cornerleftd;
    _core->renderSprite(wall37);
    wall38.pixelPosition = {16*28,16*8};
    wall38.texture = _wallh;
    _core->renderSprite(wall38);
    wall39.pixelPosition = {16*28,16*9};
    wall39.texture = _wallh;
    _core->renderSprite(wall39);
    
    ICore::Sprite wall40;
    ICore::Sprite wall41;
    ICore::Sprite wall42;
    ICore::Sprite wall43;
    ICore::Sprite wall44;
    ICore::Sprite wall45;
    ICore::Sprite wall46;
    ICore::Sprite wall47;
    ICore::Sprite wall48;
    ICore::Sprite wall49;
    
    wall40.pixelPosition = {16*29,16*8};
    wall40.texture = _wallh;
    _core->renderSprite(wall40);
    wall41.pixelPosition = {16*29,16*9};
    wall41.texture = _wallh;
    _core->renderSprite(wall41);
    wall42.pixelPosition = {16*29,16*28};
    wall42.texture = _wallh;
    _core->renderSprite(wall42);
    wall43.pixelPosition = {16*30,16*8};
    wall43.texture = _wallh;
    _core->renderSprite(wall43);
    wall44.pixelPosition = {16*30,16*9};
    wall44.texture = _wallh;
    _core->renderSprite(wall44);
    wall45.pixelPosition = {16*30,16*17};
    wall45.texture = _cornerleft;
    _core->renderSprite(wall45);
    wall46.pixelPosition = {16*30,16*18};
    wall46.texture = _wallv;
    _core->renderSprite(wall46);
    wall47.pixelPosition = {16*30,16*19};
    wall47.texture = _wallv;
    _core->renderSprite(wall47);
    wall48.pixelPosition = {16*30,16*20};
    wall48.texture = _wallv;
    _core->renderSprite(wall48);
    wall49.pixelPosition = {16*30,16*21};
    wall49.texture = _wallv;
    _core->renderSprite(wall49);
    
    ICore::Sprite wall50;
    ICore::Sprite wall51;
    ICore::Sprite wall52;
    ICore::Sprite wall53;
    ICore::Sprite wall54;
    ICore::Sprite wall55;
    ICore::Sprite wall56;
    ICore::Sprite wall57;
    ICore::Sprite wall58;
    ICore::Sprite wall59;
    
    wall50.pixelPosition = {16*30,16*22};
    wall50.texture = _wallv;
    _core->renderSprite(wall50);
    wall51.pixelPosition = {16*30,16*23};
    wall51.texture = _wallv;
    _core->renderSprite(wall51);
    wall52.pixelPosition = {16*30,16*24};
    wall52.texture = _wallv;
    _core->renderSprite(wall52);
    wall53.pixelPosition = {16*30,16*25};
    wall53.texture = _wallv;
    _core->renderSprite(wall53);
    wall54.pixelPosition = {16*30,16*26};
    wall54.texture = _cornerleftd;
    _core->renderSprite(wall54);
    wall55.pixelPosition = {16*30,16*28};
    wall55.texture = _wallh;
    _core->renderSprite(wall55);
    wall56.pixelPosition = {16*31,16*8};
    wall56.texture = _wallh;
    _core->renderSprite(wall56);
    wall57.pixelPosition = {16*31,16*9};
    wall57.texture = _wallh;
    _core->renderSprite(wall57);
    wall58.pixelPosition = {16*31,16*11};
    wall58.texture = _wallh;
    _core->renderSprite(wall58);
    wall59.pixelPosition = {16*31,16*17};
    wall59.texture = _wallh;
    _core->renderSprite(wall59);
    
    ICore::Sprite wall60;
    ICore::Sprite wall61;
    ICore::Sprite wall62;
    ICore::Sprite wall63;
    ICore::Sprite wall64;
    ICore::Sprite wall65;
    ICore::Sprite wall66;
    ICore::Sprite wall67;
    ICore::Sprite wall68;
    ICore::Sprite wall69;
    
    wall60.pixelPosition = {16*31,16*26};
    wall60.texture = _wallh;
    _core->renderSprite(wall60);
    wall61.pixelPosition = {16*31,16*28};
    wall61.texture = _endright;
    _core->renderSprite(wall61);
    wall62.pixelPosition = {16*32,16*8};
    wall62.texture = _wallh;
    _core->renderSprite(wall62);
    wall63.pixelPosition = {16*32,16*9};
    wall63.texture = _wallh;
    _core->renderSprite(wall63);
    wall64.pixelPosition = {16*32,16*11};
    wall64.texture = _wallh;
    _core->renderSprite(wall64);
    wall65.pixelPosition = {16*32,16*13};
    wall65.texture = _endleft;
    _core->renderSprite(wall65);
    wall66.pixelPosition = {16*32,16*17};
    wall66.texture = _wallh;
    _core->renderSprite(wall66);
    wall67.pixelPosition = {16*32,16*20};
    wall67.texture = _cornerleft;
    _core->renderSprite(wall67);
    wall68.pixelPosition = {16*32,16*21};
    wall68.texture = _wallv;
    _core->renderSprite(wall68);
    wall69.pixelPosition = {16*32,16*22};
    wall69.texture = _wallv;
    _core->renderSprite(wall69);
    
    ICore::Sprite wall70;
    ICore::Sprite wall71;
    ICore::Sprite wall72;
    ICore::Sprite wall73;
    ICore::Sprite wall74;
    ICore::Sprite wall75;
    ICore::Sprite wall76;
    ICore::Sprite wall77;
    ICore::Sprite wall78;
    ICore::Sprite wall79;
    
    wall70.pixelPosition = {16*32,16*23};
    wall70.texture = _wallv;
    _core->renderSprite(wall70);
    wall71.pixelPosition = {16*32,16*24};
    wall71.texture = _wallv;
    _core->renderSprite(wall71);
    wall72.pixelPosition = {16*32,16*25};
    wall72.texture = _wallv;
    _core->renderSprite(wall72);
    wall73.pixelPosition = {16*32,16*26};
    wall73.texture = _cornerrightd;
    _core->renderSprite(wall73);
    wall74.pixelPosition = {16*33,16*8};
    wall74.texture = _cornerright;
    _core->renderSprite(wall74);
    wall75.pixelPosition = {16*33,16*9};
    wall75.texture = _cornerrightd;
    _core->renderSprite(wall75);
    wall76.pixelPosition = {16*33,16*11};
    wall76.texture = _endright;
    _core->renderSprite(wall76);
    wall77.pixelPosition = {16*33,16*13};
    wall77.texture = _wallh;
    _core->renderSprite(wall77);
    wall78.pixelPosition = {16*33,16*17};
    wall78.texture = _wallh;
    _core->renderSprite(wall78);
    wall79.pixelPosition = {16*33,16*20};
    wall79.texture = _wallh;
    _core->renderSprite(wall79);
}

void Pacman::random_wall2()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    
    wall0.pixelPosition = {16*31,16*15};
    wall0.texture = _wallh;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*32,16*15};
    wall1.texture = _wallh;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*33,16*15};
    wall2.texture = _endright;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*20,16*17};
    wall3.texture = _cornerright;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*20,16*18};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*20,16*19};
    wall5.texture = _wallv;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*20,16*20};
    wall6.texture = _wallv;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*22,16*22};
    wall7.texture = _endleft;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*30,16*14};
    wall8.texture = _wallv;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*30,16*15};
    wall9.texture = _cornerleftd;
    _core->renderSprite(wall9);
    
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    
    wall10.pixelPosition = {16*11,16*7};
    wall10.texture = _wallv;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*11,16*8};
    wall11.texture = _wallv;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*11,16*9};
    wall12.texture = _wallv;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*11,16*10};
    wall13.texture = _wallv;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*11,16*11};
    wall14.texture = _wallv;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*11,16*12};
    wall15.texture = _wallv;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*11,16*13};
    wall16.texture = _wallv;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*11,16*14};
    wall17.texture = _wallv;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*11,16*15};
    wall18.texture = _wallv;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*11,16*16};
    wall19.texture = _wallv;
    _core->renderSprite(wall19);
    
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    ICore::Sprite wall26;
    ICore::Sprite wall27;
    ICore::Sprite wall28;
    ICore::Sprite wall29;
    
    wall20.pixelPosition = {16*11,16*17};
    wall20.texture = _cornerrightd;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*11,16*19};
    wall21.texture = _endright;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*12,16*21};
    wall22.texture = _cornerleft;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*12,16*22};
    wall23.texture = _wallv;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*12,16*23};
    wall24.texture = _wallv;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*12,16*24};
    wall25.texture = _cornerleftd;
    _core->renderSprite(wall25);
    wall26.pixelPosition = {16*12,16*26};
    wall26.texture = _cornerleft;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*12,16*27};
    wall27.texture = _wallv;
    _core->renderSprite(wall27);
    wall28.pixelPosition = {16*12,16*28};
    wall28.texture = _cornerleftd;
    _core->renderSprite(wall28);
    wall29.pixelPosition = {16*13,16*8};
    wall29.texture = _endup;
    _core->renderSprite(wall29);
    
    ICore::Sprite wall30;
    ICore::Sprite wall31;
    ICore::Sprite wall32;
    ICore::Sprite wall33;
    ICore::Sprite wall34;
    ICore::Sprite wall35;
    ICore::Sprite wall36;
    ICore::Sprite wall37;
    ICore::Sprite wall38;
    ICore::Sprite wall39;
    
    wall30.pixelPosition = {16*13,16*9};
    wall30.texture = _wallv;
    _core->renderSprite(wall30);
    wall31.pixelPosition = {16*13,16*10};
    wall31.texture = _wallv;
    _core->renderSprite(wall31);
    wall32.pixelPosition = {16*13,16*11};
    wall32.texture = _wallv;
    _core->renderSprite(wall32);
    wall33.pixelPosition = {16*13,16*12};
    wall33.texture = _enddown;
    _core->renderSprite(wall33);
    wall34.pixelPosition = {16*13,16*14};
    wall34.texture = _endup;
    _core->renderSprite(wall34);
    wall35.pixelPosition = {16*13,16*15};
    wall35.texture = _wallv;
    _core->renderSprite(wall35);
    wall36.pixelPosition = {16*13,16*16};
    wall36.texture = _wallv;
    _core->renderSprite(wall36);
    wall37.pixelPosition = {16*13,16*17};
    wall37.texture = _wallv;
    _core->renderSprite(wall37);
    wall38.pixelPosition = {16*13,16*18};
    wall38.texture = _wallv;
    _core->renderSprite(wall38);
    wall39.pixelPosition = {16*13,16*19};
    wall39.texture = _enddown;
    _core->renderSprite(wall39);
    
    ICore::Sprite wall40;
    ICore::Sprite wall41;
    ICore::Sprite wall42;
    ICore::Sprite wall43;
    ICore::Sprite wall44;
    ICore::Sprite wall45;
    ICore::Sprite wall46;
    ICore::Sprite wall47;
    ICore::Sprite wall48;
    ICore::Sprite wall49;
    
    wall40.pixelPosition = {16*13,16*21};
    wall40.texture = _wallh;
    _core->renderSprite(wall40);
    wall41.pixelPosition = {16*13,16*24};
    wall41.texture = _wallh;
    _core->renderSprite(wall41);
    wall42.pixelPosition = {16*13,16*26};
    wall42.texture = _wallh;
    _core->renderSprite(wall42);
    wall43.pixelPosition = {16*13,16*28};
    wall43.texture = _wallh;
    _core->renderSprite(wall43);
    wall44.pixelPosition = {16*14,16*21};
    wall44.texture = _wallh;
    _core->renderSprite(wall44);
    wall45.pixelPosition = {16*14,16*24};
    wall45.texture = _wallh;
    _core->renderSprite(wall45);
    wall46.pixelPosition = {16*14,16*26};
    wall46.texture = _wallh;
    _core->renderSprite(wall46);
    wall47.pixelPosition = {16*14,16*28};
    wall47.texture = _wallh;
    _core->renderSprite(wall47);
    wall48.pixelPosition = {16*15,16*8};
    wall48.texture = _endup;
    _core->renderSprite(wall48);
    wall49.pixelPosition = {16*15,16*9};
    wall49.texture = _wallv;
    _core->renderSprite(wall49);
    
    ICore::Sprite wall50;
    ICore::Sprite wall51;
    ICore::Sprite wall52;
    ICore::Sprite wall53;
    ICore::Sprite wall54;
    ICore::Sprite wall55;
    ICore::Sprite wall56;
    ICore::Sprite wall57;
    ICore::Sprite wall58;
    ICore::Sprite wall59;
    
    wall50.pixelPosition = {16*15,16*10};
    wall50.texture = _enddown;
    _core->renderSprite(wall50);
    wall51.pixelPosition = {16*15,16*12};
    wall51.texture = _endup;
    _core->renderSprite(wall51);
    wall52.pixelPosition = {16*15,16*13};
    wall52.texture = _wallv;
    _core->renderSprite(wall52);
    wall53.pixelPosition = {16*15,16*14};
    wall53.texture = _wallv;
    _core->renderSprite(wall53);
    wall54.pixelPosition = {16*15,16*15};
    wall54.texture = _wallv;
    _core->renderSprite(wall54);
    wall55.pixelPosition = {16*15,16*16};
    wall55.texture = _wallv;
    _core->renderSprite(wall55);
    wall56.pixelPosition = {16*15,16*17};
    wall56.texture = _wallv;
    _core->renderSprite(wall56);
    wall57.pixelPosition = {16*15,16*18};
    wall57.texture = _wallv;
    _core->renderSprite(wall57);
    wall58.pixelPosition = {16*15,16*19};
    wall58.texture = _enddown;
    _core->renderSprite(wall58);
    wall59.pixelPosition = {16*15,16*21};
    wall59.texture = _cornerright;
    _core->renderSprite(wall59);
    
    ICore::Sprite wall60;
    ICore::Sprite wall61;
    ICore::Sprite wall62;
    ICore::Sprite wall63;
    ICore::Sprite wall64;
    ICore::Sprite wall65;
    ICore::Sprite wall66;
    ICore::Sprite wall67;
    ICore::Sprite wall68;
    ICore::Sprite wall69;
    
    wall60.pixelPosition = {16*15,16*22};
    wall60.texture = _wallv;
    _core->renderSprite(wall60);
    wall61.pixelPosition = {16*15,16*23};
    wall61.texture = _wallv;
    _core->renderSprite(wall61);
    wall62.pixelPosition = {16*15,16*24};
    wall62.texture = _cornerrightd;
    _core->renderSprite(wall62);
    wall63.pixelPosition = {16*15,16*26};
    wall63.texture = _cornerright;
    _core->renderSprite(wall63);
    wall64.pixelPosition = {16*15,16*27};
    wall64.texture = _wallv;
    _core->renderSprite(wall64);
    wall65.pixelPosition = {16*15,16*28};
    wall65.texture = _cornerrightd;
    _core->renderSprite(wall65);
    wall66.pixelPosition = {16*17,16*8};
    wall66.texture = _endup;
    _core->renderSprite(wall66);
    wall67.pixelPosition = {16*17,16*9};
    wall67.texture = _wallv;
    _core->renderSprite(wall67);
    wall68.pixelPosition = {16*17,16*10};
    wall68.texture = _wallv;
    _core->renderSprite(wall68);
    wall69.pixelPosition = {16*17,16*11};
    wall69.texture = _wallv;
    _core->renderSprite(wall69);
    
    ICore::Sprite wall70;
    ICore::Sprite wall71;
    ICore::Sprite wall72;
    ICore::Sprite wall73;
    ICore::Sprite wall74;
    ICore::Sprite wall75;
    ICore::Sprite wall76;
    ICore::Sprite wall77;
    ICore::Sprite wall78;
    ICore::Sprite wall79;
    
    wall70.pixelPosition = {16*17,16*12};
    wall70.texture = _wallv;
    _core->renderSprite(wall70);
    wall71.pixelPosition = {16*17,16*13};
    wall71.texture = _wallv;
    _core->renderSprite(wall71);
    wall72.pixelPosition = {16*17,16*14};
    wall72.texture = _enddown;
    _core->renderSprite(wall72);
    wall73.pixelPosition = {16*17,16*16};
    wall73.texture = _endup;
    _core->renderSprite(wall73);
    wall74.pixelPosition = {16*17,16*17};
    wall74.texture = _wallv;
    _core->renderSprite(wall74);
    wall75.pixelPosition = {16*17,16*18};
    wall75.texture = _wallv;
    _core->renderSprite(wall75);
    wall76.pixelPosition = {16*17,16*19};
    wall76.texture = _enddown;
    _core->renderSprite(wall76);
    wall77.pixelPosition = {16*17,16*21};
    wall77.texture = _cornerleft;
    _core->renderSprite(wall77);
    wall78.pixelPosition = {16*17,16*22};
    wall78.texture = _wallv;
    _core->renderSprite(wall78);
    wall79.pixelPosition = {16*17,16*23};
    wall79.texture = _wallv;
    _core->renderSprite(wall79);
}

void Pacman::ghost_house()
{
    ICore::Sprite leftcorner;
    ICore::Sprite leftdcorner;
    ICore::Sprite rightcorner;
    ICore::Sprite rightdcorner;
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    
    leftcorner.pixelPosition = {16*22, 16*15};
    leftcorner.texture = _cornerleft;
    leftdcorner.pixelPosition = {16*22, 16*20};
    leftdcorner.texture = _cornerleftd;
    rightcorner.pixelPosition = {448, 240};
    rightcorner.texture = _cornerright;
    rightdcorner.pixelPosition = {448, 16*20};
    rightdcorner.texture = _cornerrightd;
    _core->renderSprite(leftcorner);
    _core->renderSprite(leftdcorner);
    _core->renderSprite(rightcorner);
    _core->renderSprite(rightdcorner);
    wall0.pixelPosition = {16*22, 16*16};
    wall0.texture = _wallv;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*22, 16*17};
    wall1.texture = _wallv;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*22, 16*18};
    wall2.texture = _wallv;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*22, 16*19};
    wall3.texture = _wallv;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*28, 16*16};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*28, 16*17};
    wall5.texture = _wallv;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*28, 16*18};
    wall6.texture = _wallv;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*28, 16*19};
    wall7.texture = _wallv;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*27,16*20};
    wall8.texture = _wallh;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*26,16*20};
    wall9.texture = _wallh;
    _core->renderSprite(wall9);
    wall10.pixelPosition = {16*25,16*20};
    wall10.texture = _wallh;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*24,16*20};
    wall11.texture = _wallh;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*23,16*20};
    wall12.texture = _wallh;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*27,16*15};
    wall13.texture = _wallh;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*26,16*15};
    wall14.texture = _door;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*25,16*15};
    wall15.texture = _door;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*24,16*15};
    wall16.texture = _door;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*23,16*15};
    wall17.texture = _wallh;
    _core->renderSprite(wall17);
}

void Pacman::random_wall()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    
    wall0.pixelPosition = {16*22,16*13};
    wall0.texture = _endleft;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*23,16*13};
    wall1.texture = _wallh;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*24,16*13};
    wall2.texture = _wallh;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*25,16*13};
    wall3.texture = _wallh;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*26,16*13};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*27,16*13};
    wall5.texture = _wallh;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*28,16*13};
    wall6.texture = _endright;
    _core->renderSprite(wall6);

    wall7.pixelPosition = {16*22,16*22};
    wall7.texture = _endleft;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*23,16*22};
    wall8.texture = _wallh;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*24,16*22};
    wall9.texture = _wallh;
    _core->renderSprite(wall9);
    wall10.pixelPosition = {16*25,16*22};
    wall10.texture = _wallh;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*26,16*22};
    wall11.texture = _wallh;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*27,16*22};
    wall12.texture = _wallh;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*28,16*22};
    wall13.texture = _endright;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*25,16*6};
    wall14.texture = _Tup;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*25,16*7};
    wall15.texture = _wallv;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*25,16*8};
    wall16.texture = _wallv;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*25,16*9};
    wall17.texture = _wallv;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*25,16*10};
    wall18.texture = _wallv;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*25,16*11};
    wall19.texture = _enddown;
    _core->renderSprite(wall19);
    
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    wall20.pixelPosition = {16*20,16*11};
    wall20.texture = _Tup;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*27,16*11};
    wall21.texture = _endleft;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*28,16*11};
    wall22.texture = _wallh;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*29,16*11};
    wall23.texture = _wallh;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*30,16*11};
    wall24.texture = _Tup;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*30,16*12};
    wall25.texture = _wallv;
    _core->renderSprite(wall25);
    
    ICore::Sprite wall26;
    ICore::Sprite wall27;
    ICore::Sprite wall28;
    ICore::Sprite wall29;
    ICore::Sprite wall30;
    ICore::Sprite wall31;
    ICore::Sprite wall32;
    ICore::Sprite wall60;
    wall60.pixelPosition = {16*20,16*15};
    wall60.texture = _cornerrightd;
    _core->renderSprite(wall60);
    wall26.pixelPosition = {16*20,16*14};
    wall26.texture = _wallv;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*21,16*11};
    wall27.texture = _wallh;
    _core->renderSprite(wall27);
    wall28.pixelPosition = {16*22,16*11};
    wall28.texture = _wallh;
    _core->renderSprite(wall28);
    wall29.pixelPosition = {16*23,16*11};
    wall29.texture = _endright;
    _core->renderSprite(wall29);
    wall30.pixelPosition = {16*20,16*12};
    wall30.texture = _wallv;
    _core->renderSprite(wall30);
    wall31.pixelPosition = {16*20,16*13};
    wall31.texture = _wallv;
    _core->renderSprite(wall31);
    wall32.pixelPosition = {16*30,16*13};
    wall32.texture = _wallv;
    _core->renderSprite(wall32);
    
    ICore::Sprite wall33;
    ICore::Sprite wall34;
    ICore::Sprite wall36;
    ICore::Sprite wall37;
    ICore::Sprite wall38;
    ICore::Sprite wall39;
    ICore::Sprite wall40;
    ICore::Sprite wall41;
    ICore::Sprite wall42;
    ICore::Sprite wall43;
    ICore::Sprite wall44;
    ICore::Sprite wall45;
    ICore::Sprite wall61;
    wall33.pixelPosition = {16*22,16*24};
    wall33.texture = _cornerleft;
    _core->renderSprite(wall33);
    wall34.pixelPosition = {16*23,16*24};
    wall34.texture = _wallh;
    _core->renderSprite(wall34);
    wall36.pixelPosition = {16*24,16*24};
    wall36.texture = _cornerright;
    _core->renderSprite(wall36);
    wall37.pixelPosition = {16*22,16*25};
    wall37.texture = _wallv;
    _core->renderSprite(wall37);
    wall38.pixelPosition = {16*22,16*26};
    wall38.texture = _wallv;
    _core->renderSprite(wall38);
    wall39.pixelPosition = {16*22, 16*27};
    wall39.texture = _wallv;
    _core->renderSprite(wall39);
    wall40.pixelPosition = {16*22,16*28};
    wall40.texture = _wallv;
    _core->renderSprite(wall40);
    wall41.pixelPosition = {16*24,16*25};
    wall41.texture = _wallv;
    _core->renderSprite(wall41);
    wall42.pixelPosition = {16*24,16*26};
    wall42.texture = _wallv;
    _core->renderSprite(wall42);
    wall43.pixelPosition = {16*24,16*27};
    wall43.texture = _wallv;
    _core->renderSprite(wall43);
    wall44.pixelPosition = {16*24, 16*28};
    wall44.texture = _wallv;
    _core->renderSprite(wall44);
    wall45.pixelPosition = {16*22,16*29};
    wall45.texture = _wallv;
    _core->renderSprite(wall45);
    wall61.pixelPosition = {16*24,16*29};
    wall61.texture = _wallv;
    _core->renderSprite(wall61);
    
    ICore::Sprite wall46;
    ICore::Sprite wall47;
    ICore::Sprite wall48;
    ICore::Sprite wall49;
    ICore::Sprite wall50;
    ICore::Sprite wall51;
    ICore::Sprite wall52;
    ICore::Sprite wall53;
    ICore::Sprite wall54;
    ICore::Sprite wall55;
    ICore::Sprite wall56;
    ICore::Sprite wall57;
    wall46.pixelPosition = {16*26,16*24};
    wall46.texture = _cornerleft;
    _core->renderSprite(wall46);
    wall47.pixelPosition = {16*27,16*24};
    wall47.texture = _wallh;
    _core->renderSprite(wall47);
    wall48.pixelPosition = {16*28,16*24};
    wall48.texture = _cornerright;
    _core->renderSprite(wall48);
    wall49.pixelPosition = {16*26,16*25};
    wall49.texture = _wallv;
    _core->renderSprite(wall49);
    wall50.pixelPosition = {16*26,16*26};
    wall50.texture = _wallv;
    _core->renderSprite(wall50);
    wall51.pixelPosition = {16*26, 16*27};
    wall51.texture = _wallv;
    _core->renderSprite(wall51);
    wall57.pixelPosition = {16*26,16*28};
    wall57.texture = _cornerleftd;
    _core->renderSprite(wall57);
    wall52.pixelPosition = {16*28,16*25};
    wall52.texture = _wallv;
    _core->renderSprite(wall52);
    wall53.pixelPosition = {16*28,16*26};
    wall53.texture = _wallv;
    _core->renderSprite(wall53);
    wall54.pixelPosition = {16*28,16*27};
    wall54.texture = _wallv;
    _core->renderSprite(wall54);
    wall55.pixelPosition = {16*28,16*28};
    wall55.texture = _Tdown;
    _core->renderSprite(wall55);
    wall56.pixelPosition = {16*27,16*28};
    wall56.texture = _wallh;
    _core->renderSprite(wall56);
}

void Pacman::draw_corner()
{
    ICore::Sprite leftcorner;
    ICore::Sprite leftdcorner;
    ICore::Sprite rightcorner;
    ICore::Sprite rightdcorner;
	
    leftcorner.pixelPosition = {16*10, 16*6};
    leftcorner.texture = _cornerleft;
    leftdcorner.pixelPosition = {16*10, 16*30};
    leftdcorner.texture = _cornerleftd;
    rightcorner.pixelPosition = {16*40, 16*6};
    rightcorner.texture = _cornerright;
    rightdcorner.pixelPosition = {16*40, 16*30};
    rightdcorner.texture = _cornerrightd;
    
    _core->renderSprite(leftcorner);
    _core->renderSprite(leftdcorner);
    _core->renderSprite(rightcorner);
    _core->renderSprite(rightdcorner);
}

void Pacman::fill_vector()
{
    for (int i = 10; i != 41; i++){
        _wallpos.push_back(std::make_pair(16*i,16*6));
        _wallpos.push_back(std::make_pair(16*i,16*30));
    }
    for (int i = 6; i != 18; i++){
        _wallpos.push_back(std::make_pair(16*10, 16*i));
        _wallpos.push_back(std::make_pair(16*40, 16*i));
    }
    for (int i = 19; i != 31; i++){
        _wallpos.push_back(std::make_pair(16*10, 16*i));
        _wallpos.push_back(std::make_pair(16*40, 16*i));
    }
    for (int i = 27; i != 31; i++){ 
        _wallpos.push_back(std::make_pair(16*i, 16*11));
    }
    for (int i = 12; i != 16; i++){
        _wallpos.push_back(std::make_pair(16*30, 16*i));
    }
    for (int i = 11;  i != 16; i++){
        _wallpos.push_back(std::make_pair(16*20,16*i));
        _wallpos.push_back(std::make_pair(16*19,16*i));
    }
    for (int i = 22; i != 29; i++){
        _wallpos.push_back(std::make_pair(16*i, 16*22));
        _wallpos.push_back(std::make_pair(16*i, 16*13));
        _wallpos.push_back(std::make_pair(16*i, 16*20));
    }
    for (int i = 21; i != 24; i++){
        _wallpos.push_back(std::make_pair(16*i, 16*11));
    }
    for (int i = 15; i != 20; i++){
        _wallpos.push_back(std::make_pair(16*22, 16*i));
        _wallpos.push_back(std::make_pair(16*28, 16*i));
    }
    for (int i = 23; i != 28; i++){
        _wallpos.push_back(std::make_pair(16*i, 16*15));
    }
    for (int i = 6; i != 12; i++){
        _wallpos.push_back(std::make_pair(16*25, 16*i));
    }
    for (int i = 22; i != 25; i++){
        _wallpos.push_back(std::make_pair(16*i, 16*24));
    }
    for (int i = 25; i != 30; i++){
        _wallpos.push_back(std::make_pair(16*22, 16*i));
        _wallpos.push_back(std::make_pair(16*24, 16*i));
    }
    for (int i = 24; i != 29; i++){
        _wallpos.push_back(std::make_pair(16*26, 16*i));
        _wallpos.push_back(std::make_pair(16*28, 16*i));
        _wallpos.push_back(std::make_pair(16*38, 16*i));
    }
    for (int i = 31; i != 34; i++){
        _wallpos.push_back(std::make_pair(16*i, 16*15));
    }
    for (int i = 17; i != 21; i++){
        _wallpos.push_back(std::make_pair(16*19, 16*i));
        _wallpos.push_back(std::make_pair(16*36, 16*i));
    }
    for (int i = 7; i != 18; i++){
        _wallpos.push_back(std::make_pair(16*11, 16*i));
    }
    for (int i = 21; i != 25; i++){
        _wallpos.push_back(std::make_pair(16*12, 16*i));
    }
    for (int i = 26; i != 29; i++){
        _wallpos.push_back(std::make_pair(16*12, 16*i));
    }
    for (int i = 8; i != 13; i ++){
        _wallpos.push_back(std::make_pair(16*13, 16*i));
    }
    for (int i = 14; i != 20; i ++){
        _wallpos.push_back(std::make_pair(16*13, 16*i));
    }
    for (int i = 8; i != 11; i++){
        _wallpos.push_back(std::make_pair(16*15, 16*i));
    }
    for (int i = 12; i != 20; i++){
        _wallpos.push_back(std::make_pair(16*15, 16*i));
    }
    for (int i = 21; i != 25; i++){
        _wallpos.push_back(std::make_pair(16*15, 16*i));
        _wallpos.push_back(std::make_pair(16*17, 16*i));
    }
    for (int i = 26; i != 29; i++){
        _wallpos.push_back(std::make_pair(16*15, 16*i));
        _wallpos.push_back(std::make_pair(16*17, 16*i));
        _wallpos.push_back(std::make_pair(16*20, 16*i));
    }
    for (int i = 8; i != 15; i++){
        _wallpos.push_back(std::make_pair(16*17, 16*i));
    }
    for (int i = 16; i != 20; i++){
        _wallpos.push_back(std::make_pair(16*17, 16*i));
    }
    for (int i = 17; i != 25; i++){
        _wallpos.push_back(std::make_pair(16*20, 16*i));
    }
    for (int i = 17; i != 27; i++){
        _wallpos.push_back(std::make_pair(16*30, 16*i));
    }
    for (int i = 20; i != 27; i++){
        _wallpos.push_back(std::make_pair(16*32, 16*i));
    }
    for (int i = 22; i != 27; i++){
        _wallpos.push_back(std::make_pair(16*34, 16*i));
        _wallpos.push_back(std::make_pair(16*36, 16*i));
    }
    for (int i = 8; i != 12; i++){
        _wallpos.push_back(std::make_pair(16*35, 16*i));
        _wallpos.push_back(std::make_pair(16*36, 16*i));
        _wallpos.push_back(std::make_pair(16*38, 16*i));
    }
    for (int i = 13; i != 16; i++){
        _wallpos.push_back(std::make_pair(16*38, 16*i));
    }
    _wallpos.push_back(std::make_pair(16*11, 16*19));
    _wallpos.push_back(std::make_pair(16*23, 16*28));
    _wallpos.push_back(std::make_pair(16*26, 16*24));
    _wallpos.push_back(std::make_pair(16*27, 16*24));
    _wallpos.push_back(std::make_pair(16*27, 16*28));
    _wallpos.push_back(std::make_pair(16*22, 16*22));
    _wallpos.push_back(std::make_pair(16*13, 16*21));
    _wallpos.push_back(std::make_pair(16*13, 16*24));
    _wallpos.push_back(std::make_pair(16*13, 16*26));
    _wallpos.push_back(std::make_pair(16*13, 16*28));
    _wallpos.push_back(std::make_pair(16*14, 16*21));
    _wallpos.push_back(std::make_pair(16*14, 16*24));
    _wallpos.push_back(std::make_pair(16*14, 16*26));
    _wallpos.push_back(std::make_pair(16*14, 16*28));
    _wallpos.push_back(std::make_pair(16*18, 16*21));
    _wallpos.push_back(std::make_pair(16*18, 16*24));
    _wallpos.push_back(std::make_pair(16*18, 16*26));
    _wallpos.push_back(std::make_pair(16*18, 16*28));
    _wallpos.push_back(std::make_pair(16*19, 16*8));
    _wallpos.push_back(std::make_pair(16*19, 16*9));
    _wallpos.push_back(std::make_pair(16*19, 16*21));
    _wallpos.push_back(std::make_pair(16*19, 16*24));
    _wallpos.push_back(std::make_pair(16*19, 16*26));
    _wallpos.push_back(std::make_pair(16*19, 16*28));
    _wallpos.push_back(std::make_pair(16*20, 16*8));
    _wallpos.push_back(std::make_pair(16*20, 16*9));
    _wallpos.push_back(std::make_pair(16*22, 16*8));
    _wallpos.push_back(std::make_pair(16*22, 16*9));
    _wallpos.push_back(std::make_pair(16*23, 16*8));
    _wallpos.push_back(std::make_pair(16*23, 16*9));
    _wallpos.push_back(std::make_pair(16*27, 16*8));
    _wallpos.push_back(std::make_pair(16*27, 16*9));
    _wallpos.push_back(std::make_pair(16*28, 16*8));
    _wallpos.push_back(std::make_pair(16*28, 16*9));
    _wallpos.push_back(std::make_pair(16*29, 16*8));
    _wallpos.push_back(std::make_pair(16*29, 16*9));
    _wallpos.push_back(std::make_pair(16*29, 16*28));
    _wallpos.push_back(std::make_pair(16*30, 16*8));
    _wallpos.push_back(std::make_pair(16*30, 16*9));
    _wallpos.push_back(std::make_pair(16*30, 16*28));
    _wallpos.push_back(std::make_pair(16*31, 16*8));
    _wallpos.push_back(std::make_pair(16*31, 16*9));
    _wallpos.push_back(std::make_pair(16*31, 16*11));
    _wallpos.push_back(std::make_pair(16*31, 16*17));
    _wallpos.push_back(std::make_pair(16*31, 16*26));
    _wallpos.push_back(std::make_pair(16*31, 16*28));
    _wallpos.push_back(std::make_pair(16*32, 16*8));
    _wallpos.push_back(std::make_pair(16*32, 16*9));
    _wallpos.push_back(std::make_pair(16*32, 16*11));
    _wallpos.push_back(std::make_pair(16*32, 16*13));
    _wallpos.push_back(std::make_pair(16*32, 16*17));
    _wallpos.push_back(std::make_pair(16*33, 16*8));
    _wallpos.push_back(std::make_pair(16*33, 16*9));
    _wallpos.push_back(std::make_pair(16*33, 16*11));
    _wallpos.push_back(std::make_pair(16*33, 16*13));
    _wallpos.push_back(std::make_pair(16*33, 16*17));
    _wallpos.push_back(std::make_pair(16*33, 16*20));
    _wallpos.push_back(std::make_pair(16*33, 16*28));
    _wallpos.push_back(std::make_pair(16*34, 16*13));
    _wallpos.push_back(std::make_pair(16*34, 16*17));
    _wallpos.push_back(std::make_pair(16*34, 16*20));
    _wallpos.push_back(std::make_pair(16*34, 16*28));
    _wallpos.push_back(std::make_pair(16*35, 16*13));
    _wallpos.push_back(std::make_pair(16*35, 16*15));
    _wallpos.push_back(std::make_pair(16*35, 16*17));
    _wallpos.push_back(std::make_pair(16*35, 16*20));
    _wallpos.push_back(std::make_pair(16*35, 16*22));
    _wallpos.push_back(std::make_pair(16*35, 16*26));
    _wallpos.push_back(std::make_pair(16*35, 16*28));
    _wallpos.push_back(std::make_pair(16*36, 16*13));
    _wallpos.push_back(std::make_pair(16*36, 16*15));
    _wallpos.push_back(std::make_pair(16*36, 16*28));
    _wallpos.push_back(std::make_pair(16*37, 16*28));
    _wallpos.push_back(std::make_pair(16*38, 16*17));
    _wallpos.push_back(std::make_pair(16*38, 16*19));
    _wallpos.push_back(std::make_pair(16*38, 16*21));
    _wallpos.push_back(std::make_pair(16*38, 16*22));
    _wallpos.push_back(std::make_pair(16*39, 16*17));
    _wallpos.push_back(std::make_pair(16*39, 16*19));
}

void Pacman::draw_wall4()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    ICore::Sprite wall26;
    ICore::Sprite wall27;
 
    wall0.pixelPosition = {16*11,16*30};
    wall0.texture = _wallh;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*12,16*30};
    wall1.texture = _wallh;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*13,16*30};
    wall2.texture = _wallh;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*14,16*30};
    wall3.texture = _wallh;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*15,16*30};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall4.pixelPosition = {16*16,16*30};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*17,16*30};
    wall5.texture = _wallh;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*18,16*30};
    wall6.texture = _wallh;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*19,16*30};
    wall7.texture = _wallh;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*20,16*30};
    wall8.texture = _wallh;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*21,16*30};
    wall9.texture = _wallh;
    _core->renderSprite(wall9);
    wall10.pixelPosition = {16*22,16*30};
    wall10.texture = _Tdown;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*23,16*30};
    wall11.texture = _wallh;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*24,16*30};
    wall12.texture = _Tdown;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*25,16*30};
    wall13.texture = _wallh;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*26,16*30};
    wall14.texture = _wallh;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*27,16*30};
    wall15.texture = _wallh;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*28,16*30};
    wall16.texture = _wallh;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*29,16*30};
    wall17.texture = _wallh;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*30,16*30};
    wall18.texture = _wallh;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*31,16*30};
    wall19.texture = _wallh;
    _core->renderSprite(wall19);
    wall20.pixelPosition = {16*32,16*30};
    wall20.texture = _wallh;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*33,16*30};
    wall21.texture = _wallh;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*34,16*30};
    wall22.texture = _wallh;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*35,16*30};
    wall23.texture = _wallh;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*36,16*30};
    wall24.texture = _wallh;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*37,16*30};
    wall25.texture = _wallh;
    _core->renderSprite(wall25);
    wall26.pixelPosition = {16*38,16*30};
    wall26.texture = _wallh;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*39,16*30};
    wall27.texture = _wallh;
    _core->renderSprite(wall27);
}

void Pacman::draw_wall3()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall10;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    ICore::Sprite wall20;
    ICore::Sprite wall21;
    ICore::Sprite wall22;
    ICore::Sprite wall23;
    ICore::Sprite wall24;
    ICore::Sprite wall25;
    ICore::Sprite wall26;
    ICore::Sprite wall27;
 
    wall0.pixelPosition = {16*11,16*6};
    wall0.texture = _Tup;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*12,16*6};
    wall1.texture = _wallh;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*13,16*6};
    wall2.texture = _wallh;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*14,16*6};
    wall3.texture = _wallh;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*15,16*6};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall4.pixelPosition = {16*16,16*6};
    wall4.texture = _wallh;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*17,16*6};
    wall5.texture = _wallh;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*18,16*6};
    wall6.texture = _wallh;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*19,16*6};
    wall7.texture = _wallh;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*20,16*6};
    wall8.texture = _wallh;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*21,16*6};
    wall9.texture = _wallh;
    _core->renderSprite(wall9);
    wall10.pixelPosition = {16*22,16*6};
    wall10.texture = _wallh;
    _core->renderSprite(wall10);
    wall11.pixelPosition = {16*23,16*6};
    wall11.texture = _wallh;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*24,16*6};
    wall12.texture = _wallh;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*25,16*6};
    wall13.texture = _wallh;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*26,16*6};
    wall14.texture = _wallh;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*27,16*6};
    wall15.texture = _wallh;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*28,16*6};
    wall16.texture = _wallh;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*29,16*6};
    wall17.texture = _wallh;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*30,16*6};
    wall18.texture = _wallh;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*31,16*6};
    wall19.texture = _wallh;
    _core->renderSprite(wall19);
    wall20.pixelPosition = {16*32,16*6};
    wall20.texture = _wallh;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*33,16*6};
    wall21.texture = _wallh;
    _core->renderSprite(wall21);
    wall22.pixelPosition = {16*34,16*6};
    wall22.texture = _wallh;
    _core->renderSprite(wall22);
    wall23.pixelPosition = {16*35,16*6};
    wall23.texture = _wallh;
    _core->renderSprite(wall23);
    wall24.pixelPosition = {16*36,16*6};
    wall24.texture = _wallh;
    _core->renderSprite(wall24);
    wall25.pixelPosition = {16*37,16*6};
    wall25.texture = _wallh;
    _core->renderSprite(wall25);
    wall26.pixelPosition = {16*38,16*6};
    wall26.texture = _wallh;
    _core->renderSprite(wall26);
    wall27.pixelPosition = {16*39,16*6};
    wall27.texture = _wallh;
    _core->renderSprite(wall27);
}

void Pacman::draw_wall2()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    ICore::Sprite wall20;
    ICore::Sprite wall21;
 
    wall0.pixelPosition = {16*40, 16*7};
    wall0.texture = _wallv;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*40, 16*8};
    wall1.texture = _wallv;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*40, 16*9};
    wall2.texture = _wallv;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*40, 16*10};
    wall3.texture = _wallv;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*40, 16*11};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall4.pixelPosition = {16*40, 16*12};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*40, 16*13};
    wall5.texture = _wallv;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*40, 16*14};
    wall6.texture = _wallv;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*40, 16*15};
    wall7.texture = _wallv;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*40, 16*16};
    wall8.texture = _wallv;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*40, 16*17};
    wall9.texture = _cornerrightd;
    _core->renderSprite(wall9);
    wall11.pixelPosition = {16*40, 16*19};
    wall11.texture = _cornerright;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*40, 16*20};
    wall12.texture = _wallv;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*40, 16*21};
    wall13.texture = _wallv;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*40, 16*22};
    wall14.texture = _wallv;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*40, 16*23};
    wall15.texture = _wallv;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*40, 16*24};
    wall16.texture = _wallv;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*40, 16*25};
    wall17.texture = _wallv;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*40, 16*26};
    wall18.texture = _wallv;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*40, 16*27};
    wall19.texture = _wallv;
    _core->renderSprite(wall19);
    wall20.pixelPosition = {16*40, 16*28};
    wall20.texture = _wallv;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*40, 16*29};
    wall21.texture = _wallv;
    _core->renderSprite(wall21);
}

void Pacman::draw_wall()
{
    ICore::Sprite wall0;
    ICore::Sprite wall1;
    ICore::Sprite wall2;
    ICore::Sprite wall3;
    ICore::Sprite wall4;
    ICore::Sprite wall5;
    ICore::Sprite wall6;
    ICore::Sprite wall7;
    ICore::Sprite wall8;
    ICore::Sprite wall9;
    ICore::Sprite wall11;
    ICore::Sprite wall12;
    ICore::Sprite wall13;
    ICore::Sprite wall14;
    ICore::Sprite wall15;
    ICore::Sprite wall16;
    ICore::Sprite wall17;
    ICore::Sprite wall18;
    ICore::Sprite wall19;
    ICore::Sprite wall20;
    ICore::Sprite wall21;
 
    wall0.pixelPosition = {16*10, 16*7};
    wall0.texture = _wallv;
    _core->renderSprite(wall0);
    wall1.pixelPosition = {16*10, 16*8};
    wall1.texture = _wallv;
    _core->renderSprite(wall1);
    wall2.pixelPosition = {16*10, 16*9};
    wall2.texture = _wallv;
    _core->renderSprite(wall2);
    wall3.pixelPosition = {16*10, 16*10};
    wall3.texture = _wallv;
    _core->renderSprite(wall3);
    wall4.pixelPosition = {16*10, 16*11};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall4.pixelPosition = {16*10, 16*12};
    wall4.texture = _wallv;
    _core->renderSprite(wall4);
    wall5.pixelPosition = {16*10, 16*13};
    wall5.texture = _wallv;
    _core->renderSprite(wall5);
    wall6.pixelPosition = {16*10, 16*14};
    wall6.texture = _wallv;
    _core->renderSprite(wall6);
    wall7.pixelPosition = {16*10, 16*15};
    wall7.texture = _wallv;
    _core->renderSprite(wall7);
    wall8.pixelPosition = {16*10, 16*16};
    wall8.texture = _wallv;
    _core->renderSprite(wall8);
    wall9.pixelPosition = {16*10, 16*17};
    wall9.texture = _cornerleftd;
    _core->renderSprite(wall9);
    wall11.pixelPosition = {16*10, 16*19};
    wall11.texture = _cornerleft;
    _core->renderSprite(wall11);
    wall12.pixelPosition = {16*10, 16*20};
    wall12.texture = _wallv;
    _core->renderSprite(wall12);
    wall13.pixelPosition = {16*10, 16*21};
    wall13.texture = _wallv;
    _core->renderSprite(wall13);
    wall14.pixelPosition = {16*10, 16*22};
    wall14.texture = _wallv;
    _core->renderSprite(wall14);
    wall15.pixelPosition = {16*10, 16*23};
    wall15.texture = _wallv;
    _core->renderSprite(wall15);
    wall16.pixelPosition = {16*10, 16*24};
    wall16.texture = _wallv;
    _core->renderSprite(wall16);
    wall17.pixelPosition = {16*10, 16*25};
    wall17.texture = _wallv;
    _core->renderSprite(wall17);
    wall18.pixelPosition = {16*10, 16*26};
    wall18.texture = _wallv;
    _core->renderSprite(wall18);
    wall19.pixelPosition = {16*10, 16*27};
    wall19.texture = _wallv;
    _core->renderSprite(wall19);
    wall20.pixelPosition = {16*10, 16*28};
    wall20.texture = _wallv;
    _core->renderSprite(wall20);
    wall21.pixelPosition = {16*10, 16*29};
    wall21.texture = _wallv;
    _core->renderSprite(wall21);
}
