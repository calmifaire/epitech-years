/*
** EPITECH PROJECT, 2022
** picture
** File description:
** picture
*/

#include <iostream>
#include <string>
#include <cstring>
#include <streambuf>
#include <fstream>
#include <cstddef>

class Picture
{
public:
    std::string data;
    bool getPictureFromFile(const std::string &file);
    Picture(const std::string &file);
    Picture (const Picture&);
    virtual ~Picture();
    Picture &operator=(const Picture&);
};
