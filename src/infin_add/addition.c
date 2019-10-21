/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** main
*/

#include "JIGSIG.h"

char *infin_add(char *A, char *B)
{
    char *result = NULL;
    jigsig_t sig = {NULL, '+', NULL, '+', 0, 0, 0};

    sig = init_sig(A, B);
    result = do_add(sig);
    if (sig.sign == '+')
        printf("%s\n", result);
    else
        printf("-%s\n", result);
    return (result);
}
