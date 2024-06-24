/*
** EPITECH PROJECT, 2022
** write
** File description:
** write sys info
*/

#include "../include/nm.h"

char get_symbole_part4(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('b');
        return ('B');
    }
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == SHF_ALLOC || sym.st_shndx == 4){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('r');
        return ('R');
    }else
        get_symbole_part5(sym,shdr);
}

char get_symbole_part3(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (sym.st_shndx == SHN_ABS){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('a');
        return ('A');
    }
    if (sym.st_shndx == SHN_COMMON){
        if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL)
            return ('c');
        return ('C');
    }else
        get_symbole_part4(sym,shdr);
}

char get_symbole_part2(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
        && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT){
        if (sym.st_shndx == SHN_UNDEF)
            return ('v');
        return ('V');
    }
    if (sym.st_shndx == SHN_UNDEF)
        return ('U');
    else
        get_symbole_part3(sym,shdr);
}

char get_symbole_part1(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        return ('u');
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK){
        if (sym.st_shndx == SHN_UNDEF)
            return ('w');
        return ('W');
    }else
        get_symbole_part2(sym,shdr);
}
