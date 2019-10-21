/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add_2.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *my_calc_str(char *str, char *cpy, char *result, int letter)
{
    int str_len = my_strlen(str) - 1;

    while (str_len > 0) {
        if ((str[str_len] + cpy[str_len] - '0') <= '9') {
            result[letter] = str[str_len] + cpy[str_len] - '0';
        } else {
            result[letter] = (str[str_len] + cpy[str_len] - '0') - 10;
            str[str_len - 1] += 1;
        }
        letter += 1;
        str_len += -1;
    }
    if ((str[str_len] + cpy[str_len] - '0') > '9') {
        result[letter] = (str[str_len] + cpy[str_len] - '0') - 10;
        result[letter + 1] = '1';
        result[letter + 2] = '\0';
    } else {
        result[letter] = str[str_len] + cpy[str_len] - '0';
        result[letter + 1] = '\0';
    }
    return (my_revstr(result));
}

char    *create_my_cpy(char *str, char *cpy, char *result, char *str2)
{
    int letter = 0;

    while (str[letter]) {
        cpy[letter] = str[letter];
        letter += 1;
    }
    while (str2[letter]) {
        cpy[letter] = '0';
        letter += 1;
    }
    cpy[letter] = '\0';
    my_revstr(cpy);
    return (my_calc_str(str2, cpy, result, 0));
}

char    *my_infin_add(char *str, char *str2)
{
    int str_len = my_strlen(str);
    int str_len2 = my_strlen(str2);
    char *result;
    char *cpy;

    if (str_len > str_len2) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        result = malloc(sizeof(char) * (str_len + 3));
        my_revstr(str2);
        cpy = create_my_cpy(str2, cpy, result, str);
        return (result);
    } else {
        cpy = malloc(sizeof(char) * (str_len2 + 1));
        result = malloc(sizeof(char) * (str_len2 + 3));
        my_revstr(str);
        cpy = create_my_cpy(str, cpy, result, str2);
        return (result);
    }
}

int    main(int argc, char *argv[])
{
    int av1_num = 0;
    int av2_num = 0;
    char *result;

    if (argc < 3 || argc > 3) {
        write (2, "please, 2 arguments\n", 20);
        return (0);
    }
    av1_num = my_str_isnum(argv[1]);
    av2_num = my_str_isnum(argv[2]);
    if (av1_num == 0 || av2_num == 0) {
        write (2, "please, only numbers\n", 21);
        return (0);
    }
    result = my_infin_add(argv[1], argv[2]);
    my_putstr(result);
    free(result);
    return (0);
}