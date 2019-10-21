/*
** EPITECH PROJECT, 2019
** int_array
** File description:
** int_array
*/

void    my_sort_int_array(int *tab, int size)
{
    int letter = 0;
    int cursor = 0;
    int res = 0;

    while (letter < size) {
        while (cursor < size) {
            if (tab[letter] > tab[cursor]) {
                res = tab[letter];
                tab[letter] = tab[cursor];
                tab[cursor] = res;
            }
            cursor += 1;
        }
        letter += 1;
    }
}