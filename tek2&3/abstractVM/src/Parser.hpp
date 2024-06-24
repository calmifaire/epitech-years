/*
** EPITECH PROJECT, 2022
** abstract-vm bootstrap
** File description:
** PArser
*/

#pragma once
#include <vector>
#include "IOperand.hpp"

class Parser {
    public:
        Parser();
        ~Parser();
        void Push_input(std::string input);
        void Print_file(void);
        int check_size(void);
        int check_file(void);
        int check_v(std::string, std::pair<eOperandType, std::string> *);
        std::vector<std::pair<std::string,std::pair<eOperandType, std::string>>> get_parse(void);
        std::string trim(const std::string &s);
        int check_end(std::string line, long unsigned int size);
        int check_end_with_arg(std::string line);
    protected:
    private:
        std::string ltrim(const std::string &s);
        std::string rtrim(const std::string &s);
        std::vector<std::pair<std::string,std::pair<eOperandType, std::string>>> parse;
        std::vector<std::string> file;
        std::pair<eOperandType, std::string> type;
        std::string line;
        eOperandType t;
        size_t pos1;
        size_t pos2;
        std::string substr;
        int ok;
};
