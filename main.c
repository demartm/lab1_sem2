#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/*
Формулировка задачи:
1. Даны два слова W1 и W2. Составляют ли они анаграмму (т.е. получаются ли друг из друга перестановкой букв)? Пример анаграммы: комар - корма.
*/

bool fill_tab(char *W1,int *Tab) {
    if (W1 && Tab) {
        for (int i = 0; W1[i] != '\0'; i++) {
            Tab[W1[i]] += 1;
        }
        return 1;
    }
    else {
        return 0;
    }

}

bool check_annogram(char *W1, char *W2, int *Tab) {

    if (W1 && W2 && Tab) {
        bool annogram = true;

        if (strlen(W1) != strlen(W2)) {
            return false;
        }

        for (int i = 0; W2[i] != '\0' && annogram; i++) {

            if (!Tab[W2[i]]) {
                annogram = false;
            }
            else {
                Tab[W2[i]] -= 1;
            }
        }
        return annogram;
    }
    else {
        return 0;
    }
}

int main()
{
    //char W1[] = "qwertyuiop";
    //char W2[] = "uiopqwerty"; //Вывод: annogram


    //char W1[] = "noannogram";
    //char W2[] = "annogram"; //Вывод: not an annogram

    //char W1[] = "randomtcxt";
    //char W2[] = "ardnmoettx"; //Вывод: not an annogram

    char W1[] = "randomtext";
    char W2[] = "ardnmoettx"; //Вывод: annogram

    int Tab[256] = { 0 };


    if (!fill_tab(W1, Tab)) {
        printf("Invalid pointer");
        return 0;
    }

    if (check_annogram(W1,W2,Tab)) {
        printf("annogram");
    }
    else {
        printf("not an annogram");
    }
    return 0;
}
