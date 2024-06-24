/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

void get_value_Celsius(std::string str)
{
    size_t i = 0;
    float id = 0;
    char n = str[0];

    for (; i < str.length(); i++) {
        if (isdigit(str[i]))
            break;
    }
    str = str.substr(i, str.length() - i );
    id = atoi(str.c_str());
    if (n == '-')
        id = id* (-1);
    id = 5.0 / 9.0 * (id - 32);
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << std::setw(16) << round(id) << std::setw(16) << "Celsius" << std::endl;
}

void get_value_Fahrenheit(std::string str)
{
    size_t i = 0;
    float id = 0.0;
    char n = str[0];

    for (; i < str.length(); i++) {
        if (isdigit(str[i]))
            break;
    }
    str = str.substr(i, str.length() - i );
    id = atoi(str.c_str());
    if (n == '-')
        id = id * (-1);
    id = id * 1.8 + 32;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << std::setw(16) << id << std::setw(16) << "Fahrenheit" << std::endl;
}

void get_type(std::string str)
{
    std::size_t found = str.find("Celsius");

    if (found!=std::string::npos)
        get_value_Fahrenheit(str);
    else {
        found = str.find("Fahrenheit");
        if (found!=std::string::npos)
            get_value_Celsius(str);
    }
}

int main(void)
{
    std::string str;

    std::getline (std::cin,str);
    get_type(str);
    return (0);
}
