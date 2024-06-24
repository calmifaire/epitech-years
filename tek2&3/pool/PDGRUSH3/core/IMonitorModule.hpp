/*
** EPITECH PROJECT, 2022
** IMonitorModules
** File description:
** IMonitorModul
*/

#ifndef IMONITORMODUL_HPP_
#define IMONITORMODUL_HPP_

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {};
        virtual void refresh() = 0;

    protected:
    private:
};

#endif /* !IMONITORMODUL_HPP_ */
