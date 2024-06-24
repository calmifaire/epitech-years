/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Exception
*/

#pragma once
#include <string>
#include <exception>

class Exception : public std::exception{
    public:
        Exception() = default;
        Exception(const char *text) throw();
        Exception(std::string text) throw();
        ~Exception() = default;

        const char *what() const throw();

    protected:
    private:
        std::string _message;

};
