/*
** EPITECH PROJECT, 2022
** string.h
** File description:
** string.h
*/

#ifndef STRING_H_
 #define STRING_H_

#include <string.h>

typedef struct s_string string_t;

struct 	s_string
{
    char *str;
    void (*string_init)(string_t *this, const char *s);
    void (*string_destroy)(string_t *this);
    void (*assign_s)(string_t *this, const string_t *str);
    void (*assign_c)(string_t *this , const  char *s);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*length)(const string_t *this);
    int (*compare_s)(const string_t *this, const string_t *str);
    int (*compare_c)(const string_t *this, const char *str);
    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *this);
    int (*empty)(const string_t *this);
    int (*find_s)(const string_t *this, const string_t *str, size_t pos);
    int (*find_c)(const string_t *this, const char *str, size_t pos);
};

void string_init(string_t *this , const  char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char find_at_position(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

#endif /* STRING_H_ */
