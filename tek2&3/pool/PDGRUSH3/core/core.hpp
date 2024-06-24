/*
** EPITECH PROJECT, 2022
** core.hpp
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "../modules/name.hpp"
#include "../modules/ram.hpp"
#include "../modules/system.hpp"
#include "../modules/time.hpp"

#endif /* !CORE_HPP_ */

class Core {
    public:
        // functions :
        Core();
        ~Core() {};
        void getValues();
        void addModule(IMonitorModule *module);
        void refresh();
        // variables :
        std::list<IMonitorModule *> _modules;
};