/*
** EPITECH PROJECT, 2022
** nm
** File description:
** header
*/

#ifndef NM_REQUIREMENT
    #define NM_REQUIREMENT

    #include <fcntl.h>
    #include <stdio.h>
    #include <elf.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

typedef struct inf inf_t;
struct inf {
    int j;
    char c;
    char *s;
    struct inf *next;};

int custom_strcmp(char *str1, char *str2);
void explore_sysinfo(void *buf,Elf64_Ehdr *elf,Elf64_Shdr *sys,Elf64_Sym *sym);
char get_symbole_part6(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbole_part5(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbole_part4(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbole_part3(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbole_part2(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbole_part1(Elf64_Sym sym, Elf64_Shdr *shdr);
void storing_value(char *str, Elf64_Shdr *symtab, Elf64_Sym *sym, Elf64_Shdr *shdr);
inf_t *more_in_inf(inf_t *l, char n, char *str, int a);
int test(char s, char c);
void get_info(void *buf, char *av);
char *define_array(char *array, FILE *f);
int testfile(char *a);
inf_t *more_in_inf(inf_t *l, char n, char *str, int a);
inf_t *rearrange_value_by_name(inf_t *v);
inf_t *apply_condition_rearrange_by_name(inf_t *current, inf_t *index);
inf_t *rearrange_value_by_adress(inf_t *v);
inf_t *apply_condition_rearrange_by_adress(inf_t *current, inf_t *index);

#endif
