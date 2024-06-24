/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** system
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "../core/IMonitorModule.hpp"
#include <string>

class System : public IMonitorModule {
    public:
    System();
    ~System();
    std::string getOs() const;
    std::string getDistrib() const;
    void refresh();

    private:
    std::string _os;
    std::string _kernel;
};


#endif
