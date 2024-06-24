/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include "../core/core.hpp"
#include "print_info/print_User.hpp"
#include "print_info/print_Os.hpp"
#include "print_info/print_Time.hpp"
#include "print_info/print_Ram.hpp"
#include "../core/IMonitorDisplay.hpp"

class Timer {
    public:
        // functions :
        Timer();
        ~Timer();
        void UpdateTime();
        double getTime();
        // variables :
        sf::Clock *_clock;
        double _timecurrent;
        double _preTime;
        double _timeSinceStart;
        double _value;
};

class Graphic {
    public:
        // functions :
        Graphic(Core *core);
        ~Graphic() {};
        void refresh();
        void loop();
        void update_everythings();
        void draw_everythings();
        // vars :
        std::list<IMonitorDisplay *> _modules;
        Core *_core;
        sf::RenderWindow _window;
        sf::Event _event;
        Timer *_time;
    protected:
    private:
};

void Init_SFML(Core *core);

#endif /* !GRAPHIC_HPP_ */
