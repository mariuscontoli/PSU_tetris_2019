/*
** EPITECH PROJECT, 2019
** print_ints
** File description:
** File that regroups functions to display integers
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_printf.h"

void print_char(va_list ap)
{
    char charac;
    charac = va_arg(ap, int);
    my_putchar(charac);
}

void print_str(va_list ap)
{
    char *str;
    str = va_arg(ap, char *);
    if (str != NULL){
        my_putstr(str);
    }
}

void print_sstr(va_list ap)
{
    char *str;
    str = va_arg(ap, char *);
    if (str != NULL) {
        my_putsstr(str);
    }
}