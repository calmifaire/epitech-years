/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** name
*/
#ifndef NAME_HPP_
#define NAME_HPP_

#include <string>
#include "../core/IMonitorModule.hpp"

class User : public IMonitorModule {
public:
    User();
    ~User();
    void refresh();
    std::string getuser() const;
    std::string gethost() const;

private:
    std::string _username;
    std::string _hostname;
};

#endif