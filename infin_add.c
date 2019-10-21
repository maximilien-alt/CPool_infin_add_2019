/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *complete_str(char const *str, char const str2, char *dest, int letter)
{
    int res = (my_strlen(str) - letter);
    int res2 = (my_strlen(str2) - letter);

    if (letter == my_strlen(str)) {
        while (res2 > 0) {
            dest[letter] = str2[res2];
            letter += 1;
            res2 += -1;
        }
    } else {
        while (res > 0) {
            dest[letter] = str[res];
            letter += 1;
            res += -1;
        }
    }
    my_revstr(dest);
    return (dest);
}

char    *my_calc(char const *str, char const *str2, char *dest, int len)
{
    int letter = 0;
    char c = ((str[len] + str2[len]) - 96);

    while (len > 0) {
        if (c > 10) {
            dest[letter] = (c % 10 + '0');
            len += -1;
            letter += 1;
            str[len - 1] += 1;

        } else {
            dest[letter] = c;
            len += -1;
            letter += 1;
        }
    }
    return (complete_str(str, str2, dest, letter));
}

char    *my_infin_add(char *str, char *str2)
{
    int len1 = (my_strlen(str) + 2);
    int len2 = (my_strlen(str2) + 2);
    char dest[];

    if (len1 > len2) {
        dest = malloc(sizeof(char) * len1);
        dest[len1] = '\0';
        my_calc(str, str2, dest, len2);
        return (dest);
    } else {
        dest = malloc(sizeof(char) * len2);
        dest[len2] = '\0';
        my_calc(str, str2, dest, len1);
        return (dest);
    }
}

int    main(int argc, char *argv[])
{
    int num = my_str_isnum(argv[1]);
    int num2 = my_str_isnum(argv[2]);

    if (argc < 2 || argc > 3) {
        write(2, "please, 2 arguments\n", 20);
        return (0);
    }
    if (num == 0 || num2 == 0) {
        write (2, "please, only numbers\n", 21);
        return (0);
    }
    my_infin_add(argv[1], argv[2]);
    return (0);
}