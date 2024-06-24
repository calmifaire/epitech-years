/*
** EPITECH PROJECT, 2022
** cpu
** File description:
** cpu
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Cpu
{
public:
    Cpu();
    ~Cpu();
    std::string getModel() const;
    std::string getFrequency() const;
    std::string getCore() const;
    std::string getActivity() const;
private:
    std::string model;
    std::string frequency;
    std::string core;
    std::string activity;
};
