/*
** EPITECH PROJECT, 2022
** Circuit
** File description:
** circuit
*/

#ifndef CIRCUIT_HPP_HPP
#define CIRCUIT_HPP

#include <bits/stdc++.h>
#include "IComponent.hpp"

class Circuit
{
public:
    Circuit() {stick = 0;};
    Circuit(const Circuit &p1) = delete;
    void addComponent(std::unique_ptr<nts::IComponent> c, std::string i);
    std::string getname(std::size_t) const;
    size_t getSize(std::size_t) const;
    size_t getMySize() const;
    nts::Tristate getValue(std::size_t k, size_t pin) const;
    void execCommand(std::string);
    void removeComponent();
    void createLink(std::size_t l, std::string g, std::string c, std::string m);
private:
    std::vector<std::string> name;
    std::vector<std::unique_ptr<nts::IComponent>> comp;
    size_t stick;
};

#endif
