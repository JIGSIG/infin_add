/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** main
*/

#include "JIGSIG.h"

bool my_str_isnum(char *s)
{
    while (*s == '-' || *s == '+')
        s++;
    while (*s) {
        if (*s < '0' || *s > '9')
            return (false);
        s++;
    } return (true);
}
