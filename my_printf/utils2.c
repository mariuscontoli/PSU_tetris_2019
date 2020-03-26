/*
** EPITECH PROJECT, 2019
** utility functions file
** File description:
** regroup used functions for this project
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my_printf.h"

void my_put_nbr(int nb)
{
    int modulo;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            modulo = (nb % 10);
            nb = (nb - modulo) / 10;
            my_put_nbr(nb);
            my_putchar(48 + modulo);
        }
        else
            my_putchar(48 + nb % 10);
    }
}

void my_put_nbr_hex(int nb)
{
    int modulo;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 0) {
        modulo = (nb % 16);
        nb = (nb - modulo) / 16;
        my_put_nbr_hex(nb);
        if (modulo <= 9)
            my_putchar(48 + modulo);
        else
            my_putchar(87 + modulo);
    }
}

void my_put_nbr_hexx(int nb)
{
    int modulo;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 0) {
        modulo = (nb % 16);
        nb = (nb - modulo) / 16;
        my_put_nbr_hex(nb);
        if (modulo <= 9)
            my_putchar(48 + modulo);
        else
            my_putchar(55 + modulo);
    }
}

void my_put_nbr_oct(int nb)
{
    int modulo;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 0) {
        modulo = (nb % 8);
        nb = (nb - modulo) / 8;
        my_put_nbr_oct(nb);
        if (modulo <= 9)
            my_putchar(48 + modulo);
        else
            my_putchar(87 + modulo);
    }
}

void my_put_nbr_uns(unsigned int nb)
{
    int modulo;

    if (nb >= 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        my_put_nbr_uns(nb);
        my_putchar(48 + modulo);
    } else {
        my_putchar(48 + nb % 10);
    }
}