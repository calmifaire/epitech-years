/*
** EPITECH PROJECT, 2022
** Circuit
** File description:
** Circuit
*/

#include "Circuit.hpp"

void Circuit::createLink(std::size_t l, std::string g, std::string c, std::string m)
{
    std::size_t y;
    std::stringstream sstream(g);
    size_t begin;
    sstream >> begin;
    std::stringstream sstrea(m);
    std::size_t end;
    sstrea >> end;
    nts::IComponent *p = comp[l].get();
    for (y = 0; y != name.size() && c.compare(name[y]) != 0; y++);
    if (y == name.size()){
		std::cout << c << " in links don't exist" << std::endl;
        throw std::exception();
	}
	if (end == 0 || begin == 0){
		std::cout << "missing number" << std::endl;
        throw std::exception();
	}
    comp[y]->setLink(end, *p, begin);
}

size_t Circuit::getMySize() const
{
    return comp.size();
}

size_t Circuit::getSize(std::size_t k) const
{
    return comp[k]->getLenght();
}

nts::Tristate Circuit::getValue(std::size_t k, size_t pin) const
{
    return comp[k]->compute(pin);
}

std::string Circuit::getname(std::size_t k) const
{
    return name[k];
}

void Circuit::execCommand(std::string h)
{
    if (h.compare("display")==0){
        std::cout << "tick: " << stick << "\ninput(s):" << std::endl;
        for (size_t k = 0; k < name.size(); k++){
            if (comp[k]->toWrite() == 0)
                std::cout << "  " << name[k] << ": " << comp[k]->getValueW() << std::endl;
        }
        std::cout << "output(s):";
        for (size_t k = 0; k < name.size(); k++){
            if (comp[k]->toWrite() == 1)
                std::cout << "\n  " << name[k] <<": " <<comp[k]->getValueW();
        }
        std::cout << std::endl;
    }
    if (h.find_first_of("=") != std::string::npos){
        size_t pos = h.find("=");
        std::string n = h.substr(0, pos);
        h.erase(0, pos + 1);
        for (pos = 0; pos < name.size() && name[pos].compare(n) != 0; pos++);
        if (pos == name.size())
            std::cout << n << " does not exist" << std::endl;
        else if (comp[pos]->toWrite() == 0)
            comp[pos]->setValue(h);
        else
            std::cout << n << " can't be changed manuelly" << std::endl;
    }
    if (h.compare("simulate")==0){
        stick++;
        for (size_t k = 0; k < name.size(); k++){
            comp[k]->simulate(stick);
        }
    }
}

void Circuit::addComponent(std::unique_ptr<nts::IComponent> c, std::string i)
{
	for (size_t l = 0; l != name.size(); l++)
	    if (name[l].compare(i) == 0){
		    std::cout << "same name " << i << " find\n";
		    throw std::exception();
		}
    name.push_back(i);
    comp.push_back(std::move(c));
}
