/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    this->_message = message;
    this->_component = component;
}

const std::string& NasaError::getComponent() const
{
    return _component;
}

char const *NasaError::what() const throw()
{
    return this->_message.c_str();
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component) 
{
    this->_message = message;
    this->_component = component;
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
    this->_message = message;
    this->_component = component;
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
    this->_message = message;
    this->_component = component;
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
    this->_message = message;
    this->_component = "CommunicationDevice";
}
