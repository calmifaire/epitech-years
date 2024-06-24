/*
** EPITECH PROJECT, 2022
** stack
** File description:
** stack
*/

#include <string>
#include <stack>

class Stack
{
private:
    std::stack<double> s;
    std::string message = "Empty stack";
public:
    Stack();
    ~Stack();
    void push(double value);
    double pop();
    double top() const;
    void add();
    void sub();
    void mul();
    void div();
    class Error : public std::exception
    {
    public:
        char const *what() const throw();
    private:
        Stack&  parent;
    };
};
