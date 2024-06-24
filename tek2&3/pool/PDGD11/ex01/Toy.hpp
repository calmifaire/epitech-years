/*
** EPITECH PROJECT, 2022
** toy
** File description:
** toy
*/

#include "Picture.hpp"

class Toy
{
public:
    enum ToyType
    {
        BASIC_TOY,
        ALIEN
    };
    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(std::string name);
    void setAscii(std::string file);
    Toy();
    Toy(Toy::ToyType, std::string, std::string);
    Toy(const Toy&);
    Toy &operator=(const Toy&);
    virtual ~Toy();
private:
    Toy::ToyType type;
    std::string name;
    Picture picture;
};
