/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Main
*/

#include "Include.hpp"
#include "Factory.hpp"

static int get_input()
{
    int i = 0;
    Parser parser;
    Factory factory;
    std::string input;

    while (input.compare(";;") != 0){
        std::getline(std::cin, input);
        input = parser.trim(input);
        if (input.size() != 0 && input.at(0) != ';')
            parser.Push_input(input);
    }
     if ((i = parser.check_file()) != 0) {
        if (i == 1)
            throw Exception("wrong command or error syntax");
        if (i == 2)
            throw Exception("no exit");
        if (i == 3)
            throw Exception("nothing to use");
    }
    i = factory.loop(parser.get_parse());
    return (i);
}

static int read_file(char *file)
{
    int i = 0;
    std::ifstream infile(file);
    Parser parser;
    Factory factory;
    std::string input;

    while (std::getline(infile, input)){
        input = parser.trim(input);
        if (input.size() != 0 && input.at(0) != ';')
            parser.Push_input(input);
    }
    if ((i = parser.check_file()) != 0) {
        if (i == 1)
            throw Exception("wrong command or error syntax");
        if (i == 2)
            throw Exception("no exit");
        if (i == 3)
            throw Exception("nothing to use");
        if (i == 4)
            throw Exception("only int8 for store and load");
    }
    i = factory.loop(parser.get_parse());
    return (i);
}

static int check_file(char *file)
{
    int i = 0;

    for (i = 0; file[i] != '.' && file[i] != '\0'; i++);
    if (file[i] != '.' || file[i + 1] == '\0' || file[i + 2] == '\0' || file[i + 3] == '\0')
        throw Exception("wrong file type");
    if (file[i + 1] != 'a' || file[i + 2] != 'v' || file[i + 3] != 'm'){
        throw Exception("wrong file type");
    }
    return (read_file(file));
}

int main (int ac, char **av)
{
    try
    {
        if (ac == 1)
            return (get_input());
        else if (ac == 2)
            return (check_file(av[1]));
        else
            throw Exception("usage ./avm or ./avm file");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}
