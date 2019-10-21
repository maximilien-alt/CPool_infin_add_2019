/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *calc_str(char *str, char *str2, char *cpy, char *result)
{
    int len = (my_strlen(str) - 1);
    int letter = 0;

    while (len >= 0) {
        if ((str[len] + cpy[len] - '0') > '9') {
            result[letter] = (((str[len] + cpy[len]) - '0') - 10);
            if (len > 0) {
            str[len - 1] += 1;
            } else {
                result[letter + 1] = '1';
                result[letter + 2] = '\0';
                my_revstr(result);
                return (result);
            }
        } else {
        result[letter] = str[len] + cpy[len] - '0';
        }
        letter += 1;
        len += -1;
    }
    result[letter] = '\0';
    my_revstr(result);
    return (result);
}

char    *create_my_cpy(char *str, char *str2, char *cpy, char *result)
{
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);
    int letter = 0;

    if (str_len > str2_len) {
        while (str2[letter]) {
            cpy[letter] = str2[letter];
            letter += 1;
        }
        while (str[letter]) {
            cpy[letter] = '0';
            letter += 1;
        }
        cpy[letter] = '\0';
        my_revstr(cpy);
        return (calc_str(str, str2, cpy, result));
    } else {
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
        return (calc_str(str2, str, cpy, result));
    }
}

char    *my_infin_add(char *str, char *str2)
{
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);
    char *cpy;
    char *result;

    if (str_len > str2_len) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        result = malloc(sizeof(char) * (str_len + 3));
        my_revstr(str2);
        cpy = create_my_cpy(str, str2, cpy, result);
        return (result);
    } else {
        cpy = malloc(sizeof(char) * (str2_len + 1));
        result = malloc(sizeof(char) * (str2_len + 3));
        my_revstr(str);
        cpy = create_my_cpy(str, str2, cpy, result);
        return (result);
    }
}

int    main(int argc, char *argv[])
{
    int num = 0;
    int num2 = 0;
    char *result;

    if (argc < 3 || argc > 3) {
        write(2, "please, 2 arguments\n", 20);
        return (0);
    }
    num = my_str_isnum(argv[1]);
    num2 = my_str_isnum(argv[2]);
    if (num == 0 || num2 == 0) {
        write (2, "please, only numbers\n", 21);
        return (0);
    }
    result = my_infin_add(argv[1], argv[2]);
    my_putstr(result);
    free (result);
    return (0);
}