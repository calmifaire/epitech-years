/*
** EPITECH PROJECT, 2022
** print time
** File description:
** print_Time
*/

#ifndef PRINT_TIME_HPP_
#define PRINT_TIME_HPP_

#include <SFML/Graphics.hpp>
#include "../../core/IMonitorDisplay.hpp"
#include "../../core/IMonitorModule.hpp"
#include "../../modules/time.hpp"

class P_Time : public IMonitorDisplay {
    public:
        P_Time(sf::RenderWindow &window);
        ~P_Time() {};
        void draw();
        void updateValues(IMonitorModule *module);
    private:
        std::string _time;
        sf::Text *_TimE;
        sf::Text *_title;
        sf::RenderWindow &_window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
};

#endif /* !PRINT_TIME_HPP_ */
