/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** main
*/

#include "JIGSIG.h"

static char get_final_sign(char *A, char *B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    if ((*A == '-' && *B != '-') && lenA < lenB)
        return ('-');
    if ((*A == '-' && *B != '-') && lenA > lenB)
        return ('-');
    if ((*A == '-' && *B == '-'))
        return ('-');
    if ((*A != '-' && *B == '-') && lenA > lenB)
        return ('-');
    if ((*A != '-' && *B == '-') && lenA > lenB)
        return ('+');
    if ((*A != '-' && *B == '-') && lenA < lenB)
        return ('-');
    return ('+');
}

static char get_op(char *A, char *B)
{
    char op = '+';

    if ((*A == '-' && *B == '-') || (*A != '-' && *B != '-'))
        op = '+';
    if ((*A == '-' && *B != '-') || (*A != '-' && *B == '-'))
        op = '-';
    return (op);
}

int count_sign(char *s)
{
    int count = 0;

    while (*s == '-' || *s == '+') {
        count++;
        s++;
    } return (count);
}

static char *remove_sign(char *s)
{
    char *new = NULL;
    int i = 0;

    new = malloc(sizeof(*s) * (strlen(s) + 1));
    if (!new)
        return (NULL);
    while (*s == '-' || *s == '+')
        s++;
    while (*s) {
        new[i] = *s;
        i++;
        s++;
    } return (new);
}

jigsig_t init_sig(char *A, char *B)
{
    jigsig_t new = {NULL, '+', NULL, '+', 0, 0, 0};
    int lenA = strlen(A) - count_sign(A);
    int lenB = strlen(B) - count_sign(B);

    new.op = get_op(A, B);
    new.sign = get_final_sign(A, B);
    if (lenA >= lenB) {
        new.A = remove_sign(A);
        new.B = remove_sign(B);
    } else {
        new.A = remove_sign(B);
        new.B = remove_sign(A);
    } return (new);
}
