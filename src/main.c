/*
** EPITECH PROJECT, 2019
** bistromatic
** File description:
** main
*/

#include "JIGSIG.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_str_isnum(av[1]) == false || my_str_isnum(av[2]) == false)
        return (84);
    infin_add(av[1], av[2]);
    return (0);
}
