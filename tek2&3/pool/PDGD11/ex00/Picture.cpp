/*
** EPITECH PROJECT, 2022
** Picture
** File description:
** Picture
*/

#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string &file)
{
    if (file.size() == 0) {
        data = "";
        return true;
    }
    std::ifstream t(file);
    if (!t) {
        data = "ERROR";
        return false;
    }
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    data = str;
    return true;
}

Picture::Picture(const std::string &file)
{
    if (file.size() == 0)
        data = "";
    else {
        std::ifstream t(file);
        if (!t) {
            data = "ERROR";
        }
        else {
            std::string str((std::istreambuf_iterator<char>(t)),
                            std::istreambuf_iterator<char>());
            this->data = str;
        }
    }
}
