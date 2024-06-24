 /*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** blocksys
*/

#ifndef BLOCKSYS_HPP_
#define BLOCKSYS_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "../../core/IMonitorModule.hpp"
#include "../../core/IMonitorDisplay.hpp"
#include "../../modules/system.hpp"

class P_sys : public IMonitorDisplay
{
    public:
        P_sys(sf::RenderWindow &window);
        ~P_sys();

        void updateValues(IMonitorModule *);
        void draw();
    private:
        std::string _os;
        std::string _distrib;
        sf::Text *_title;
        sf::Text *_printOs;
        sf::Text *_printDistrib;
        sf::RenderWindow &_window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
};

#endif /* !BLOCKSYS_HPP_ */