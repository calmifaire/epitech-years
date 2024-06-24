/*
** EPITECH PROJECT, 2022
** buzz
** File description:
** buzz
*/

#include "Toy.hpp"

class Buzz : public Toy
{
public:
    Buzz(std::string n, std::string file);
    Buzz(std::string n);
    virtual void speak(std::string statement) override;
    virtual bool speak_es(std::string statement) override;
};
