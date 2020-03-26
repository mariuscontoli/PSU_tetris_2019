/*
** EPITECH PROJECT, 2019
** utility functions file
** File description:
** regroup used functions for this project
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        ++i;
    }
}

void my_putsstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            my_put_nbr_oct(str[i]);
            i += 1;
        } else {
            my_putchar(str[i]);
            i += 1;
        }
    }
}

void my_put_nbr_bin(unsigned int nb)
{
    int modulo;

    if (nb > 0) {
        modulo = (nb % 2);
        nb = (nb - modulo) / 2;
        my_put_nbr_bin(nb);
        if (modulo <= 10)
            my_putchar(48 + modulo);
        else
            my_putchar(49 + modulo);
    }
}