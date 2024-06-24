/*
** EPITECH PROJECT, 2022
** print user
** File description:
** print_User
*/

#ifndef PRINT_USER_HPP_
#define PRINT_USER_HPP_

#include <list>
#include <SFML/Graphics.hpp>
#include "../../core/IMonitorDisplay.hpp"

class P_user : public IMonitorDisplay {
    public:
        // functions :
        P_user(sf::RenderWindow &window);
        ~P_user() {};
        void draw();
        void updateValues(IMonitorModule *module);
        // vars :
        sf::RenderWindow &_window;
        sf::Font _font;
        sf::Texture _texture;
        std::string _username;
        std::string _hostname;
        sf::Sprite _sprite;
        sf::Text *_TUsername;
        sf::Text *_THostename;
        sf::Text *_title;
    private:
};

#endif /* !PRINT_USER_HPP_ */
