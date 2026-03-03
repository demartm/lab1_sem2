#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>


/*
Формулировка задачи:
1. Даны два слова W1 и W2. Составляют ли они анаграмму (т.е. получаются ли друг из друга перестановкой букв)? Пример анаграммы: комар - корма.
*/

bool check_annogram(char* W1, char* W2) {

    if (W1 && W2) {
        int Tab[256] = { 0 };

        for (int i = 0; W1[i] != '\0'; i++) {
            Tab[(unsigned char)W1[i]] += 1;
        }


        bool annogram = true;

        if (strlen(W1) != strlen(W2)) {
            return false;
        }

        for (int i = 0; W2[i] != '\0' && annogram; i++) {

            if (!Tab[(unsigned char)W2[i]]) {
                annogram = false;
            }
            else {
                Tab[(unsigned char)W2[i]] -= 1;
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
    //Насколько я понял, кириллические символы нормально определяются благодаря устройству Unicode, который не оставляет вариантов для коллизий байтовых значений разных символов

    //char W1[] = "qwertyuiop";
    //char W2[] = "uiopqwerty"; //Вывод: annogram


    //char W1[] = "noannogram";
    //char W2[] = "annogram"; //Вывод: not an annogram

    //char W1[] = "randomtcxt";
    // char W2[] = "ardnmoettx"; //Вывод: not an annogram

    //char W1[] = "listen";
    //char W2[] = "silent"; //Вывод: annogram

    char W1[] = "abcабв";
    char W2[] = "абвabc"; //Вывод: annogram

    //char W1[] = "проверка";
    //char W2[] = "рпвореак"; //Вывод: annogram

    //char W1[] = "комар";
    //char W2[] = "корма"; //Вывод: annogram

    //char W1[] = "тест";
    //char W2[] = "тесто"; //Вывод: not an annogram

    //char W1[] = "весна";
    //char W2[] = "навес"; //Вывод: annogram


    //char W1[] = "aab";        // Латинские
    //char W2[] = "ааb";        // Кириллические а + латинская b //Вывод: not an annogram

    //char W1[] = "google";     // Латинские символы
    //char W2[] = "gооgle";     // С кириллическими о //Вывод: not an annogram

    //char W1[] = "a";          // Латинская a
    //char W2[] = "а";          // Кириллическая а //Вывод: not an annogram

     //char W1[] = "ÀÿАп";
     //char W2[] = "ÀÀпп"; //Вывод: not an annogram

    //W1: C3=2, 80=1, BF=2, D0=2, 90=1
    //W2: C3 = 2, 80 = 2, BF = 2, D0 = 2




    if (check_annogram(W1, W2)) {
        printf("annogram");
    }
    else {
        printf("not an annogram");
    }
    return 0;
}
