/*
** EPITECH PROJECT, 2022
** print ram
** File description:
** print_Ram
*/

#ifndef PRINT_RAM_HPP_
#define PRINT_RAM_HPP_

#include <SFML/Graphics.hpp>
#include "../../core/IMonitorDisplay.hpp"
#include "../../core/IMonitorModule.hpp"
#include "../../modules/ram.hpp"

class P_Ram : public IMonitorDisplay {
    public:
        P_Ram(sf::RenderWindow &window);
        ~P_Ram();
        void draw();
        void updateValues(IMonitorModule *module);
    private:
        float _totalRam;
        float _ramUsed;
        sf::Text *_TotalRam;
        sf::Text *_RamUsed;
        sf::Text *_title;
        sf::RenderWindow &_window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
};

#endif /* !PRINT_RAM_HPP_ */
