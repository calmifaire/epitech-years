#pragma once

#include <string>
#include <exception>

class NasaError : public std::exception
{
protected:
    std::string _message;
    std::string _component;
public:
    NasaError(std::string const &message, std::string const &component = "Unknown");
    std::string const &getComponent() const;
    char const *what() const throw();
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};
