#include <stdio.h>
#include <stdbool.h>


/*
Формулировка задачи:
2. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
*/

int main()
{
        //char S1[] = "nothingspc"; //Вывод: ningspc
        //char S2[] = "oth";

        //char S1[] = "somerandom"; //Вывод: smandm
        //char S2[] = "qwertyuiop";

        //char S1[] = "randomtext"; //Вывод: random
        //char S2[] = "text";

        char S1[] = "randomtext"; //Вывод: text
        char S2[] = "random";
        bool exist[256] = { 0 };

        printf("%s\n", S1);

        for (int i = 0; S2[i] != '\0'; i++) {
                exist[S2[i]] = 1;
        }

        int old = 0;

        for (int i = 0; S1[i] != '\0'; i++) {
                if (!exist[S1[i]]) {
                        S1[old] = S1[i];
                old++;
                }

        }
        S1[old] = '\0';
        printf("%s\n", S1);
}
