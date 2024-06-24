/*
** EPITECH PROJECT, 2022
** stock
** File description:
** all
*/

#include "../include/nm.h"

inf_t *more_in_inf(inf_t *l, char n, char *str, int a)
{
    inf_t *nv = malloc(sizeof(inf_t));
    inf_t *tmp = l;

    nv->j = a;
    nv->c = n;
    nv->s = str;
    nv->next = NULL;
    if (tmp == NULL)
        return (nv);
    else{
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = nv;
        return (l);
    }
}

void storing_value(char *str,Elf64_Shdr *symtab,Elf64_Sym *sym,Elf64_Shdr *shdr)
{
    inf_t *v = NULL;

    for (size_t i = 1; i < symtab->sh_size / sizeof(Elf64_Sym); i++){
        if (sym[i].st_info != STT_FILE && sym[i].st_info != STT_SECTION)
            v = more_in_inf(v, get_symbole_part1(sym[i],shdr),
                            (str + sym[i].st_name), sym[i].st_value);
    }
    if (v == NULL)
        return;
    rearrange_value_by_name(v);
    rearrange_value_by_adress(v);
    for (;v != NULL; v = v->next){
        if (v->c != 'w' && v->c != 'U')
            printf("%016x %c %s\n", v->j,v->c,v->s);
        else
            printf("                 %c %s\n", v->c,v->s);
    }
}
