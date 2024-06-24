/*
** EPITECH PROJECT, 2022
** cpu
** File description:
** cpu
*/

#include "cpu.hpp"

Cpu::Cpu()
{
    std::string line;
    std::ifstream finfo("/proc/cpuinfo");
    std::ifstream ainfo("/proc/stat");

    while(getline(finfo,line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;
        if (getline(str, itype, ':') && getline(str,info) && itype.substr(0,10) == "model name") {
            model = info;
            break;
        }
    }
    while(getline(finfo,line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;
        if (getline(str, itype, ':') && getline(str,info) && itype.substr(0, 7) == "cpu MHz") {
            frequency = info;
            break;
        }
    }
    while(getline(finfo,line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;
        if (getline(str, itype, ':') && getline(str,info) && itype.substr(0, 9) == "cpu cores") {
            core = info;
            break;
        }
    }
    while(getline(ainfo,line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;
        if (getline(str, itype, ' ') && getline(str,info) && itype.substr(0,3) == "cpu") {
            activity = info;
            break;
        }
    }
}

Cpu::~Cpu()
{}

std::string Cpu::getModel() const
{
    return model;
}

std::string Cpu::getFrequency() const
{
    return frequency;
}

std::string Cpu::getCore() const
{
    return core;
}

std::string Cpu::getActivity() const
{
    return activity;
}
