#include <stdio.h>
#include <stdbool.h>

#define word_size 11

/*
Формулировка задачи:
1. Даны два слова W1 и W2. Составляют ли они анаграмму (т.е. получаются ли друг из друга перестановкой букв)? Пример анаграммы: комар - корма.
*/

int main()
{
        //char W1[] = "qwertyuiop";
        //char W2[] = "uiopqwerty"; //Вывод: annogram


        //char W1[] = "noannogram";
        //char W2[] = "annogram"; //Вывод: not an annogram

        char W1[] = "randomtext";
        char W2[] = "ardnmoettx"; //Вывод: annogram

        int exist[256] = { 0 };
        bool annogram = true;

        int length = 0;



        for (length = 0; W1[length] != '\0'; length++) {
                exist[W1[length]] += 1;
        }
        int i = 0;

        for (i = 0; W2[i] != '\0' && annogram; i++) {

                if (!exist[W2[i]]) {
                        annogram = false;
                }
                else {
                        exist[W2[i]] -= 1;
                }
        }

        if (annogram && length == i) {
                printf("annogram");
        }
        else {
                printf("not an annogram");
        }
        return 0;
}
