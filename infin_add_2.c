/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add_2.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *my_cpy_neg(char *str, char *cpy, int str_neg, int letter)
{
    while (str[str_neg]) {
        cpy[letter] = str[str_neg];
        letter += 1;
        str_neg += 1;
    }
    return (cpy);
}

char   *my_transform_neg(char *str)
{
    int str_len = my_strlen(str);
    int str_neg = 0;
    int letter = 0;
    char *cpy;

    while (str[letter] == '-') {
        str_neg += 1;
        letter += 1;
    }
    letter = 0;
    str_len = str_len - str_neg;
    if (str_neg % 2 == 0) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        cpy[str_len] = '\0';
    } else {
        cpy = malloc(sizeof(char) * (str_len + 2));
        cpy[str_len + 1] = '\0';
        cpy[letter] = '-';
        letter += 1;
    }
    return (my_cpy_neg(str, cpy, str_neg, letter));
}

char    *my_calc_str_neg(char *str, char *cpy, char *result, int letter)
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

char    *create_my_cpy_neg(char *str, char *cpy, char *result, char *str2)
{
    int letter = 0;
    int neg = 0;

    while (str[letter] &&  str[letter] != '-') {
        cpy[letter] = str[letter];
        letter += 1;
    }
    if (str[letter] == '-') {
        cpy[letter] = '0';
        letter += 1;
    }
    while (str2[letter]) {
        cpy[letter] = '0';
        letter += 1;
    }
    cpy[letter] = '\0';
    my_revstr(cpy);
    return (my_calc_str_neg(str2, cpy, result, 0));
}

char    *my_infin_add_neg(char *str, char *str2)
{
    int str_len = my_strlen(my_transform_neg(str));
    int str_len2 = my_strlen(my_transform_neg(str2));
    char *result;
    char *cpy;

    if (str_len > str_len2) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        result = malloc(sizeof(char) * (str_len + 3));
        str = my_transform_neg(str);
        str2 = my_transform_neg(str2);
        my_revstr(str2);
        cpy = create_my_cpy_neg(str2, cpy, result, str);
        return (result);
    } else {
        cpy = malloc(sizeof(char) * (str_len2 + 1));
        result = malloc(sizeof(char) * (str_len2 + 3));
        str2 = my_transform_neg(str2);
        str = my_transform_neg(str);
        my_revstr(str);
        cpy = create_my_cpy_neg(str, cpy, result, str2);
        return (result);
    }
}