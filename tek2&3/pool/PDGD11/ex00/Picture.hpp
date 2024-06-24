/*
** EPITECH PROJECT, 2022
** picture
** File description:
** picture
*/

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
};
