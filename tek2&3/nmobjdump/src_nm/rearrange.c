/*
** EPITECH PROJECT, 2022
** rearrange
** File description:
** reangea
*/

#include "../include/nm.h"

inf_t *apply_condition_rearrange_by_adress(inf_t *current, inf_t *index)
{
    char *stmp;
    char ctmp;
    int jtmp;

    if (custom_strcmp(current->s, index->s) == 0 
    && strlen(current->s) == strlen(index->s) && current->j > index->j){
        stmp = current->s;
        ctmp = current->c;
        jtmp = current->j;
        current->s = index->s;
        current->c = index->c;
        current->j = index->j;
        index->s = stmp;
        index->c = ctmp;
        index->j = jtmp;
    }
    return current;
}

inf_t *rearrange_value_by_adress(inf_t *v)
{
    inf_t *current;
    char *stmp;
    char ctmp;
    int jtmp;

    for (inf_t *current = v; current != NULL; current = current->next){
        for (inf_t *index = current->next;index != NULL; index = index->next){
            apply_condition_rearrange_by_adress(current, index);
        }
    }
    return (current);
}

inf_t *apply_condition_rearrange_by_name(inf_t *current, inf_t *index)
{
    char *stmp;
    char ctmp;
    int jtmp;

    if (custom_strcmp(current->s, index->s) > 0) {
        stmp = current->s;
        ctmp = current->c;
        jtmp = current->j;
        current->s = index->s;
        current->c = index->c;
        current->j = index->j;
        index->s = stmp;
        index->c = ctmp;
        index->j = jtmp;
    }
    return current;
}

inf_t *rearrange_value_by_name(inf_t *v)
{
    inf_t *current;
    char *stmp;
    char ctmp;
    int jtmp;

    for (inf_t *current = v; current != NULL; current = current->next){
        for (inf_t *index = current->next;index != NULL; index = index->next){
            apply_condition_rearrange_by_name
                (current, index);
        }
    }
    return (current);
}
