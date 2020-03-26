/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/tetris.h"

head_t *get_n_node(char *x, head_t *l_a)
{
    node_t *n_node = malloc(sizeof(node_t) + 1);
    if (n_node == 0)
        return NULL;
    n_node->data = x;
    n_node->prev = NULL;
    n_node->next = NULL;
    if (l_a == 0) {
        l_a = malloc(sizeof(head_t) + 1);
        if (l_a == 0)
            return NULL;
        l_a->begin = n_node;
        l_a->end = n_node;
        l_a->f_op = 0;
    }
    else {
        l_a->end->next = n_node;
        n_node->prev = l_a->end;
        l_a->end = n_node;
    }
    return l_a;
}