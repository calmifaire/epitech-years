/*
** EPITECH PROJECT, 2022
** explore sys
** File description:
** explore info in sys
*/

#include "../include/nm.h"

void explore_sysinfo(void *buf,Elf64_Ehdr *elf,Elf64_Shdr *sys,Elf64_Sym *sym)
{
    Elf64_Shdr *symtab;
    Elf64_Shdr *strtab;
    char *str = (char *)(buf + sys[elf->e_shstrndx].sh_offset);

    for (int i = 0; i < elf->e_shnum; i++){
        if (strcmp(&str[sys[i].sh_name], ".symtab") == 0)
            symtab = (Elf64_Shdr *) &sys[i];
        if (strcmp(&str[sys[i].sh_name], ".strtab") == 0)
            strtab = (Elf64_Shdr *) &sys[i];
    }
    str = (char*)(buf + strtab->sh_offset);
    storing_value(str,symtab, sym, sys);
}
