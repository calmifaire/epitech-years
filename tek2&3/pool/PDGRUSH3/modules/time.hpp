/*
** EPITECH PROJECT, 2022
** time
** File description:
** time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <ctime>
#include <string>
#include "../core/IMonitorModule.hpp"

class TimeInfo : public IMonitorModule
{
private:
    time_t tmm;
    std::string dt;
    tm *g;
public:
    std::string getLocale() const;
    TimeInfo();
    ~TimeInfo();
    void refresh();
    void updateValues(IMonitorModule *module);

};

#endif /* !TIME_HPP_ */