/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** create my_putnbr
*/

#include "JIGSIG.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb < 10)
        my_putchar(nb + 48);
    else if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
}
