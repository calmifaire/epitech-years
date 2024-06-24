/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeError
*/

#ifndef ARCADEERROR_HPP_
#define ARCADEERROR_HPP_

#include "ArcadeMain.hpp"

class ArcadeError : public std::exception {
    public:
        ArcadeError(std::string const &type, std::string const &message);
        const char *what() const noexcept override;
        ~ArcadeError();

    protected:
        std::string _message;
    private:
};

#endif /* !ARCADEERROR_HPP_ */
