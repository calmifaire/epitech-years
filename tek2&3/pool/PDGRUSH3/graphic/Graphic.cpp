/*
** EPITECH PROJECT, 2022
** Graphic
** File description:
** Graphic
*/

#include "Graphic.hpp"

void Init_SFML(Core *core)
{
    Graphic *graphique = new Graphic(core);

    core->refresh();
    graphique->update_everythings();
    graphique->draw_everythings();
    graphique->loop();
}

Graphic::Graphic(Core *core) : _core(core)
{
    Timer *dt = new Timer();
    _time = dt;
    _modules.push_back(new P_user(_window));
    _modules.push_back(new P_Ram(_window));
    _modules.push_back(new P_Time(_window));
    _modules.push_back(new P_sys(_window));
    _window.create(sf::VideoMode(1200, 800), "GKrell", sf::Style::Close);
    _window.setFramerateLimit(60);
}

Timer::Timer() : _timecurrent(0), _timeSinceStart(0), _preTime(0), _value(0), _clock(new sf::Clock())
{}

void Timer::UpdateTime()
{
    _preTime = _timecurrent;
    _timecurrent = _clock->getElapsedTime().asMicroseconds();
    _timeSinceStart = _timecurrent / 1000000.0f;
    _value = (_timecurrent - _preTime) / 1000000.0f;
}

double Timer::getTime()
{
    return (this->_value);
}

void Graphic::loop()
{
    double time = 0.0f;

    while (_window.isOpen()) {
        _time->UpdateTime();
        time += _time->getTime();
        if (time >= (1.0f)) {
            _core->refresh();
            update_everythings();
            time = 0;
        }
        _window.clear(sf::Color::White);
        draw_everythings();
        refresh();
    }
}

void Graphic::draw_everythings()
{
    std::list<IMonitorDisplay *>::iterator it1;

    for (it1 = _modules.begin(); it1 != _modules.end(); ++it1) {
        (*it1)->draw();
    }
}

void Graphic::update_everythings()
{
    std::list<IMonitorDisplay *>::iterator it1;
    std::list<IMonitorModule *>::iterator it2;

    for (it1 = _modules.begin(), it2 = _core->_modules.begin(); it1 != _modules.end(), it2 != _core->_modules.end(); it1++, it2++) {
        (*it1)->updateValues((*it2));
    }
}

void Graphic::refresh()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
    _window.display();
}