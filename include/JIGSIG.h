/*
** EPITECH PROJECT, 2019
** JIGSIG.h
** File description:
** create JIGSIG.h
*/

#ifndef JIGSIG_H
#define JIGSIG_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct jigsig_t jigsig_t;
struct jigsig_t
{
    char *A;
    char op;
    char *B;
    char sign;
    int lenA;
    int lenB;
    int reste;
};

void my_putchar(char);
void my_putstr(char const *);
void my_putnbr(int);
int my_strlen(char const *);
int my_strcmp(char const *, char const *);
char *my_strstr(const char *haystack, const char *needle);
int my_strncmp(char const *S_one, char const *S_two, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char const *src1, char const *src2);
int my_getnbr(char const *str);
bool my_str_isnum(char *s);
jigsig_t init_sig(char *A, char *B);
char *infin_add(char *A, char *B);
char *do_add(jigsig_t sig);

#endif
