/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parser
*/

#include "Parser.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

Parser::Parser(std::string f)
{
    file = f;

    std::ifstream t(f);
    if (t.good() == 0){
        std::cout << "no such file\n";
        throw std::exception();
    }
    std::string str;
    std::regex author_regex("([^ .\n:#]+)");
    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());
    std::vector<std::string> names(std::sregex_token_iterator(str.begin(), str.end(), author_regex),
                                   std::sregex_token_iterator());
    auto i = names.begin();
    if (i == names.end()){
        std::cout << "empty file\n";
        throw std::exception();
    }
    std::unique_ptr<nts::IComponent> g;
    Circuit b;
    for (;i != names.end() && i->compare("chipsets");++i);
    if (i == names.end()){
        std::cout << "chipsets error found\n";
        throw std::exception();
    }
    i++;
    for (;i != names.end() && i->compare("links") != 0; ++i){
        g = createComponent(*i);
        ++i;
        b.addComponent(std::move(g), *i);
    }
    if (b.getMySize() == 0){
        std::cout << "no component\n";
        throw std::exception();
    }
    if (i->compare("links") != 0 || i+1 == names.end()){
        std::cout << "links error found" << std::endl;
        throw std::exception();
    }
    i++;
    std::size_t l;
    for (;i != names.end(); ++i){
        for (l = 0; i->compare(b.getname(l)) != 0 && l < b.getMySize() - 1; l++);
        if (i->compare(b.getname(l)) == 0){
            if (i+3 == names.end()){
                std::cout << "links error found\n";
                throw std::exception();
            }
            i++;
            auto a = *i;
            i++;
            auto f = *i;
            i++;
            auto c = *i;
            if (f.compare(b.getname(l)) == 0 && a == c){
                std::cout << "component link to itself\n";
                throw std::exception();
            }
            b.createLink(l, a, f, c);
        }else{
            std::cout << *i << " in links don't exist" << std::endl;
            throw std::exception();
        }
    }
    std::string h;
    int def = '0';
    while (def != EOF && h.compare("exit") != 0){
        std::cout << "> ";
        std::cin >> h;
        def = getchar();
        if (def != EOF && h.compare("exit") != 0){
            b.execCommand(h);
        }
    }
}
