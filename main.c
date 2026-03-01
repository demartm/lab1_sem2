#include <stdio.h>
#include <stdbool.h>


/*
Формулировка задачи:
2. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
*/

bool fill_Tab(char *S2, bool *Tab) {

    if (S2 && Tab) {

        for (int i = 0; S2[i] != '\0'; i++) {
            Tab[S2[i]] = 1;
        }
        return 1;
    }
    else {
        return 0;
    }
}

bool delete_matches(char *S1, bool *Tab) {

    if (S1 && Tab) {
        int old = 0;

        for (int i = 0; S1[i] != '\0'; i++) {
            if (!Tab[S1[i]]) {
                S1[old] = S1[i];
                old++;
            }

        }
        S1[old] = '\0';
        return 1;
    }
    else {
        return 0;
    }
}


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
    bool Tab[256] = { 0 };

    printf("%s\n", S1);

    if (!fill_Tab(S2, Tab)) {
        printf("Invalid pointer");
        return 0;
    }
    if (!delete_matches(S1, Tab)) {
        printf("Invalid pointer");
        return 0;
    }

    printf("%s\n", S1);
}
