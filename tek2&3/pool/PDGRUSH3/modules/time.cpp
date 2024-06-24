/*
** EPITECH PROJECT, 2022
** Time
** File description:
** Time
*/

#include "time.hpp"

std::string TimeInfo::getLocale() const
{
    return dt;
}

TimeInfo::TimeInfo()
{
    tmm = time(0);
    dt = ctime(&tmm);
    g = gmtime(&tmm);
}

TimeInfo::~TimeInfo()
{
}

void TimeInfo::refresh()
{
    tmm = time(0);
    dt = ctime(&tmm);
    g = gmtime(&tmm);
}

