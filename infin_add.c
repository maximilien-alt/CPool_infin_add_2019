/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *complete_str(char *str, char *str2, char *dest, int cursor)
{
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);

    if (str_len > str2_len) {
        while (cursor > 0) {
        dest[cursor] = str[cursor];
        }
        cursor += -1;
    } else {
        while (cursor > 0) {
            dest[cursor] = str2[cursor];
        }
        cursor += -1;
    }
    return (dest);
}

char    *my_calc(char *str, char *str2, char *dest, int len)
{
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);

    while ((str_len >= 0) && (str2_len >= 0)) {
        if (((str[str_len] + str2[str2_len]) - 48) > '9') {
            dest[len] = (((str[str_len] + str2[str2_len]) - 48) % 10 + '0');
            if (str_len > str2_len) {
                str[str_len - 1] == (str[str_len - 1] + 1);
            } else {
                str2[str2_len - 1] == (str2[str2_len - 1] + 1);
            }
        } else {
            dest[len] = ((str[str_len] + str2[str2_len]) - 48);
        }
        len += -1;
        str_len += -1;
        str2_len += -1;
    }
    return (complete_str(str, str2, dest, len));
}

char    *my_infin_add(char *str, char *str2)
{
    char *dest;
    int str_len = my_strlen(str);
    int str2_len = my_strlen(str2);

    if (str_len > str2_len) {
        dest = malloc(sizeof(char) * (str_len + 2));
        dest[str_len + 2] = '\0';
        my_calc(str, str2, dest, (str_len + 1));
        return (dest);
    } else {
        dest = malloc(sizeof(char) * (str2_len + 2));
        dest[str2_len + 2] = '\0';
        my_calc(str, str2, dest, (str2_len + 1));
        return (dest);
    }
}

int    main(int argc, char *argv[])
{
    int num = 0;
    int num2 = 0;
    char *dest;

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
    dest = my_infin_add(argv[1], argv[2]);
    return (dest);
}