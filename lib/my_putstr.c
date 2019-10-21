/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** create my_putstr
*/

#include "JIGSIG.h"

void my_putstr(char const *str)
{
    if (str == NULL) {
        write(1, "", 1);
        return;
    } while (*str) {
        my_putchar(*str);
        str++;
    }
}
