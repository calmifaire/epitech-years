/*
** EPITECH PROJECT, 2022
** IMonitorDisplay
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class IMonitorDisplay {
    public:
        // functions :
        virtual ~IMonitorDisplay() {};
        virtual void updateValues(IMonitorModule *) = 0;
        virtual void draw() = 0;
        // variables :

    private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
