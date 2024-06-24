/*
** EPITECH PROJECT, 2022
** main
** File description:
** mian
*/

#include "./include/nm.h"

void get_info(void *buf, char *av)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr *) buf;
    Elf64_Shdr *sys = (Elf64_Shdr *)((char *)buf + elf->e_shoff);
    Elf64_Sym *sym = NULL;

    for (int i = 0; i < elf->e_shnum; i++)
        if (sys[i].sh_type == SHT_SYMTAB) {
            sym = (Elf64_Sym *)((char *)buf + sys[i].sh_offset);
            break;
        }
    if (sym == NULL){
        printf("%s no symbols\n",av);
        return;
    }
    explore_sysinfo(buf,elf,sys,sym);
}

int proceed_single(char *b)
{
    int fd;
    void *buf;
    struct stat s;

    fd = open(b, O_RDONLY);
    if (fd == -1)
        return (84);
    if (fstat(fd, &s) < 0)
        return (84);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == -1)
        return (84);
    get_info(buf, b);
    close(fd);
    return (0);
}

int proceed_loop(char *b)
{
    if (testfile(b) == 84)
        return (84);
    printf("\n%s:\n", b);
    if (proceed_single(b) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    char *b;
    int end = 0;

    if (ac == 2)
        b = av[1];
    if (ac == 1)
        b = "a.out";
    if (ac < 3){
        if (testfile(b) == 84)
            return (84);
        return (proceed_single(b));
    }else
        for (int i = 1; i != ac; i++){
            b = av[i];
            if (proceed_loop(b) == 84)
                end = 84;
        }
    return (end);
}
