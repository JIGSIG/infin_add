/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** engine
*/

#include "JIGSIG.h"

static void init_result(char **result, jigsig_t sig)
{
    (*result) = malloc(sizeof(char) * (sig.lenA + 2));
    if (!(*result))
        return;
    for (int i = 0; i <= (sig.lenA); i++)
        (*result)[i] = '0';
    for (int i = 0; i < sig.lenA; i++)
        (*result)[i + 1] = sig.A[i];
    (*result)[sig.lenA + 1] = 0;
}

static void my_addition(jigsig_t sig, char **result)
{
    for (int i = (sig.lenB - 1), k = sig.lenA; i >= 0; i--, k--) {
        (*result)[k] += sig.B[i] - 48;
        while ((*result)[k] > 57) {
            (*result)[k] -= 10;
            sig.reste++;
        } (*result)[k - 1] += sig.reste;
        sig.reste = 0;
    }
}

static void my_soustraction(jigsig_t sig, char **result)
{
    for (int i = (sig.lenB - 1), k = sig.lenA; i >= 0; i--, k--) {
        if ((*result)[k] < sig.B[i]) {
            (*result)[k] = (*result)[k] + 10 - sig.B[i] + 48;
            (*result)[k - 1] -= 1;
            for (int n = 1; n <= k; n++)
                if ((*result)[k - n] < 48) {
                    (*result)[k - n] = '9';
                    (*result)[k - (n + 1)] -= 1;
                }
        } else {
            (*result)[k] = (*result)[k] - sig.B[i] + 48;
            while ((*result)[k] > 57) {
                (*result)[k] -= 10;
                sig.reste++;
            } (*result)[k - 1] += sig.reste;
            sig.reste = 0;
        }
    }
}

char *do_add(jigsig_t sig)
{
    char *result = NULL;

    sig.lenB = strlen(sig.B);
    sig.lenA = strlen(sig.A);
    init_result(&result, sig);
    if (sig.op == '+')
        my_addition(sig, &result);
    else
        my_soustraction(sig, &result);
    while (*result == '0')
        result++;
    if (*result == 0)
        result--;
    return (result);
}
