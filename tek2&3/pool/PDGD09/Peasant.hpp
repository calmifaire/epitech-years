/*
** EPITECH PROJECT, 2022
** peasant
** File description:
** peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <string>
#include <iostream>

class Peasant {
protected:
    std::string Name;
    int Power;
    int Hp;
public:
    int attack();
    int special();
    void rest();
    void damage(int damage);
    const std::string &getName() const;
    int getPower() const;
    int getHp() const;
    explicit Peasant(const std::string &name, int power);
    ~Peasant();
};

#endif /* PEASANT_HPP_ */
