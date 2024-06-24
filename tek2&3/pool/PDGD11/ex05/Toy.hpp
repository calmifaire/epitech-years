/*
** EPITECH PROJECT, 2022
** toy
** File description:
** toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy
{
public:
    enum ToyType
    {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };
    class Error {
    public:
        enum ErrorType
        {
            UNKNOWN,
            PICTURE,
            SPEAK
        };
        Error();
        ErrorType type;
        std::string what() const;
        std::string where() const;
        void setType(ErrorType type);
    };
    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(std::string name);
    bool setAscii(std::string file);
    virtual void speak(std::string statement);
    virtual bool speak_es(std::string statement);
    Toy::Error const& getLastError() const;
    Toy();
    Toy(Toy::ToyType, std::string, std::string);
    Toy(const Toy&);
    Toy &operator=(const Toy&);
    void operator<<(const std::string f);
    virtual ~Toy();
protected:
    Error error;
    Toy::ToyType type;
    std::string name;
    Picture picture;
};

std::ostream& operator<<(std::ostream& os, const Toy& dt);

#endif
