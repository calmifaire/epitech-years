/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArgumentChecker
*/

#ifndef ARGUMENTCHECKER_HPP_
#define ARGUMENTCHECKER_HPP_

#include "ArcadeError.hpp"

class ArgumentChecker {
    public:
        static void CheckNumber(int ac);
        static void *CheckAndOpenLibrary(char *arg);
    protected:
    private:
};

#endif /* !ARGUMENTCHECKER_HPP_ */
