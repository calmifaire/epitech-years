/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** Parser
*/

#include "Include.hpp"

std::vector<std::pair<std::string,std::pair<eOperandType, std::string>>> Parser::get_parse(void)
{
    return (parse);
}

void Parser::Push_input(std::string input)
{
    file.push_back(trim(input));
}

void Parser::Print_file(void)
{
    for (long unsigned int i = 0; i < file.size(); i++)
        std::cout << file[i] << std::endl;
    std::cout << std::endl;
}

int Parser::check_size(void)
{
    if (file.size() == 0)
        return (1);
    return (0);
}

int Parser::check_file(void)
{
    std::string line;
    std::pair<eOperandType, std::string> type;

    if (check_size() != 0)
        return (3);
    for (long unsigned int i = 0; i < file.size(); i++) {
        ok = 0;
        line = file[i];
        if (line.compare(0, 3, "pop") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("pop", type));
            ok = 1;
        }
        if (line.compare(0, 3, "dup") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("dup", type));
            ok = 1;
        }
        if (line.compare(0, 3, "add") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("add", type));
            ok = 1;
        }
        if (line.compare(0, 3, "sub") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("sub", type));
            ok = 1;
        }
        if (line.compare(0, 3, "mul") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("mul", type));
            ok = 1;
        }
        if (line.compare(0, 3, "div") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("div", type));
            ok = 1;
        }
        if (line.compare(0, 3, "mod") == 0 && check_end(line, 3) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("mod", type));
            ok = 1;
        }
        if (line.compare(0, 4, "swap") == 0 && check_end(line, 4) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("swap", type));
            ok = 1;
        }
        if (line.compare(0, 4, "dump") == 0 && check_end(line, 4) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("dump", type));
            ok = 1;
        }
        if (line.compare(0, 4, "exit") == 0 && check_end(line, 4) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("exit", type));
            break;
        }
        if (line.compare(0, 5, "print") == 0 && check_end(line, 5) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("print", type));
            ok = 1;
        }
        if (line.compare(0, 5, "clear") == 0 && check_end(line, 5) == 0) {
            type = std::make_pair(null, NULL);
            parse.push_back(std::make_pair("clear", type));
            ok = 1;
        }
        if (line.compare(0, 4, "push") == 0 && check_end_with_arg(line) == 0) {
            ok = check_v(line, &type);
            parse.push_back(std::make_pair("push", type));
        }
        if (line.compare(0, 4, "load") == 0 && check_end_with_arg(line) == 0) {
            ok = check_v(line, &type);
            if (type.first != INT8)
                return (4);
            parse.push_back(std::make_pair("load", type));
        }
        if (line.compare(0, 5, "store") == 0 && check_end_with_arg(line) == 0) {
            ok = check_v(line, &type);
            if (type.first != INT8)
                return (4);
            parse.push_back(std::make_pair("store", type));
        }
        if (line.compare(0, 6, "assert") == 0 && check_end_with_arg(line) == 0) {
            ok = check_v(line, &type);
            parse.push_back(std::make_pair("assert", type));
        }
        if (ok == 0)
            return (1);
    }
    if (parse.back().first.compare(0, 4, "exit") != 0)
        return (2);
    return (0);
}

int Parser::check_v(std::string line, std::pair<eOperandType, std::string> *type)
{
    t = null;
    pos1 = line.find_first_of(" \n\r\t\f\v");
    pos2 = line.find_first_of('(');
    substr = line.substr(pos1 + 1, pos2 - pos1 - 1);
    substr = trim(substr);
    if (substr.compare("int8") == 0)
        t = INT8;
    if (substr.compare("int16") == 0)
        t = INT16;
    if (substr.compare("int32") == 0)
        t = INT32;
    if (substr.compare("float") == 0)
        t = FLOAT;
    if (substr.compare("double") == 0)
        t = DOUBLE;
    if (substr.compare("bigdecimal") == 0)
        t = BIGDECIMAL;
    if (t == null)
        return (0);
    pos1 = line.find_first_of(')');
    substr = line.substr(pos2 + 1, pos1 - pos2 - 1);
    if (substr.size() <= 0)
        return (0);
    substr = trim(substr);
    if ((t == INT8 || t == INT16 || t == INT32) && substr.find_first_not_of("-0123456789") < substr.size()) {
        return (0);
    }
    if ((t == FLOAT || t == DOUBLE || t == BIGDECIMAL) && substr.find_first_not_of("-0123456789.") < substr.size()) {
        return (0);
    }
    pos1 = line.find_first_of(')');
    *type = std::make_pair(t, substr);
    return (1);
}

std::string Parser::ltrim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \n\r\t\f\v");
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string Parser::rtrim(const std::string &s)
{
	size_t end = s.find_last_not_of(" \n\r\t\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string Parser::trim(const std::string &s)
{
	return rtrim(ltrim(s));
}

int Parser::check_end(std::string line, long unsigned int size)
{
    if (line.size() == size)
        return (0);
    size_t start = line.find_first_not_of(" \n\r\t\f\v", size + 1);
    if (line.at(start) == ';')
        return (0);
    return (1);
}

int Parser::check_end_with_arg(std::string line)
{
    size_t start = line.find_first_of(")");
    if (line.size() == start + 1)
        return (0);
    start = line.find_first_not_of(" \n\r\t\f\v", start + 1);
    if (line.at(start) == ';')
        return (0);
    return (1);
}

Parser::Parser()
{
}

Parser::~Parser()
{
}
