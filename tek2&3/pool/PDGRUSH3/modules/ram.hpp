/*
** EPITECH PROJECT, 2022
** B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
** File description:
** ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "../core/IMonitorModule.hpp"

class Ram : public IMonitorModule {
public:
    Ram();
    ~Ram();
    void refresh();
    float GetRamTotal() const;
    float GetUsedRam() const;

private:
    float _totalram;
    float _ramused;
};

#endif /* !RAM_HPP_ */
