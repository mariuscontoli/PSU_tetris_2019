/*
** EPITECH PROJECT, 2019
** header
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_putstr(char const *str);
void my_putsstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
void print_str(va_list ap);
void print_sstr(va_list ap);
void print_char(va_list ap);
void print_nbr(va_list ap);
void print_nbr_hex(va_list ap);
void print_nbr_hexx(va_list ap);
void print_nbr_oct(va_list ap);
void print_uns_nbr(va_list ap);
void print_nbr_bin(va_list ap);
void my_put_nbr_uns(unsigned int nb);
void my_put_nbr_bin(unsigned int nb);
void my_put_nbr_oct(int nb);
void my_put_nbr_hex(int nb);
void my_put_nbr_hexx(int nb);
void my_printf(char *s, ...);
void is_flag(char *s, int temp, va_list ap);
void no_flag(char *s, int i, int temp);

typedef struct PTR {
    char flag;
    void (*ptr)(va_list ap);
} PTR;

#endif