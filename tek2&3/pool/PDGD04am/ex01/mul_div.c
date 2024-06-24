/*
** EPITECH PROJECT, 2022
** mul
** File description:
** div
*/

void mul_div_long (int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int tmp  = *a * *b;
    if (*b == 0)
        *b = 42;
    else
        *b = *a / *b;
    *a = tmp;
}
