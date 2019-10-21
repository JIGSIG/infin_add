/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** create my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (len = 0; str[len] != 0; len++);
    return (len);
}
