/*
** EPITECH PROJECT, 2022
** write ifo
** File description:
** 2
*/

#include "../include/nm.h"

char get_symbole_part6(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('d');
        return ('D');
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
        return ('d');
    return ('D');
}

char get_symbole_part5(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('d');
        return ('D');
    }
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('t');
        return ('T');
    }else
        get_symbole_part6(sym,shdr);
}
